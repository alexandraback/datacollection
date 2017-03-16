#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int f[10];
string zip[10];
int g[10][10];
vector<int> stack;

int main() {
    int tests; cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        printf("Case #%d: ", test_id);
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> zip[i];
        memset(g, 0, sizeof(g));
        for (int i = 0; i < n; ++i) f[i] = i;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            g[a][b] = g[b][a] = 1;
        }
        bool r = false;
        string res;
        do {
            int p = 0;
            bool ok = true;
            string cur = zip[f[0]];
            stack.clear();
            stack.push_back(f[0]);
            for (int i = 1; i < n; ++i) {
                cur += zip[f[i]];
                while (p >= 0 && !g[stack[p]][f[i]]) { --p; stack.pop_back(); }
                if (p == -1) ok = false;
                stack.push_back(f[i]);
                p++;
            }
            if (ok) {
                if (r) res = min(res, cur);
                else res = cur, r = true;
            }
        } while (next_permutation(f, f + n));
        cout << res << endl;
    }
    return 0;
}