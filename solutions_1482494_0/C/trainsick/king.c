
#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

typedef struct node {
    struct node *next[2];
    int a[2];
    int used;
    int skip;
} node;

int N;

int pass;
node *todo;
node *data;

void readit(void) {
    int i;
    scanf("%d",&N);
    data=calloc(N,sizeof(node));
    for (i=0;i<N;i++) {
        scanf("%d %d",data[i].a+0,data[i].a+1);
    }
}

node *merge(node *a, node *b) {
    node c0,*c=&c0;
    int cmp;
    while (a && b) {
        cmp=a->a[pass] - b->a[pass];
        if (!cmp) cmp=a->a[1] - b->a[1];
        if (cmp<=0) {
            c=c->next[pass]=a;a=a->next[pass];
        } else {
            c=c->next[pass]=b;b=b->next[pass];
        }
    }
    c->next[pass]=a?a:b;
    return c0.next[pass];
}

node *sort(int n) {
    node *a;
    if (n==0) return NULL;
    if (n==1) {
        a=todo++;
        a->next[pass]=NULL;
        a->used=0;
        return a;
    }
    a=sort(n/2);
    return merge(a,sort(n-n/2));
}

int levused(void) {
    node *list1,*list0;
    int lev=0,stars=0;
    todo=data;
    pass=0;
    list0=sort(N);
    todo=data;
    pass=1;
    list1=sort(N);
    while (list1) {
        if (stars >= list1->a[1]) {
            stars+=2-list1->used;
            lev+=1;
            list1->skip=1;
            list1=list1->next[1];
        } else if (list0 && list0->skip) {
            list0=list0->next[0];
        } else if (list0 && stars>=list0->a[0]) {
            stars++;
            lev++;
            list0->used=1;
            list0=list0->next[0];
        } else {
            //printf("Too Bad\n");
            //break;
            return INF;
        }
    }
    
    return lev;
}


void kingdom(void) {
    int b,bmin=-1,lmin=INF,l;
    int i;
    readit();
    for (b=0;b<(1<<N);b++) {
        for (i=0;i<N;i++) data[i].skip=(b>>i) & 1;
        l=levused();
        if (l<lmin) {lmin=l;bmin=b;}
    }
    
    //printf("(%d)",bmin);
    if (lmin<INF) printf("%d\n",lmin);
    else printf("Too Bad\n");
    free(data);
}

int main(void) {
    int TC,i;
    scanf("%d",&TC);
    for (i=1;i<=TC;i++) {
        printf("Case #%d: ",i);
        kingdom();
    }
    return 0;
}
