#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define debug(x...) fprintf(stderr, x)

//Triple Linked List!
typedef struct Node { //Only complies under g++, not gcc?
    int value;
    int inPlay;
    Node* link;
    Node* next;
    Node* prev;
} Node;

Node* AList;//Get 1 Star
Node* BList;//Get 2 Star
int N;

void removeNode(Node* n)//Leaves the link pointer and the node alive
{
    if (n->prev)
        n->prev->next = n->next;
    else
        AList = n->next;
    if (n->next)
        n->next->prev= n->prev;
    n->inPlay = 0;
}

void unremoveNode(Node* n) //Assumes nothing else changed
{
    if (n->prev)
        n->prev->next = n;
    else
        AList = n;
    if (n->next)
        n->next->prev = n;
    n->inPlay = 1;
}

Node* insertNode(int blist, int value)//Insertion sort too!
{
    Node* ret = (Node*) malloc(sizeof(Node));
    ret->value = value;
    debug("Adding val %d to %X\n", value, ret);
    ret->link = 0;
    ret->inPlay = 1;

    Node* list = blist ? BList : AList;
    if (!list || list->value > value) { //Insert at head
        ret->prev = 0;
        ret->next = list;
        if (list)
            list->prev = ret;
        if (blist)
            BList = ret;
        else
            AList = ret;
        return ret;
    }
    //Insert in middle/tail
    while (list->next && list->next->value < value)
        list = list->next;
    ret->prev = list;
    if(list->next) {
        ret->next = list->next;
        ret->next->prev = ret;
    } else
        ret->next = 0;
    list->next = ret;
    return ret;
}

void cleanLists() //Cleans based off BList
{
    Node* cur = BList;
    while(cur) {
        free(cur->link);
        Node* prev = cur;
        cur = cur->next;
        free(prev);
    }
}

int interleavedResult() //-1 for invalid, otherwise length
{
    // PRE: Both lists are sorted
    int c = 0;
    int stars = 0;//Diverge once you get a two star directly
    Node *a = AList;
    Node *b = BList;
    debug("Starters: %X %X\n", a,b);
    // Must sort b before a for case of ai == bi (although you could special case it...)
    Node *cur;
    while (a || b) {
        if( a && (!b || a->value < b->value) ) {
            cur = a;
            a = a->next;
        } else {
            cur = b;
            b = b->next;
        }
        if (cur->value > stars){
            debug("Death at %d %X! %d, %d\n", cur->value, cur, c, stars);
            return -1;
        }
        c++;
        stars++;
        if (!cur->link->inPlay){
            stars++;
            debug("Yes I'm hit!\n");
        } else {
            debug("Nein! %d %X\n", cur->link->inPlay, cur);
        }
    }
    debug("%d\n",c);
    return c;
}

int solve()
{
    //Two sorted lists, remove as many as you can from AList while maintaining
    //valid interleaved order. Removal by BList order is theorized to be both
    //efficient and correct.
    int result = interleavedResult();
    if (result == -1) //Never possible
        return -1;
    Node* cur = BList;
    while(cur) {
        Node* candidate = cur->link;
        removeNode(candidate);
        debug("Dropping %X\n", candidate);
        int res2 = interleavedResult();
        assert(res2 == -1 || res2 == result - 1);
        if (res2 == -1)
            unremoveNode(candidate);
        else
            result = res2;
        cur = cur->next;
    }
    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: You're doing it wrong\n");
        return 1;
    }

    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    int T,t,i,j,k;
    fscanf(fin, "%d", &T);
    for (t=0; t<T; t++) {
        AList = 0;
        BList = 0;
        fscanf(fin, "%d", &N);
        for(i=0; i<N; i++){
            fscanf(fin, "%d %d", &j, &k);
            Node* a = insertNode(0, j);
            Node* b = insertNode(1, k);
            a->link = b;
            b->link = a;
        }
        int answer = solve();
        if (answer != -1)
            fprintf(fout, "Case #%d: %d\n", t+1, answer);
        else
            fprintf(fout, "Case #%d: Too Bad\n", t+1);
        cleanLists();
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
