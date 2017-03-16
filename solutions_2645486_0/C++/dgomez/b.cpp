# include <iostream>
# include <cstring>
using namespace std;

const int maxn = 20;
const int maxe = 20;
int R, N, E;
int dp[maxn + 1][maxe + 1];
int v[maxn + 1];

int go(int i, int e) {
    int j;

    if (i == N) {
        return 0;
    }

    int& ans = dp[i][e];
    if (ans != -1) {
        return ans;
    }

    ans = 0;
    for (j = 0; j <= e; j++) {
        ans = max(ans, j * v[i] + go(i + 1, min(E, e - j + R)));
    }

    return ans;
}

int main() {
    int t, tt, i;

    cin >> t;
    for (tt = 0; tt < t; tt++) {
        cin >> E >> R >> N;
        for (i = 0; i < N; i++) {
            cin >> v[i];
        }

        memset(dp, -1, sizeof dp);
        cout << "Case #" << (tt + 1) << ": " << go(0, E) << endl;
    }
    return 0;
}
