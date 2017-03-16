#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using std::min;
using std::max;
int dp[20][20];
int ss[10];
int hash[1024];
int s[10];
int R, N, M, K;

bool dfs(int k){
    if(k==N){
        for(int i=0;i<(1<<N);++i){
            int v=1;
            for(int j=0;j<N;++j){
                if(i&(1<<j))
                    v*=s[j];
            }
            hash[v]=1;
        }
        for(int i=0;i<K;++i)
            if(hash[ss[i]]==0)return false;
        for(int i=0;i<N;++i)
            printf("%d",s[i]);
        printf("\n");
        return true;
    }else{
        for(int i=2;i<=M;++i){
            s[k]=i;
            if(dfs(k+1))return true;
        }
    }
}

void solve(){
    scanf("%d%d%d%d", &R, &N, &M, &K);
    for(int i=0; i<R; ++i){
        memset(hash,0,sizeof(hash));
        for(int j=0;j<K;++j){
            scanf("%d",&ss[j]);
        }
        if(!dfs(0))
            printf("Error\n");
    }
    return;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t){
        printf("Case #%d:\n", t);
        solve();
    }
}