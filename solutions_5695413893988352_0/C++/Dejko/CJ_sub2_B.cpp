#include <bits/stdc++.h>

using namespace std;

int t;
char a[10], b[10];
int c;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    scanf("%d", &t);
    for (int tp=1; tp<=t; tp++) {
        scanf("%s", a);
        scanf("%s", b);

        int len = strlen(a);
        int xx = 0;
        int yy = 0;
        /*
        for (int i=0; i<len; i++) {
            xx = xx * 10 + a[i]-'0';
            yy = yy * 10 + b[i]-'0';
        }
        int min_dist = abs(xx-yy);
        */
        int min_dist = 10000;
        int D;
        if (len == 1) D = 10;
        else if (len == 2) D = 100;
        else D = 1000;
        for (int x=0; x<D; x++) {
            bool ok = true;
            for (int i=0; i<len; i++) {
                if (a[i] == '?') continue;
                if (D == 1000) {
                    if (i == 0) c = x / 100;
                    if (i == 1) c = x / 10 % 10;
                    if (i == 2) c = x % 10;
                }
                else if (D == 100) {
                    if (i == 0) c = x / 10;
                    else c = x % 10;
                }
                else c = x;
                if (a[i] - '0' != c) ok = false;
            }
            if (!ok) continue;
            for (int y=0; y<D; y++) {
                ok = true;
                for (int i=0; i<len; i++) {
                    if (b[i] == '?') continue;
                    if (D == 1000) {
                        if (i == 0) c = y / 100;
                        if (i == 1) c = y / 10 % 10;
                        if (i == 2) c = y % 10;
                    }
                    else if (D == 100) {
                        if (i == 0) c = y / 10;
                        else c = y % 10;
                    }
                    else c = y;
                    if (b[i] - '0' != c) ok = false;
                }
                if (!ok) continue;

                int dist = abs(x-y);
                if (dist < min_dist) {
                    min_dist = dist;
                    xx = x;
                    yy = y;
                }
            }
        }

        printf("Case #%d: ", tp);
        if (len == 3) {
            if (xx < 100) printf("0");
            if (xx < 10) printf("0");
        }
        else if (len == 2) {
            if (xx < 10) printf("0");
        }
        printf("%d ", xx);
        if (len == 3) {
            if (yy < 100) printf("0");
            if (yy < 10) printf("0");
        }
        else if (len == 2) {
            if (yy < 10) printf("0");
        }
        printf("%d\n", yy);
        /*
        for (int l=1; l<=len; l++) {
            for (int i=0; i<10; i++) {
                for (int j=0; j<10; j++) {
                    dp[i][j][l] = inf;
                    for (int i1=0; i1<10; i1++) {
                        for (int j1=0; j1<10; j1++) {
                            dp[i][j][l] = dp[i1][j1][l-1]*10 + i-j;
                        }
                    }
                }
            }
        }
        */
    }

    return 0;
}
