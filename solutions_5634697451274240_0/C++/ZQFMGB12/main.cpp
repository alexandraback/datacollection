#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T,N;
char S[105];

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        scanf(" %100s",S);
        int N = strlen(S);
        int ans = 0;
        for (int i = N-1; i >= 0; i--){
            if (i == N-1){
                if (S[i] == '-') ans++;
            }else{
                if (S[i] != S[i+1]) ans++;
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
