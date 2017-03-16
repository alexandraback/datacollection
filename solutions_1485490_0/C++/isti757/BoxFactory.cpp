
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>
using namespace std;


int main() {
    //freopen ("C-small-attempt0.in","r",stdin);

    int T;
    cin >> T;

    for(int TT = 1; TT <= T; TT++) {
        int N, M;
        cin >> N >> M;

        long long a[2*100], b[2*100];
        for(int i = 0; i < 2*N; i++) {
            long long tmp;
            cin >> tmp;
            a[i] = tmp;
        }

        for(int j = 0; j < 2*M; j++){
            long long tmp;
            cin >> tmp;
            b[j] = tmp;
        }

        long long edges[100][100];
        memset(edges, 0, sizeof(long long) * 100 * 100);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(a[2*i+1] == b[2*j+1]) {
                    edges[i][j] = min(a[2*i], b[2*j]);
                }
            }
        }

        long long cum[100][100][2];
        memset(cum, 0, sizeof(long long) * 100 * 100 * 2);

        for(int i = 0; i < N; i++)
            cum[i][a[2*i+1]][0] = a[2*i];

        for(int i = 0; i < M; i++)
            cum[i][b[2*i+1]][1] = b[2*i];

        for(int i = 1; i < N; i++) {
            for(int t = 0; t < 100; t++)
                cum[i][t][0] += cum[i-1][t][0];
        }

        for(int i = 1; i < M; i++) {
            for(int t = 0; t < 100; t++)
                cum[i][t][1] += cum[i-1][t][1];
        }


        long long dp[100][100];
        memset(dp, 0, sizeof(long long) * 100 * 100);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++) {
                if(a[2*i+1] == b[2*j+1])
                    dp[i][j] = min(cum[i][a[2*i+1]][0], cum[j][b[2*j+1]][1]);

                if(i >= 1)
                    dp[i][j] = max(dp[i-1][j],dp[i][j]);
                if(j >= 1)
                    dp[i][j] = max(dp[i][j-1],dp[i][j]);

                if(i >= 1 && j >= 1)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);

                if(edges[i][j] && i >= 1 && j >= 1) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+edges[i][j]);
                }
            }

        long long maxSum = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                maxSum = max(maxSum, dp[i][j]);

        printf("Case #%d: %lld\n", TT, maxSum);
    }

    return 0;
}
