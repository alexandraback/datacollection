# include <stdio.h>
# include <string.h>
# include <iostream>
# include <math.h>
# include <queue>
typedef long long int lli;
using namespace std;

# define testin freopen("C-small-2-attempt1.in"/*"in.txt"*/, "r", stdin)
# define testout freopen("out.txt", "w", stdout)

const int N = 105;

int n;
int d[N], m[N];int h[N];

int c;
lli s[N];
lli v[N];
lli x[N];

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
        priority_queue<lli, vector<lli>, greater<lli> > Q;
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < c*c; ++j) {
                Q.push( (360LL+j*360LL-s[i])*v[i] );
            }
        }

        x[0] = 0;
        for (int i = 0; i < c+2; ++i) {
            x[i+1] = Q.top(); Q.pop();
        }

        int ans = c * c;
        for (int i = 0; i < c+3; ++i) {
            int t = 0;
            for (int j = 0; j < c; ++j) {
                if ( (360LL-s[j])*v[j] >= x[i]) t += 1;
                else {
                    t += (int)floor((x[i] + s[j]*v[j]) / (v[j]*360LL) ) - 1;
                }
            }
            ans = min(ans, t-1);
        }
        printf("%d\n", ans);

    }

    return 0;
}
