#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1234567890;
const int MAX = 1 << 20;

int A;
int N;
int motes[100];

int dp[2][MAX];

int go() {
    sort(motes, motes + N);

    for (int j = 1; j < MAX; ++j) dp[0][j] = INF;
    dp[0][A] = 0;

    for (int i = 0; i < N; ++i) {
        int a = i % 2;
        int b = (i + 1) % 2;

        for (int j = 1; j < MAX; ++j) dp[b][j] = INF;

        for (int j = 1; j < MAX; ++j) if (dp[a][j] < INF) {
            dp[b][j] = min(dp[b][j], dp[a][j] + 1);

            if (j > 1) {
                int k = 0;
                int jj = j;
                while (jj <= motes[i]) {
                    jj += jj - 1;
                    ++k;
                }
                jj += motes[i];
                jj = min(jj, MAX - 1);

                dp[b][jj] = min(dp[b][jj], dp[a][j] + k);
            }
        }
    }

    int re = INF;
    int a = N % 2;
    for (int j = 1; j < MAX; ++j) re = min(re, dp[a][j]);

    return re;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d", &A, &N);
        for (int n = 0; n < N; ++n) scanf("%d", motes + n);
        printf("Case #%d: %d\n", t, go());
    }

    return 0;
}
