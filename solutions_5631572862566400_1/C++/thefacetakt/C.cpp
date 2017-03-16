#include "bits/stdc++.h"

using namespace std;

struct Sol {
    vector <set<int> > in;
    vector <int> out;
    vector <bool> used;
    vector <int> colors;
    vector <int> colcou;

    int findChain(int v, int w) {
        int ans = 1;
        for (auto const &u: in[v]) {
            if (u != w) {
                ans = max(ans, findChain(u, -1) + 1);
            }
        }
        return ans;
    }

    void dfs(int v, int c) {
        colors[v] = c;
        colcou[c]++;
        if (colors[out[v]] == 0) {
            dfs(out[v], c);
        }
    }

    int main() {
        int n;
        scanf("%d", &n);
        in.resize(n), out.resize(n);
        vector <int> cur(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &out[i]);
            --out[i];
            in[out[i]].insert(i);
            ++cur[out[i]];
        }
        used.assign(n, 0);
        int currentAnswer = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && !used[out[i]]
                && in[i].find(out[i]) != in[i].end()) {
                used[i] = used[out[i]] = true;
                currentAnswer += findChain(i, out[i]) + findChain(out[i], i);
            }
        }
        set<pair<int, int> > cycleFinding;


        for (int i = 0; i < n; ++i) {
            cycleFinding.insert(make_pair(cur[i], i));
        }
        while (cycleFinding.size()) {
            auto v = cycleFinding.begin();
            if (v->first > 0) {
                break;
            }
            int i = v->second;
            cycleFinding.erase(v);
            cycleFinding.erase(make_pair(cur[out[i]], out[i]));
            --cur[out[i]];
            cycleFinding.insert(make_pair(cur[out[i]], out[i]));
        }
        vector <bool> inCycle(n, 0);
        for (auto const &v: cycleFinding) {
            inCycle[v.second] = true;
        }
        colors.assign(n, 0);
        colcou.assign(n + 1, 0);
        int cc = 1;
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0 && inCycle[i]) {
                dfs(i, cc);
                ++cc;
            }
        }
        int secondAnswer = 0;
        for (int i = 0; i <= n; ++i) {
            secondAnswer = max(secondAnswer, colcou[i]);
        }
        return max(secondAnswer, currentAnswer);
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int z = 1; z <= T; ++z) {
        printf("Case #%d: %d\n", z, Sol().main());
    }
}
