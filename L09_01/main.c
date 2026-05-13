#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char str[100];
    struct node *left;
    struct node *right;
} Node;

void preorder (Node *root);
void inorder (Node *root);
void postorder (Node *root);
void delete (Node *root);

int main() {
    //root
    Node *root = (Node *)calloc(1, sizeof(Node));
    strcpy(root->str, "A");

    root->left = (Node *)calloc(1, sizeof(Node));
    strcpy(root->left->str, "B");

    root->right = (Node *)calloc(1, sizeof(Node));
    strcpy(root->right->str, "C");

    root->left->left = (Node *)calloc(1, sizeof(Node));
    strcpy(root->left->left->str, "D");

    root->left->right = (Node *)calloc(1, sizeof(Node));
    strcpy(root->left->right->str, "E");

    root->left->left->left = (Node *)calloc(1, sizeof(Node));
    strcpy(root->left->left->left->str, "G");

    root->left->right->right = (Node *)calloc(1, sizeof(Node));
    strcpy(root->left->right->right->str, "H");

    root->left->right->right->left = (Node *)calloc(1, sizeof(Node));
    strcpy(root->left->right->right->left->str, "J");

    root->right->right = (Node *)calloc(1, sizeof(Node));
    strcpy(root->right->right->str, "F");

    root->right->right->left = (Node *)calloc(1, sizeof(Node));
    strcpy(root->right->right->left->str, "I");

    printf("Preorder:\n");
    preorder(root);
    printf("\nInorder:\n");
    inorder(root);
    printf("\nPostorder:\n");
    postorder(root);

    delete(root);
    return 0;
}

//preorder (root, left, right)
void preorder(Node *root) {
    if (root == NULL) return;
    printf("%s", root->str);
    preorder(root->left);
    preorder(root->right);
}

//inorder (left, root, right)
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%s", root->str);
    inorder(root->right);
}

//postorder (left, right, root)
void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%s", root->str);
}

void delete(Node *root) {
    if (root == NULL) return;
    delete(root->left);
    delete(root->right);
    free(root);
}