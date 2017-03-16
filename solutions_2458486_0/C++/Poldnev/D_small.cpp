#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back

ifstream in("D-small-attempt0.in");
ofstream out("output.txt");

int main()
{
    int tests;
    in >> tests;
    for (int z = 0; z < tests; ++z) {
        int k, n;
        in >> k >> n;
        vector<int> init(k);
        for (int j = 0; j < k; ++j) {
            in >> init[j];
        }
        vector<int> t(n), qn(n);
        vector<vector<int>> q(n);
        for (int i = 0; i < n; ++i) {
            in >> t[i];
            in >> qn[i];
            for (int j = 0; j < qn[i]; ++j) {
                int x;
                in >> x;
                q[i].pb(x);
            }
        }

        int M = 1 << n;
        vector<vector<int>> ans(M);
        for (int mask = (1 << n) - 2; mask >= 0; --mask) {
            ans[mask] = {-1};
            map<int, int> c;
            for (int x : init) {
                ++c[x];
            }
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    --c[t[i]];
                    for (int x : q[i]) {
                        ++c[x];
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0 && c[t[i]] > 0) {
                    const vector<int> &there = ans[mask + (1 << i)];
                    if (there.size() == 1 && there[0] == -1) {
                        continue;
                    }
                    ans[mask] = {i + 1};
                    ans[mask].insert(ans[mask].end(), there.begin(), there.end());
                    break;
                }
            }
        }

        const vector<int> &res = ans[0];
        out << "Case #" << z + 1 << ": ";
        if (res.size() == 1 && res[0] == -1) {
            out << "IMPOSSIBLE";
        } else {
            for (int x : res) {
                out << x << " ";
            }
        }
        out << endl;
    }

    return 0;
}
