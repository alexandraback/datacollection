#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    //freopen("Brattleship.txt","r",stdin);
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    int T,R,C,W,i,j,ans,K;
    int A[10][10]={{1},{2,2},{3,3,3},{4,3,4,4},{5,4,4,5,5},{6,4,4,5,6,6},{7,5,5,5,6,7,7},{8,5,5,5,6,7,8,8},{9,6,5,6,6,7,8,9,9},{10,6,6,6,6,7,8,9,10,10}};
    scanf("%d",&T);
    for(K=1;K<=T;K++) {
        scanf("%d%d%d",&R,&C,&W);
        printf("Case #%d: %d\n",K,A[C-1][W-1]);
    }
    return 0;
}
