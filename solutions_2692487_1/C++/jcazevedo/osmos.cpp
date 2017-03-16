#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100
#define MAXS 1000001
#define INF 1001

int A, N;
int m[MAXN];
int s[MAXN + 1][MAXS + 1];

int getMinOperations() {
    sort(&m[0], &m[N]);
    for (int i = 0; i <= MAXN; i++)
        for (int j = 0; j <= MAXS; j++)
            s[i][j] = INF;

    s[0][A] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= MAXS; j++) {
            if (s[i - 1][j] != INF) {
                if (j > m[i - 1]) {
                    s[i][min(j + m[i - 1], MAXS)] =
                        min(s[i][min(j + m[i - 1], MAXS)], s[i - 1][j]);
                }

                int nj = j + j - 1;
                int c = 1;
                while (nj <= m[i - 1]) {
                    c++;
                    nj += nj - 1;
                }

                s[i][min(nj + m[i - 1], MAXS)] = min(s[i][min(nj + m[i - 1], MAXS)], s[i - 1][j] + c);
                s[i][j] = min(s[i][j], s[i - 1][j] + 1);
            }
        }
    }

    int best = N;
    for (int i = 1; i <= MAXS; i++)
        if (s[N][i] < best)
            best = s[N][i];

    return best;
}

int main() {
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> A >> N;
        for (int j = 0; j < N; j++) {
            cin >> m[j];
        }

        cout << "Case #" << i << ": "
             << getMinOperations() << endl;
    }

    return 0;
}
