#include <cassert>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 22;

int k, n, t[kMaxN], st[kMaxN];
vector<int> keys[kMaxN], init;
bool f[1 << kMaxN];

bool test(int msk, int cnt) {
    if (f[msk])
        return false;
    if (msk == (1 << n) - 1) {
        for (int i = 0; i < n; ++i)
            printf(" %d", st[i]);
        printf("\n");
        return true;
    }
    f[msk] = true;

    map<int, int> keyCnt;
    for (int i = 0; i < n; ++i)
        if ((1 << i) & msk) {
            for (int j = 0; j < keys[i].size(); ++j)
                keyCnt[keys[i][j]]++;
            keyCnt[t[i]]--;
        }
    for (int i = 0; i < init.size(); ++i)
        keyCnt[init[i]]++;
    for (int i = 0; i < n; ++i)
        if (((1 << i) & msk) == 0 && keyCnt[t[i]] > 0) {
            st[cnt] = i + 1;
            if (test(msk | (1 << i), cnt + 1))
                return true;
        }
    return false;
}

void solve() {
    fill(f, f + (1 << n), false);
    if (!test(0, 0))
        printf(" IMPOSSIBLE\n");
}

int main() {
    int numOfCases;
    cin >> numOfCases;
    for (int caseNo = 1; caseNo <= numOfCases; ++caseNo) {
        cin >> k >> n;
        init.clear();
        for (int i = 0; i < k; ++i) {
            int type;
            cin >> type;
            init.push_back(type);
        }
        for (int i = 0; i < n; ++i) {
            int cnt;
            cin >> t[i] >> cnt;
            keys[i].clear();
            for (int j = 0; j < cnt; ++j) {
                int type;
                cin >> type;
                keys[i].push_back(type);
            }
        }
        printf("Case #%d:", caseNo);
        solve();
    }
    return 0;
}
