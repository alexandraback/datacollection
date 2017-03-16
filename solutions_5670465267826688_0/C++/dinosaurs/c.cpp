#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, L, X;
char ijk[10101];
int dp[10101][10101];

// 1ijk
int to_int(char c) {
    if (c == '1') {
        return 1;
    } else {
        return 2 + (c - 'i');
    }
}

int next(int i) {
    if (i < 4) {
        return i + 1;
    } else {
        return 2;
    }
}

char prod(int a, int b) {
    int sign = (a * b < 0 ? -1 : 1);
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    if (a == 1) {
        return b * sign;
    } else if (a == b) {
        return -1 * sign;
    } else if (b == next(a)) {
        return sign * (2 + 3 + 4 - a - b);
    } else {
        return -sign * (2 + 3 + 4 - a - b);
    }
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &L, &X);
        scanf("%s", ijk);
        for (int i = 0; i < L * X; ++i) {
            ijk[i] = ijk[i % L];
            dp[i][i] = to_int(ijk[i]);
        }

        for (int i = 0; i < L * X; ++i) {
            for (int j = i + 1; j < L * X; ++j) {
                dp[i][j] = prod(dp[i][j - 1], dp[j][j]);
            }
        }

        bool good = false;
        for (int i = 1; i < L * X && !good; ++i) {
            if (dp[0][i - 1] != 2) {
                continue;
            }
            for (int j = i + 1; j < L * X && !good; ++j) {
                if (dp[0][i - 1] == 2 && dp[i][j - 1] == 3 && dp[j][L * X - 1] == 4) {
                    good = true;
                }
            }
        }

        if (good) {
            printf("Case #%d: YES\n", t);
        } else {
            printf("Case #%d: NO\n", t);
        }
    }

    return 0;
}
