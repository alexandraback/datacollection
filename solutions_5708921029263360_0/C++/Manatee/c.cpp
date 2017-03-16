#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long T, j, p, s, k;

map<pair<int, int>, int> jps, jss, pss;

vector<pair<int, pair<int, int>>> ans;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cout << "Case #" << tc + 1 << ": ";
        cin >> j >> p >> s >> k;

        for (int is = 0; is < s; ++is) {
            for (int ij = 0; ij < j; ++ij) {
                for (int ip = 0; ip < p; ++ip) {
                    auto jp = make_pair(ij, ip);
                    if (jps[jp] == k) continue;
                    auto js = make_pair(ij, is);
                    if (jss[js] == k) continue;
                    auto ps = make_pair(ip, is);
                    if (pss[ps] == k) continue;

                    ans.push_back(make_pair(ij, make_pair(ip, is)));
                    jps[jp] += 1;
                    jss[js] += 1;
                    pss[ps] += 1;
                }
            }
        }

        cout << ans.size() << endl;

        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].first + 1 << " "
                << ans[i].second.first + 1 << " "
                << ans[i].second.second + 1 << endl;

        }

        ans.clear();
        jps.clear();
        jss.clear();
        pss.clear();
    }
}