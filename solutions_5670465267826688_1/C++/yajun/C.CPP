/*

½á¹ûÎª-1

(-1)^n * L[0..i] = i;
(-1)^(x-n) * L[..k] = j;

*/
# include <iostream>
# include <stdio.h>
# include <algorithm>

const int maxn = 10005 * 2;

int L, X;
char l[maxn];
int d[256];

void init()
{
    d['i'] = 2;
    d['j'] = 3;
    d['k'] = 5;
}

int mul(int x, int y)
{
    int f = (x / abs(x)) * ( y / abs(y));
    x = abs(x), y = abs(y);
    if (x == 1 || y == 1) return f * x * y;
    else if (x == y) return f * -1;
    else if (x == 2 && y == 3) return f * 5 ;
    else if (x == 3 && y == 5) return f * 2;
    else if (x == 5 && y == 2) return f * 3;
    else return -f * mul(y, x);
}
# define testin freopen("C-large.in", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
int main()
{
    //freopen("in.txt", "r", stdin);
    testin;
    testout;

    init();

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%d%d%s", &L, &X, l);
        printf("Case #%d: ", ica);
        int sX = X;
        int n = L;
        if (X%2 == 0) {
            for (int i = 0; i < L; ++i) l[L+i] = l[i];
            l[L + L] = 0;
            X -= 2;
            n = L + L;
        } else {
            X -= 1;
        }
        X /= 2;
        /// 1. check ans

        int aa = 1;
        for (int i = 0; i < L; ++i) {
            aa = mul(aa, d[ l[i] ]);
        }
        if (abs(aa) == 1) {
            if (sX%2 == 0) aa *= aa;
        } else {
            if (sX%2 == 0) {
                sX /= 2;
                aa = (sX%2 == 0 ? 1:-1);
            }
        }
        if (aa != -1) {
            puts("NO");
        } else {
            /// 2. check 'i'
            int la = 1, li = -1;
            for (int i = 0; i < n; ++i) {
              //  printf("%d %d %d\n", la, d[ l[i] ], mul(la, d[ l[i] ]));
                la = mul(la, d[ l[i] ]);
                if ( la == d['i'] ) {
                    li = i;
                    break;
                } else if ( la == -d['i'] && X > 0) {
                    --X;
                    li = i;
                    break;
                }
            }

            if (li == -1) {
                puts("NO");
            } else {
                /// 3. check 'k'
                int rk = -1, ra = 1;
                int hi = (X == 0 ? li+1:0);
                for (int i = n-1; i >= hi; --i) {
                    ra = mul(d[ l[i] ], ra);
                    if (ra == d['k']) {
                        rk = i;
                        break;
                    } else if (ra == -d['k'] && X > 0) {
                        rk = i;
                        --X;
                        break;
                    }
                }
                if (rk == -1) {
                    puts("NO");
                } else {
                    puts("YES");
                }
            }
        }
    }

    return 0;
}
