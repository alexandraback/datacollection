#include <cstdio>
#include <cstring>
using namespace std;

int mat[4][4] = {
    0, 1, 2, 3,
    1, 0, 3, 2,
    2, 3, 0, 1,
    3, 2, 1, 0
};

int sgn[4][4] = {
    1, 1, 1, 1,
    1, -1, 1, -1,
    1, -1, -1, 1,
    1, 1, -1, -1
};

int dp[200010][4][4][3];
int can[110];

char s[200010], pat[10010];

void getSol(char *s, int L, int eachL) {
    // L <= 200000
    for (int i = 0; i < L; i ++) {
        if (s[i] == 'i') {
            s[i] = 1;
        } else if (s[i] == 'j') {
            s[i] = 2;
        } else {
            s[i] = 3;
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][1][0][2] = 1;
    for (int i = 0; i < L; i ++) {
        for (int j = 1; j <= 3; j ++) {
            for (int k = 0; k < 4; k ++) {
                for (int l = 0; l <= 2; l += 2) {
                    if (dp[i][j][k][l] == 0) {
                        continue;
                    }
                    int neK = mat[k][(int)s[i]];
                    int neL = (l - 1) * sgn[k][(int)s[i]] + 1;
                    dp[i + 1][j][neK][neL] = 1;
                    if (neK == j && neL == 2 && j < 3) {
                        dp[i + 1][j + 1][0][2] = 1;
                    }  
                }
            }
        }
    }
    for (int i = eachL; i <= L; i += eachL) {
        if (dp[i][3][3][2] == 1) {
            can[i / eachL] = 1;
        }
    }
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas ++) {
        int l;
        long long x;
        scanf("%d%I64d", &l, &x);
        scanf("%s", pat);
        s[0] = 0;
        for (int i = 0; i < 20; i ++) {
            strcat(s, pat);
            can[i + 1] = 0;
        }
        getSol(s, l * 20, l);
        bool sol = false;
        int tx = x % 4;
        if (tx == 0) {
            tx = 4;
        }
        for (; tx <= 20 && tx <= x; tx += 4) {
            if (can[tx]) {
                sol = true;
            }
        }
        printf("Case #%d: ", cas);
        fprintf(stderr, "Case #%d: ", cas);
        if (sol) {
            puts("YES");
            fprintf(stderr, "YES\n");
        } else {
            puts("NO");
            fprintf(stderr, "NO\n");
        }
    }
    return 0;
}