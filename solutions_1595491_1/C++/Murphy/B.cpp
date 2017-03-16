#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    int T;
    cin>>T;
    REP(i, T) {
        int N, S, P;
        cin>>N>>S>>P;
        int r[128];
        int p[32][4] = {0};
        for (int t1 = 0; t1 <= 10; t1++)
            for (int t2 = t1; t2 <= 10 && t2 <= t1 + 2; t2++)
                for (int t3 = t2; t3 <= 10 && t3 <= t1 + 2; t3++) {
                    int r = 0;
                    if (t3 - t1 == 2) {
                        r |= 1;
                    }
                    if (t3 >= P) {
                        r |= 2;
                    }
                    p[t1 + t2 + t3][r] = 1;
                }
        int dp[128][128];
        memset(dp, 0, sizeof dp);
        REP(k, N) {
            int score;
            cin>>score;
            for (int s = 0; s <= S; s++) {
                if (p[score][0]) {
                    dp[k + 1][s] = max(dp[k + 1][s], dp[k][s]);
                }
                if (p[score][1]) {
                    dp[k + 1][s + 1] = max(dp[k + 1][s + 1], dp[k][s]);
                }
                if (p[score][2]) {
                    dp[k + 1][s] = max(dp[k + 1][s], dp[k][s] + 1);
                }
                if (p[score][3]) {
                    dp[k + 1][s + 1] = max(dp[k + 1][s + 1], dp[k][s] + 1);
                }
            }   
        }
        printf("Case #%d: %d\n", i + 1, dp[N][S]);
    }
}
