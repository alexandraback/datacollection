#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 555
#define mod 1000000005
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

ll a[N][N], need, x, i, j, n, m, T, t, gr[N];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%lld", &T);

    for(t = 1; t <= T; t++) {
        printf("Case #%lld: ", t);
        scanf("%lld%lld", &n, &m);

        if(m > (n - 2) * (n - 1) / 2 + 1) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        printf("POSSIBLE\n");

        for(i = 1; i <= n; i++) {
            gr[i] = 0;

            for(j = 1; j <= n; j++)
                a[i][j] = 0;
        }

        need = m - 1;
        a[1][n] = 1;

        for(i = 2; i < n&&need; i++) {
            x = n - i;

            if(x > need)
                x = need;

            need -= x;

            if(x >= gr[i]) {
                a[1][i] = 1;
                gr[i]++;
                a[i][n] = 1;
                x -= gr[i];
            }

            for(j = i + 1; j < n && x; j++) {
                if(gr[i] <= x) {
                    a[i][j] = 1;
                    a[j][n] = 1;
                    x -= gr[i];
                    gr[j]++;
                    gr[j] += gr[i];
                }
            }
        }

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++)
                printf("%lld", a[i][j]);

            printf("\n");
        }
    }

    return 0;
}

