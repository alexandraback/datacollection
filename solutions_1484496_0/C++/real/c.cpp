#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <numeric>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define REP(i,n)   FOR(i,0,n)
#define ALL(x) (x).begin(), (x).end()
#define CLR(s) memset(s,0,sizeof(s))
#define PB push_back
#define ITER(v)      __typeof((v).begin())
#define FOREACH(i,v) for(ITER(v) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
#define x first
#define y second

const int N = 20360;
LL a[N];
int n;

void out(int x) {
        bool f = false;
        FOR(i, 0, n) if ((1<<i)&x) {
                if (f) putchar(' ');
                else f = true;
                printf("%lld", a[i]);
        } puts("");
}

int main() {
        int t; scanf("%d", &t);
        FOE(ca, 1, t) {
                scanf("%d", &n);
                FOR(i, 0, n) scanf("%lld", a+i);

                map<LL,vi> bin;
                FOR(b, 1, 1<<n) {
                        LL s = 0LL;
                        FOR(i, 0, n) {
                                if ((b>>i)&1) {
                                        s += a[i];
                                }
                        }
                        bin[s].PB( b );
                }

                printf("Case #%d:\n", ca);

                bool sol = false;
                FOREACH(it, bin) {
                        vi &v = it->second;
                        FOR(i, 0, v.size()) FOR(j, i+1, v.size()) {
                                if (!(v[i] & v[j])) {
                                        out(v[i]);
                                        out(v[j]);
                                        sol = true;
                                        goto END;
                                }
                        }
                }

END:
                if (!sol) puts("Impossible");
        }

        return 0;
}
