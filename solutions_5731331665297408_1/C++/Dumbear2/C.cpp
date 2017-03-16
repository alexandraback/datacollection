/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t, n, m, o[64], g[64][64];
string zip[64];
bool v2[64], bad[64], all_bad[64], vis[64];
vector<int> ss;

int cmp(int a, int b) {
    return zip[a] < zip[b];
}

int get_cnt(int v) {
    v2[v] = true;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (g[v][i] && !bad[i] && !v2[i]) {
            cnt += get_cnt(i);
        }
    }
    return cnt;
}

bool check(int v) {
    memcpy(bad, all_bad, sizeof(bad));
    // if (ss.size() == 4) output(count(bad, bad + n, true));
    if (!ss.empty()) {
        int k = ss.size() - 1;
        while (k >= 0 && g[ss[k]][v] == 0) {
            bad[ss[k]] = true;
            --k;
        }
        if (k == -1)
            return false;
    }
    int root = ss.empty() ? v : ss[0];
    memset(v2, 0, sizeof(v2));
    if (get_cnt(root) + count(bad, bad + n, true) != n) {
        return false;
    }
    while (!ss.empty() && bad[ss.back()]) {
        all_bad[ss.back()] = true;
        ss.pop_back();
    }
    ss.push_back(v);
    vis[v] = true;
    return true;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        cin >> zip[i];
        o[i] = i;
    }
    sort(o, o + n, cmp);
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
    }
    ss.clear();
    string ans;
    memset(all_bad, 0, sizeof(all_bad));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int v = o[j];
            if (vis[v])
                continue;
            // if (i == n - 1) {
            //     for (int k = 0; k < n; ++k)
            //         printf("%d ", all_bad[k]);
            //     puts("");
            //     for (int k = 0; k < ss.size(); ++k)
            //         printf("%d ", ss[k]);
            //     puts("");
            //     output(v);
            // }
            if (check(v)) {
                ans += zip[v];
                break;
            }
        }
    }
    printf("Case #%d: ", ++t);
    cout << ans << endl;
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
