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
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <climits>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int n = 12, m = 8;

int t, val[n], n_prod, prod[16], cc[20000];
set<pair<int, int> > ss;
long long cnt;
string str[20000];

void solve() {
    int r;
    scanf("%d%*d%*d%d", &r, &n_prod);
    printf("Case #%d:\n", ++t);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < n_prod; ++j) {
            scanf("%d", &prod[j]);
        }
        sort(prod, prod + n_prod, greater<int>());
        memset(cc, 0, sizeof(cc));
        for (int j = 0; j < n_prod; ++j) {
            set<pair<int, int> >::iterator it = ss.lower_bound(make_pair(prod[j], 0));
            while (it != ss.end() && it->first == prod[j]) {
                ++cc[it->second];
                ++it;
            }
        }
        for (int j = 0; j < cnt; ++j) {
            if (cc[j] == n_prod) {
                printf("%s\n", str[j].c_str());
                break;
            }
        }
    }
}

void dfs(int k, int v, long long prod) {
    if (k == n) {
        string s;
        for (int j = 0; j < n; ++j) {
            s += (char)(val[j] + '0');
        }
        str[cnt] = s;
        for (int i = 0; i < (1 << n); ++i) {
            long long tmp = 1;
            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1) == 1)
                    tmp *= val[j];
            }
            ss.insert(make_pair(tmp, cnt));
        }
        ++cnt;
        //printf("%d\n", cnt);
        return;
    }
    for (int i = v; i <= m; ++i) {
        val[k] = i;
        dfs(k + 1, i, prod * i);
    }
}

void pre() {
    cnt = 0;
    dfs(0, 2, 1);
}

int main() {
    freopen("out.txt", "w", stdout);
    pre();
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
