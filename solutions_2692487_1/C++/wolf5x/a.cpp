#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 110;

long long dp[maxn][maxn];
int T, A, N, S[maxn];

inline void checkmax(long long &a, long long b){
    if(a<b) a=b;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("al.out","w",stdout);
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d",&A, &N);
        for(int i = 0; i<N; i++){
            scanf("%d", &S[i]);
        }
        sort(S,S+N);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = A;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= N; j++){
                if(dp[i][j] >= 0){
                    //absorb
                    if(dp[i][j] > S[i]){ 
                        checkmax(dp[i+1][j], dp[i][j]+S[i]);
                    }
                    //remove
                    if(j<N) {
                        checkmax(dp[i+1][j+1], dp[i][j]);
                    }
                    //add
                    if(j<N && dp[i][j]>1) {
                        checkmax(dp[i][j+1], dp[i][j]+dp[i][j]-1);
                    }
                }
            }
        }
        int ans = N;
        for(int i = 0; i <N; i++)
            if(dp[N][i]>=0){
                ans = i;
                break;
            }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
