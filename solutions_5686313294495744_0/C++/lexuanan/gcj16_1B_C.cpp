#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<pair<string,string>> ds;
vector<int> ad1[N], ad2[N];
bool mark[N];

int main() {
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        int n;
        cin >> n;

        ds.clear();
        /*
        cnt.clear();
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            cnt[s2]++;
            if (ds.count(s1) == 0) ds[s1] = vector<string>();
            ds[s1].push_back(s2);
        }
        for (auto s1 : ds) {
            bool ok = false;
            int dem = 0;
            for (auto s2 : s1->second) {
                if (cnt[s2] == 1) {
                    ok = true;
                }
                else dem++;
            }
        }
        */

        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            ds.push_back({s1,s2});
        }
        for (int i = 0; i < n; i++) {
            ad1[i].clear();
            ad2[i].clear();
            for (int j = 0; j < n; j++)
                if (j != i) {
                    if (ds[i].first.compare(ds[j].first) == 0) {
                        ad1[i].push_back(j);
                    }
                    if (ds[i].second.compare(ds[j].second) == 0) {
                        ad2[i].push_back(j);
                    }
                }
        }
        int ans = 0;
        int mm = 1 << n;
        for (int i = 1; i < mm; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) {
                    mark[j] = true;
                }
                else {
                    mark[j] = false;
                    tmp++;
                }
            if (tmp <= ans) continue;
            bool ok = true;
            for (int j = 0; j < n; j++)
                if (mark[j] == false) {
                    ok = false;
                    for (auto z : ad1[j])
                        if (mark[z]) {
                            ok = true; break;
                        }
                    if (!ok) break;
                    ok = false;
                    for (auto z : ad2[j])
                        if (mark[z]) {
                            ok = true;
                            break;
                        }
                    if (!ok) break;
                }
            if (ok) ans = max(ans, tmp);
        }
        cout << "Case #" << nt << ": " << ans << '\n';
    }
    return 0;
}
