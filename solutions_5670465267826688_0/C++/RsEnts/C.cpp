#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1000010

using namespace std;

int premat[4][4] = {
1, 2, 3, 4,
2, -1, 4, -3,
3, -4, -1, 2,
4, 3, -2, -1
};

int mat[9][9];

int T;
int L;
long long X;
char str[MaxN];

int Power(int to, long long b) {
    int base = to, y = 0;
    for( ; b; b >>= 1LL, base = mat[base][base])
        if(b & 1LL)
            y = mat[y][base];
    return y;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int i, j, T0 = 0;
    for(i = 0; i < 8; ++i) {
        for(j = 0; j < 8; ++j) {
            int s = i, t = j, fl = 0;
            if(s >= 4) {
                s -= 4; fl ^= 1;
            }
            if(t >= 4) {
                t -= 4; fl ^= 1;
            }
            mat[i][j] = premat[s][t];
            if(fl)
                mat[i][j] = -mat[i][j];
            if(mat[i][j] < 0) {
                mat[i][j] = -mat[i][j] + 4 - 1;
            }
            else {
                mat[i][j] = mat[i][j] - 1;
            }
        }
    }
    scanf("%d", &T);
    for( ; T; --T) {
        scanf("%d%lld", &L, &X);
        scanf("%s", &str);
        int now = 0;
        for(i = 0; i < L; ++i) {
            int tmp = str[i] - 'i' + 1;
            now = mat[now][tmp];
        }
        int ret = Power(now, X);
        if(ret != 4) {
            printf("Case #%d: NO\n", ++T0);
            continue;
        }
        if(X > 20) X = 20;

        for(i = 0; i < L; ++i)
            for(j = 1; j < X; ++j)
                str[i + j * L] = str[i];
        L *= X;
        int lmost = L, rmost = 0;
        now = 0;
        for(i = 0; i < L; ++i) {
            int tmp = str[i] - 'i' + 1;
            now = mat[now][tmp];
            if(now == 1) {
                lmost = i; break;
            }
        }
        now = 0;
        for(i = L - 1; i >= 0; --i) {
            int tmp = str[i] - 'i' + 1;
            now = mat[tmp][now];
            if(now == 3) {
                rmost = i; break;
            }
        }
        if(lmost + 1 < rmost) {
            printf("Case #%d: YES\n", ++T0);

        }
        else {
            printf("Case #%d: NO\n", ++T0);
        }
    }
    return 0;
}
