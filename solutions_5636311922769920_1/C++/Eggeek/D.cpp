#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long llong;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const llong INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/

void solve(int k, int c, int s) {

    if (k == s) {
        for (int i=1; i<=s; i++) printf("%d%c", i, i==s?'\n': ' ');
    } else {
        if (c >= k) {
            llong idx = 0;
            for (int i=0; i<c; i++) {
                idx = idx * k + i % k;
            }
            printf("%lld\n", idx+1l);
        } else if (s * c < k) {
            printf("IMPOSSIBLE\n");
        } else {
            vector<llong> ans;
            int idx = 0;
            for (int i=0; i<s; i++) {
                llong res = 0;
                for (int j=0; j<c; j++) {
                    res = res * k + idx;
                    idx = (idx + 1) % k;
                }
                ans.push_back(res);
            }
            UNIQUE(ans);
            for (int i=0; i<(int)ans.size(); i++) {
                printf("%lld%c", ans[i]+1l, i == (int)ans.size()-1?'\n': ' ');
            }
        }
    }
}

int main() {
    freopen("test2.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int cas;
    cin >> cas;
    for (int i=1; i<=cas; i++) {
        int k, c, s;
        cin >> k >> c >> s;
        printf("Case #%d: ", i);
        solve(k, c, s);
    }
    return 0;
}
