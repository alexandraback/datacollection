#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 1200

int node[MAXN];
int arr[MAXN];
int linum;
struct linkline{
    int linode;
    int next;
}line[MAXN*MAXN*3];

void init (int n);
void insert (int s ,int e);
bool tjudge (int n);
bool dfs (int s ,int flag);

int main (){
    int t ,n ,m;
    int a;
    freopen ("in.in","r",stdin);
    freopen ("out.out","w",stdout);
    scanf ("%d",&t);
    for(int test=1 ;test<=t ;test++){
        scanf ("%d",&n);
        init (n);
        for (int i=1 ;i<=n ;i++){
            scanf ("%d",&m);
            for (int j=1 ;j<=m ;j++){
                scanf ("%d",&a);
                insert (i ,a);
            }
        }
        printf ("Case #%d: %s\n",test ,tjudge (n)?"Yes":"No");
    }
    return 0;
}
void init (int n){
    for (int i=0 ;i<=n ;i++){
        node[i] = -1;
        arr[i] = -1;
    }
    linum = 0;
    return ;
}
void insert (int s ,int e){
    line[++linum].next = node[s];
    line[linum].linode = e;
    node[s] = linum;
    return ;
}
bool tjudge (int n){
    for (int i=1 ;i<=n ;i++){
        if (arr[i] == -1){
            //printf ("%d->",i);
            if (dfs (i ,i))
                return true;
            //printf ("\n");
        }
    }
    return false;
}
bool dfs (int s ,int flag){
    int temp;
    arr[s] = flag;
    //printf ("->%d\n",s);
    for (int i=node[s] ;i!=-1 ;i=line[i].next){
        temp = line[i].linode;
        if (arr[temp] == flag)
            return true;
        if (dfs (temp ,flag))
            return true;
    }
    return false;
}