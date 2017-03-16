
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define MAXN 1000

using namespace std;

int n;
int f[MAXN];
bool vis[MAXN];
vector <int> path[MAXN];

int solve_naive() {
    for (int k = n; k > 1; k--) {
        vector <int> ord(n);
        for (int i = 0; i < n; i++)
            ord[i] = i;
        do {
            bool valid = true;
            for (int i = 0; i < k; i++) {
                int i0 = ord[i];
                int i1 = ord[(i + 1) % k];
                int i2 = ord[(i - 1 + k) % k];
                if (f[i0] != i1 && f[i0] != i2) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return k;
        } while (next_permutation(ord.begin(), ord.end()));
    }
    return 1;
}

int solve() {
    int longest = 1;
    map <int, vector <pair <int, int>>> disjoint;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            vis[j] = false;
        path[i].clear();
        int cur = i;
        int len = 0;
        while (true) {
            if (vis[cur]) {
                // valid iff next is first or prv visited
                if (cur == i)
                    longest = max(longest, len);
                if (cur == f[f[cur]]) {
                    int f_end = min(f[cur], cur);
                    disjoint[f_end].push_back({len, i});
                    // cerr << "disjoint " << f_end << " " << len << endl;
                }
                break;
            }
            path[i].push_back(cur);
            vis[cur] = true;
            cur = f[cur];
            len++;
        }
    }
    int disjoint_total = 0;
    for (auto &kv : disjoint) {
        vector <pair <int, int>> lens = kv.second;
        sort(lens.begin(), lens.end());
        reverse(lens.begin(), lens.end());
        disjoint_total += lens[0].first;
        cerr << "disjoint " << lens[0].first << " " << lens[0].second << endl;

        int i = lens[0].second;
        if (lens.size() > 1 && path[i].size() > 2) {
            for (int j = 1; j < lens.size(); j++) {
                int k = lens[j].second;
                if (path[k].back() == path[i].back())
                    continue;
                disjoint_total += lens[j].first - 2;
                cerr << "disjoint2 " << lens[j].first << " " << lens[j].second << endl;
                break;
            }
        }
    }

    return max(longest, disjoint_total);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> f[i];
            f[i]--;
        }
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
