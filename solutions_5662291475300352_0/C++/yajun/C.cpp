# include <stdio.h>
# include <string.h>
# include <iostream>

typedef long long int lli;
using namespace std;

# define testin freopen("C-small-1-attempt1.in"/*"in.txt"*/, "r", stdin)
# define testout freopen("out2.txt", "w", stdout)

const int N = 10;

int n;
int d[N], m[N];int h[N];

int c;
lli s[N];
lli v[N];

int main()
{
    testin;
    testout;
    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        printf("Case #%d: ", ica);
        scanf("%d", &n);
        c = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &d[i], &h[i], &m[i]);
            for (int j = 0; j < h[i]; ++j) {
                s[c] = d[i];
                v[c] = m[i]+j;
                ++c;
            }
        }

        if (c <= 1) {
            printf("0\n");
        } else if (c <= 2){
            int ans = 0;

            lli x0 = (360LL-s[0])*v[0];
            lli x1 = (720LL-s[0])*v[0];

            lli y0 = (360LL-s[1])*v[1];
            lli y1 = (720LL-s[1])*v[1];

            //double t0 = (360.0-s[0]) / (360/v[0]);

            if (x1<=y0) ans = 1;
            if (y1<=x0) ans = 1;

/*
            lli x = (360-s[0])*v[1];
            lli y = (360-s[1])*v[0];
            lli z = (720-s[0])*v[1];

            if (x <= y && z <= y) ans = 1;

            x = (360-s[1])*v[0];
            y = (360-s[0])*v[1];
            z = (720-s[1])*v[0];

            if (x <= y && z <= y) ans = 1;
*/           printf("%d\n", ans);
        } else {
            printf("NONE\n");
        }
    }

    return 0;
}
