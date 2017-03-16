#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
int num[1000];
long long dp[105][105];

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas){
        memset(dp, -1, sizeof(dp));
        int N, A;
        scanf("%d%d", &A, &N);
        for(int i = 0; i < N; ++i){
            scanf("%d", num + i);
        }
        sort(num, num + N);
        dp[0][0] = A;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j <= N; ++j){
                if(dp[i][j] != -1){
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                    LL temp = dp[i][j];
                    for(int k = 0; k <= N - j; ++k){
                        if(temp > num[i]){
                            dp[i + 1][j + k] = max(dp[i + 1][j + k], temp + num[i]);
                        }
                        temp += temp - 1;
                    }
                }
            }
        }
        int ans = N;
        for(int i = 0; i <= N; ++i){
            if(dp[N][i] != -1){
                ans = i;
                break;
            }
        }
//        for(int i = 0; i <= N; ++i, puts("")){
//            for(int j = 0; j <= N; ++j) printf("%lld ", dp[i][j]);
//        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
