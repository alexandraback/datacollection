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

int t, m, n_prod, prod[16];

int get() {
    for (int x = 2; x <= m; ++x) {
        for (int y = 2; y <= m; ++y) {
            for (int z = 2; z <= m; ++z) {
                bool f = true;
                for (int i = 0; i < n_prod; ++i) {
                    if (prod[i] == 1 || prod[i] == x || prod[i] == y || prod[i] == z)
                        continue;
                    if (prod[i] == x * y * z || prod[i] == x * y || prod[i] == y * z || prod[i] == z * x)
                        continue;
                    f = false;
                }
                if (f)
                    return x * 100 + y * 10 + z;
            }
        }
    }
    return 222;
}

void solve() {
    int r, n;
    scanf("%d%d%d%d", &r, &n, &m, &n_prod);
    printf("Case #%d:\n", ++t);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < n_prod; ++j) {
            scanf("%d", &prod[j]);
        }
        printf("%d\n", get());
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
