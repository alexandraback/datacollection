#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    // freopen("Brattleship.txt","r",stdin);
    freopen("Input.txt","r",stdin);
    freopen("Output2.txt","w",stdout);
    int T,R,C,W,i,j,ans,K,temp;
    scanf("%d",&T);
    for(K=1;K<=T;K++) {
        scanf("%d%d%d",&R,&C,&W);
        temp=(R-1)*(C/W);
        if(W==1) {
            ans=C;
        } else if(W==C) {
            ans=W;
        } else {
            ans=0;
            while(((C+1)/2)>W) {
                C-=W;
                ans++;
            }
            ans+=(W+1);
        }
        ans+=temp;
        printf("Case #%d: %d\n",K,ans);
    }
    return 0;
}
