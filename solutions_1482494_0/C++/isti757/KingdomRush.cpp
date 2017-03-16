#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
    if(p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

int main() {
    int T;
    cin >> T;

    for(int TT = 1; TT <= T; TT++) {
        int N;
        cin >> N;

        vector<pair<int, int> > ab(N, make_pair(0, 0));
        for(int i = 0; i < N; i++) {
            cin >> ab[i].first >> ab[i].second;
        }

        sort(ab.begin(), ab.end(), compare);

        vector<int> a(N), b(N);
        for(int i = 0; i < N; i++) {
            a[i] = ab[i].first;
            b[i] = ab[i].second;
        }

        int inf = (1 << 25);
        vector<vector<vector<int > > > dp(2*N+5, vector<vector<int> >(N, vector<int>(3, inf) ) ); // stars, levels, store min moves

        dp[0][0][0] = 0;
        for(int level = 0; level < N; level++) {
            for(int stars = 0; stars <= 2*N+2; stars++) {
                if(stars >= a[level]) {
                    dp[stars+1][level][1] = min(dp[stars][level][0]+1, dp[stars+1][level][1]);
                    if(level != N-1) {
                        if(stars+1 >= a[level+1] && dp[stars+1][level][1] < inf)
                            dp[stars+1][level+1][0] = min(dp[stars+1][level][1], dp[stars+1][level+1][0]);
                    }
                }

                if(stars >= b[level]) {
                    dp[stars+1][level][2] = min(dp[stars][level][1]+1, dp[stars+1][level][2]);
                    dp[stars+2][level][2] = min(dp[stars][level][0]+1, dp[stars+2][level][2]);

                    if(level != N-1) {
                        if(stars+1 >= a[level+1] && dp[stars+1][level][2] < inf) {
                            dp[stars+1][level+1][0] = min(dp[stars+1][level][2], dp[stars+1][level+1][0]);
                            dp[stars+1][level+1][1] = min(dp[stars+1][level][2], dp[stars+1][level+1][1]);
                        }
                        if(stars+2 >= a[level+1] && dp[stars+2][level][2] < inf) {
                            dp[stars+2][level+1][0] = min(dp[stars+2][level][2], dp[stars+2][level+1][0]);
                            dp[stars+2][level+1][1] = min(dp[stars+2][level][2], dp[stars+2][level+1][1]);
                        }
                    }
                }
            }
        }

        int minMoves = inf;
        for(int stars = 0; stars < 2*N+5; stars++) {
            minMoves = min(minMoves, dp[stars][N-1][2]);
        }

        if(minMoves < inf)
            printf("Case #%d: %d\n", TT, minMoves);
        else
            printf("Case #%d: Too Bad\n", TT);
    }
    return 0;
}
