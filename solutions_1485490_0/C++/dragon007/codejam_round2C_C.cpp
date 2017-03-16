#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <strstream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
#define A first
#define B second
#define eps 1e-8

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int t, n, m;
LL a[110], b[110];
int atype[110], btype[110];

LL work(int i, LL pi, int j, LL pj) {
    if (i > n || j > m) return 0;
    LL ans = 0;
    if (atype[i] == btype[j]) {
        if (a[i] - pi < b[j] - pj) {
            ans = a[i] - pi;
            return ans + work(i + 1, 0, j, pj + a[i] - pi);
        }
        else
            if (a[i] - pi > b[j] - pj) {
                ans = b[j] - pj;
                return ans + work(i , pi + b[j] - pj, j + 1, 0);
            }
            else return a[i] - pi + work(i + 1, 0, j + 1, 0);
    }
    else
        return max(work(i + 1, 0, j, pj), work(i, pi, j + 1, 0));
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C1.out","w",stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++ ) {
        scanf("%d%d", &n, &m);
        for (int j = 1; j <= n; j ++)
            scanf("%lld%d",&a[j], &atype[j]);
        for (int j = 1; j <= m; j ++)
            scanf("%lld%d",&b[j], &btype[j]);
        printf("Case #%d: %lld\n", i, work(1, 0, 1, 0));
    }
    return 0;
}
