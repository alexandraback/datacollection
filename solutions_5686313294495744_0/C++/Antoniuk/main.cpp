//#include "testlib.h"
//#include <spoj.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <set>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
//#include <unordered_map>

using namespace std;

int n;
pair<string, string> th[1111];

int dp[1<<17];

int solve() {
    for(int i = 0; i < (1 << n); ++i)
        dp[i] = 99999;
    set< pair<int, int> > q;
    for(int i = 0; i < n; ++i) {
        q.insert(make_pair(1, (1<<i)));
        dp[1<<i] = 1;
    }

    while (!q.empty()) {
        int dd, nv, v = q.begin()->second;
        int d = q.begin()->first;
        q.erase(q.begin());

        if (dp[v] != d) continue;

        set<string> h1, h2;
        for(int i = 0; i < n; ++i)
        if ((v & (1 << i)))
            h1.insert(th[i].first), h2.insert(th[i].second);

        for(int i = 0; i < n; ++i)
        if ((v & (1 << i)) == 0) {
            nv = v | (1 << i);
            if (dp[nv] <= dp[v]) continue;

            dd = 1;
            if (h1.find(th[i].first) != h1.end() &&
                h2.find(th[i].second) != h2.end())
                dd = 0;


            if (dp[v] + dd < dp[nv]) {
                dp[nv] = dp[v] + dd;
                q.insert(make_pair(dp[nv], nv));
            }
        }
    }
    return n - dp[(1 << n)-1];
}

int main() {
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;
    for(int i = 0; i < tt; ++i) {
        cerr << i << "\n";
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> th[i].first >> th[i].second;

        cout << "Case #" << i+1 << ": ";
        cout << solve() << "\n";
    }

    return 0;
}
