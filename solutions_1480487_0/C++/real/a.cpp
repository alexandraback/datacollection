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

int t, n;
const int N = 20360;
int J[N];

int main() {
        scanf("%d", &t);
        FOE(ca, 1, t) {
                scanf("%d", &n);
                FOR(i, 0, n) scanf("%d", &J[i]);
                int X = accumulate(J, J+n, 0);
                printf("Case #%d:", ca);
                FOR(i, 0, n) {
                        double lo = 0, hi = 1;
                        FOR(iter, 0, 100) {
                                double md = (lo + hi) * .5;
                                double pt = J[i] + md * X;
                                double rem = 1.0 - md;
                                FOR(j, 0, n) if (i != j) {
                                        double q = (pt - J[j]) / X;
                                        q = max(q, (double)0.0);
                                        rem -= q;
                                }
                                (rem < 0 ? hi : lo) = md;
                        }
                        printf(" %.9f", lo*100);
                } puts("");
        }
        return 0;
}
