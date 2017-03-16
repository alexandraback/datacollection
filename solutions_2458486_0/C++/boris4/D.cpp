#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

const int MAX_N = 20;

int am[1 << MAX_N][MAX_N];
int nxt[1 << MAX_N];

int k;
int key[MAX_N];

int t[MAX_N];
int cnt[MAX_N];
int keys[MAX_N][MAX_N];

int tmp_key[201];
int tmp_keys[MAX_N][201];
int qq;
bool mark[201];
int mapsTo[201];

int main() {
    int tests;
    cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        int n; cin >> k >> n;
        memset(key, 0, sizeof(key));
        memset(tmp_key, 0, sizeof(tmp_key));
        for (int i = 0; i < k; ++i) {
            int t; cin >> t;
            --t;
            tmp_key[t]++;
        }
        qq = 0;
        memset(mark, 0, sizeof(mark));
        memset(keys, 0, sizeof(keys));
        memset(tmp_keys, 0, sizeof(tmp_keys));
        for (int i = 0; i < n; ++i) {
            cin >> t[i] >> cnt[i];
            --t[i];
            if (!mark[t[i]]) {
                mark[t[i]] = true;
                mapsTo[t[i]] = qq++;
            }
            for (int j = 0; j < cnt[i]; ++j) {
                int tmp; cin >> tmp;
                --tmp;
                tmp_keys[i][tmp]++;
            }
        }
        for (int i = 0; i <= 200; ++i)
            if (mark[i])
                key[mapsTo[i]] = tmp_key[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= 200; ++j)
                if (mark[j])
                    keys[i][mapsTo[j]] = tmp_keys[i][j];
        for (int i = 0; i < n; ++i)
            t[i] = mapsTo[t[i]];
        memset(am, 0, sizeof(am));
        for (int mask = 0; mask < 1 << n; ++mask) {
            if (mask == 0) {
                for (int j = 0; j < n; ++j)
                    am[mask][j] += key[j];
            } else {
                for (int i = 0; i < n; ++i)
                    if ((mask >> i) & 1) {
                        for (int j = 0; j < n; ++j)
                            am[mask][j] += am[mask ^ (1 << i)][j];
                        for (int j = 0; j < n; ++j)
                            am[mask][j] += keys[i][j];
                        am[mask][t[i]]--;
                        break;
                    }
            }
        }
        nxt[(1 << n) - 1] = -1;
        for (int mask = (1 << n) - 2; mask >= 0; --mask) {
            nxt[mask] = 987654321;
            for (int i = 0; i < n; ++i)
                if (!((mask >> i) & 1)) {
                    if (am[mask][t[i]] && nxt[mask ^ (1 << i)] != 987654321) {
                        nxt[mask] = i;
                        break;
                    }
                }
        }
        cout << "Case #" << test_id << ": ";
        if (nxt[0] == 987654321) cout << "IMPOSSIBLE" << endl;
        else {
            int cur = 0;
            cout << nxt[cur] + 1;
            cur = cur ^ (1 << nxt[cur]);
            while (cur != (1 << n) - 1) {
                cout << " " << nxt[cur] + 1;
                cur = cur ^ (1 << nxt[cur]);
            }
            cout << endl;
        }
    }
    return 0;
}
