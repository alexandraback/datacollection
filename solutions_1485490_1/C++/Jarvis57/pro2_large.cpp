#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))

int m, n, x[105], y[105];
long long a[105], b[105], f[105][105];
int test;

int main() {
    freopen("3large.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) cin >> a[i] >> x[i];
        FOR(i, 1, m) cin >> b[i] >> y[i];
        FOR(i, 1, n+1) FOR(j, 1, m+1) f[i][j]=0;
        DOW(i, n, 1) DOW(j, m, 1) 
            if (x[i]!=y[j]) f[i][j]=max(f[i+1][j], f[i][j+1]);
            else if (a[i]==b[j]) f[i][j]=f[i+1][j+1]+a[i];
            else {
                int u=i, v=j, k;
                long long r=min(a[u], b[v]), sl=max(a[u], b[v])-r;
                if (a[u]>b[v]) k=1; else k=2;
                while (u<=n && v<=m) {
                    f[i][j]=max(f[i][j], r+f[u+1][v+1]);
                    if (k==1) {
                        v++;
                        while (v<=m && y[v]!=x[u]) v++;
                        if (v<=m) {
                            if (sl==b[v]) {
                                f[i][j]=max(f[i][j], r+sl+f[u+1][v+1]);
                                break;
                            }
                            if (sl<b[v]) r+=sl, k=2, sl=b[v]-sl;
                            else r+=b[v], k=1, sl=sl-b[v];
                        }
                    } else {
                        u++;
                        while (u<=n && x[u]!=y[v]) u++;
                        if (u<=n) {
                            if (sl==a[u]) {
                                f[i][j]=max(f[i][j], r+sl+f[u+1][v+1]);
                                break;
                            }
                            if (sl>a[u]) r+=a[u], k=2, sl=sl-a[u];
                            else r+=sl, k=1, sl=a[u]-sl;
                        }
                    }
                }
            }
        cout << "Case #" << t << ": " << f[1][1] << endl;
    }
    //system("pause");
    return 0;
}
