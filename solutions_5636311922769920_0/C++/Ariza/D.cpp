#include <cstdio>
#include <iostream>
using namespace std;
#define LL long long
int K,C,S;
LL recur(int idx,LL prev,int depth) {
    if (depth==C) return prev*K+idx;
    if (idx<K)
        return recur(idx+1, prev*K+(idx-1), depth+1);
    else
        return recur(idx, prev*K+(idx-1), depth+1);
}
void solve(){
    printf(" ");
    scanf("%d %d %d",&K,&C,&S);
    
    int need = (K/C)+(K%C>0);
    if (need>S) printf("IMPOSSIBLE\n");
    else{
        for (int i=0;i<need;++i){
            printf("%lld%c",recur(i*C+1, 0, 1),i<need-1?' ':'\n');
        }
    }
}

int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
