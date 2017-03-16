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

int m, n, x[105], y[105], xx[105], nn;
long long a[105], b[105], aa[105];
int test;

int main() {
    freopen("3small.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) cin >> aa[i] >> xx[i];
        FOR(i, 1, m) cin >> b[i] >> y[i];
        nn=0;
        FOR(i, 1, n) if (i==1 || xx[i]!=xx[i-1]) nn++, a[nn]=aa[i], x[nn]=xx[i];
            else a[nn]+=a[i];
        n=nn;
        if (n==1) {
            long long cc=0;
            FOR(i, 1, m) if (x[1]==y[i]) cc+=b[i];
            cout << "Case #" << t << ": " << min(cc, a[1]) << endl;
        } else if (n==2) {
            long long c1=0, c2=0, cc=0;
            FOR(i, 1, m+1) {
                c1=c2=0;
                FOR(j, 1, i-1) if (x[1]==y[j]) c1+=b[j];
                FOR(j, i, m)   if (x[2]==y[j]) c2+=b[j];
                cc = max (cc, min(c1, a[1])+min(c2, a[2]));
            }
            cout << "Case #" << t << ": " << cc << endl;
        } else {
            long long c1=0, c2=0, c3=0, cc=0;
            FOR(i, 0, m) FOR(j, i+1, m+1) {
                c1=c2=c3=0;
                FOR(k, 1, i) if (x[1]==y[k]) c1+=b[k];
                FOR(k, i+1, j-1) if (x[2]==y[k]) c2+=b[k];
                FOR(k, j, m) if (x[3]==y[k]) c3+=b[k];
                cc = max (cc, min(c1, a[1])+min(c2, a[2])+min(c3, a[3]));
            }
            c1=0;
            if (x[1]==x[3]) {
                FOR(j, 1, m) if (y[j]==x[1]) c1+=b[j];
                cc = max(cc, min(c1, a[1]+a[3]));
            }
            cout << "Case #" << t << ": " << cc << endl;
        }
    }
    //system("pause");
    return 0;
}
