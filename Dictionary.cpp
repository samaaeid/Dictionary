#include <bits/stdc++.h>
using namespace std;

// A binary search tree node
struct node {
	string data;
	node* left;
	node* right;
};

// Initialize a global pointer for root
node* root;

// This function do inorder traversal of the binary search tree
void inOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of inorder traversal
	inOrder(curr->left);
	cout << curr->data << ' ';
	inOrder(curr->right);
}


// This function searches if the given data in the binary search tree
bool search(node* curr, string data) {
	// base case we reach a null node
	if (curr == NULL)
		return false;
	// check if we find the data at the curr node
	if (curr->data == data)
		return true;
	// repeat the same definition of search at left or right subtrees
    if (data < curr->data)
        return search(curr->left, data);
    else
        return search(curr->right, data);
}

// This function inserts a new node with given key in the binary search tree
node* insert_node(node* curr, string new_data) {
	// base case we reach a null node
    if (curr == NULL) {
		curr = new node();
		curr->data = new_data;
		return curr;
    }
	// repeat the same definition of insert at left or right subtrees
    if (new_data < curr->data)
		curr->left = insert_node(curr->left, new_data);
    else if (new_data > curr->data)
		curr->right = insert_node(curr->right, new_data);
	// return the unchanged node pointer
	return curr;
}

// This function returns the node with minimum value found in the given tree
node* min_node(node* curr) {
    node* res = curr;
    // loop down to find the leftmost leaf
    while (res->left != NULL)
        res = res->left;
	// return the nearest data node of curr data node
    return res;
}

// This function returns the node with maximum value found in the given tree
node* max_node(node* curr) {
    node* res = curr;
    // loop down to find the rightmost leaf
    while (res->right != NULL)
        res = res->right;
	// return the nearest data node of curr data node
    return res;
}

// This function deletes the given data in the binary search tree if exists
node* delete_node(node* curr, string data) {
	// base case we reach a null node
    if (curr == NULL)
    	return curr;
	// repeat the same definition of insert at left or right subtrees
    if (data < curr->data)
        curr->left = delete_node(curr->left, data);
    else if (data > curr->data)
        curr->right = delete_node(curr->right, data);
    // if the given data is same as curr's data, then we will delete this node
    else {
        // node with no child
        if (curr->left == NULL && curr->right == NULL) {
            delete(curr);
            return NULL;
        }
        // node with only one child
        else if (curr->left == NULL) {
            node* temp = curr->right;
            delete(curr);
            return temp;
        }
        // node with only one child
        else if (curr->right == NULL) {
            node* temp = curr->left;
            delete(curr);
            return temp;
        }
        // node with two children
        else {
            // get the inorder successor (smallest in the right subtree)
            node* temp = min_node(curr->right);
            // copy the inorder successor's content to this node
            curr->data = temp->data;
            // delete the inorder successor
            curr->right = delete_node(curr->right, temp->data);
        }
    }
	// return the unchanged node pointer
    return curr;
}

// This function traverses the binary search tree in postorder to delete all nodes
void delete_tree(node* curr) {
	// base case we reach a null node
	if (curr == NULL)
    	return;
	// repeat the same definition of postorder traversal
    delete_tree(curr->left);
    delete_tree(curr->right);
    delete(curr);
}
//----------------------------------------------------------------------------------------------------------------------------//

void search_word(){
cout<<"please enter the word you wanted to search about it : ";
string word;
cin>>word;
if(search(root,word)){
    cout<<"this world is founded"<<endl;
}
else{
        cout<<"this world is NOT found"<<endl;

}
}
void delete_word(){
cout<<"please enter the word you wanted to delete it from dictionary : ";
string word;
cin>>word;
delete_node(root,word);

}
void insert_node(){
cout<<"please enter the word you wanted to add it to dictionary : ";
string word;
cin>>word;
insert_node(root,word);

}




int main() {

	// Functionality Testing

    // first level of the binary search tree (root only)
	root = insert_node(root, "car");
    root = insert_node(root, "rappit");
	root = insert_node(root, "apple");
	root = insert_node(root, "banana");
	root = insert_node(root, "snake");
	root = insert_node(root, "cat");
	root = insert_node(root, "game");
	root = insert_node(root, "english");
	root = insert_node(root, "jac");


	while(1){
            cout<<"\n====Dictionary===="<<endl;

    cout<<"\nPlease choose what you want to do";

    cout<<"\n1.Search";
    cout<<"\n2.Delete";
    cout<<"\n3.insert"; // from num to num
    cout<<"\n4.View";  // num line + text

    cout<<"\n5.exit";


        cout<<"\n\nEnter your choice..";

        int choice;
        cin>>choice;
        switch(choice){
      case 1:
          search_word();
        break;
      case 2:
          delete_word();
        break;
      case 3:
          insert_node();
        break;
      case 4:
         inOrder(root);
         break;
      case 5:
        exit(0);

    }
}
}
