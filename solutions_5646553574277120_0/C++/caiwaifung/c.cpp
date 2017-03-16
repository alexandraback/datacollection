#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
using namespace std;
#pragma warning(disable: 4996)

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

// ------------------------ template ends here ------------------------ //

int V; unsigned full;
unsigned put(unsigned cur, int x) {
    unsigned tmp = cur;
    forint(i, 0, V) {
        if (cur&(1 << i)) {
            if (i + x <= V) tmp |= 1 << (i + x);
        }
    }
    return tmp;
}
int ans;

bool used[99];

void dfs(int tot, int lb, unsigned cur) {
    if (tot >= ans) return;
    if (cur == full) {
        ans = tot; return;
    }
    while (lb <= V) {
        if (!used[lb]) {
            used[lb] = true; 
            dfs(tot + 1, lb + 1, put(cur, lb));
            used[lb] = false; 
        }
        ++lb;
    }
}

int main() {
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\c_in.txt", "r", stdin);
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\c_out.txt", "w", stdout);
    int cs; scanf("%d", &cs);
    forint(fcs, 1, cs) {
        ans = 999;
        int C, D; scanf("%d%d%d", &C, &D, &V);
        if (C > 1) break;
//assert(C == 0);
        int d[99]; forint(i, 1, D) scanf("%d", &d[i]);
        fillchar(used, false);

        full = (1u << (V + 1)) - 1;
        unsigned cur = 1;
        forint(i, 1, D) cur = put(cur, d[i]), used[d[i]] = true;
        dfs(0, 1, cur);

        printf("Case #%d: %d\n", fcs, ans);
    }
	return 0;
}
