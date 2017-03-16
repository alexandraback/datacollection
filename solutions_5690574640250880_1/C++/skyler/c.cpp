#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const int MAX = 55;
int n, r, c, m;
char g[MAX][MAX];
void solve() {
    rep(i, r) {
        rep(j, c) g[i][j] = '*';
    }
    bool f;
    m = r*c - m;
    if (!m) f = 0;
    else if (m==1) {
        f = 1;
        g[0][0] = 'c';
    }
    else if (r==1 || c==1) {
        f = 1;
        g[0][0] = 'c';
        if (r==1) {
            rep(i, m) {
                if (i) g[0][i] = '.';
            }
        }
        if (c==1) {
            rep(i, m) {
                if (i) g[i][0] = '.';
            }
        }
    }
    else if (r==2 || c==2) {
        if ((m&1) || m<=3) f = 0;
        else {
            f = 1;
            if (r==2) {
                rep(i, m/2) {
                    g[0][i] = g[1][i] = '.';
                }
            }
            else if (c==2) {
                rep(i, m/2) {
                    g[i][0] = g[i][1] = '.';
                }
            }
            g[0][0] = 'c';
        }
    }
    else {
        if (m<=3 || m==5 || m==7) f = 0;
        else {
            f = 1;
            if (m <= 2*c + 1) {
                if (m & 1) {
                    rep(i, (m-3)/2) {
                        g[0][i] = g[1][i] = '.';
                    }
                    g[2][0] = g[2][1] = g[2][2] = '.';
                    g[0][0] = 'c';
                }
                else {
                    rep(i, m/2) {
                        g[0][i] = g[1][i] = '.';
                    }
                    g[0][0] = 'c';
                }
            }
            else if (m%c==1) {
                rep(i, m/c-1) {
                    rep(j, c) {
                        g[i][j] = '.';
                    }
                }
                rep(i, c-1) g[m/c-1][i] = '.';
                g[m/c][0] = g[m/c][1] = '.';
                g[0][0] = 'c';
            }
            else {
                rep(i, r) {
                    rep(j, c) {
                        if (!m) break;
                        m--;
                        g[i][j] = '.';
                    }
                }
                g[0][0] = 'c';
            }
        }
            
    }

    if (!f) printf("Impossible\n");
    else {
        rep(i, r) {
            rep(j, c) {
                //if (j) printf(" ");
                printf("%c", g[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d%d%d", &r, &c, &m);
        printf("Case #%d:\n", i+1);
        solve();
    }
    return 0;
}
