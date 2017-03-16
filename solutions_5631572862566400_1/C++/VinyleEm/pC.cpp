#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <utility>

#include "common.h"

using namespace std;

int getCircleSize(int fst, vector<int>& bff)
{
    const size_t n = bff.size();
    vector<bool> seen(n, false);

    int cur, cnt = 0;
    for (cur = fst;!seen[cur];cur = bff[cur]) {
        seen[cur] = true;
        cnt++;
        if (cnt > 1 and cur == fst) {
            return cnt;
        }
    }

    return cur == fst ? cnt : -1;
}

int main(int argc, char **argv) {

    int T;
    cin >> T;

    for (int tno = 1;tno <= T; tno++) {
        int n;
        cin >> n;
        vector<int> bff(n);
        for (auto& f: bff) {
            cin >> f;
            f--;
        }

        vector<vector<int> > rbff(n);
        for (int i = 0;i < n; ++i)
            if (bff[bff[i]] != i)
                rbff[bff[i]].push_back(i);

        int ret = 0;
        set<int> pairs;

        for (int i = 0;i < n; ++i) {
            int csize = getCircleSize(i, bff);
            ret = max(ret, csize);
            int a = i, b = bff[i];
            if (bff[b] == a) {
                pairs.insert(a);
                pairs.insert(b);
            }
        }

        int ret2 = 0;
        vector<int> dp(n, -1);

        function<int(int)> f = [&](int x) -> int {
            if (dp[x] >= 0)
                return dp[x];
            int ret = 1;
            for (auto r: rbff[x])
                ret = max(ret, 1 + f(r));
            return dp[x] = ret;
        };

        for (int i = 0;i < n; ++i)
            if (pairs.count(i))
                ret2 += f(i);

        ret = max(ret, ret2);

        cout << "Case #" << tno << ": " << ret << endl;
    }

    return 0;
}
