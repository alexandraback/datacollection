#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long dp[110][110];
pair<long long, int> A[110];
pair<long long, int> B[110];
vector<int> posA[110];
vector<int> posB[110];

long long presumA[110][110];
long long presumB[110][110];

int N, M;

long long solve(int id1, int id2) {
    if (dp[id1][id2] != -1) return dp[id1][id2];
    long long& ret = dp[id1][id2];
    ret = 0;
    int type = A[id1].second;
    for (int i = 0; i < posA[type].size(); i++) {
        if (posA[type][i] < id1) continue;
        for (int j = 0; j < posB[type].size(); j++) {
            if (posB[type][j] < id2) continue;
            
            int i1 = posA[type][i];
            int j1 = posB[type][j];
            long long r = 0;
            for (int i2 = i1 + 1; i2 < N; i2++) {
                for (int j2 = j1 + 1; j2 < M; j2++) {
                    if (A[i2].second == B[j2].second) {
                        r = max(r, solve(i2, j2));
                    }
                }
            }
            
            long long sum1 = presumA[i1][type] - (id1 > 0 ? presumA[id1 - 1][type] : 0);
            long long sum2 = presumB[j1][type] - (id2 > 0 ? presumB[id2 - 1][type] : 0);
            ret = max(ret, r + min(sum1, sum2));
        }
    }
    return ret;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(dp, -1, sizeof(dp));
        memset(presumA, 0, sizeof(presumA));
        memset(presumB, 0, sizeof(presumB));
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            posA[i].clear();
        }
        for (int i = 0; i < M; i++) {
            posB[i].clear();
        }
        for (int i = 0; i < N; i++) {
            long long a;
            int b;
            cin >> a >> b;
            A[i].first = a;
            A[i].second = b;
            posA[b].push_back(i);
            if (i) for (int j = 1; j <= 100; j++) presumA[i][j] = presumA[i - 1][j];
            if (i) presumA[i][b] = presumA[i - 1][b] + a; else presumA[i][b] = a;
        }
        for (int i = 0; i < M; i++) {
            long long a;
            int b;
            cin >> a >> b;
            B[i].first = a;
            B[i].second = b;
            posB[b].push_back(i);
            if (i) for (int j = 1; j <= 100; j++) presumB[i][j] = presumB[i - 1][j];
            if (i) presumB[i][b] = presumB[i - 1][b] + a; else presumB[i][b] = a;
        }
        
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i].second == B[j].second) {
                    ans = max(ans, solve(i, j));
                }
            }
        }
        cout << "Case #" << t << ": ";
        cout << ans << endl;
    }
    return 0;
}

        
            