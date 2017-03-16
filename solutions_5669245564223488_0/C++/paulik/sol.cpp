#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

int n;
vector<int> next, prev;
vector<int> insides;
vector<int> weights;
vector<int> visited;

LL fact(int n) {
    LL result = 1;
    for (int i = 2; i <= n; ++i)
        result = (result * i) % MOD;
    return result;
}

bool dfs(int v, int pr = -1) {
    if (!v) return true;
    if (visited[v] == 1) return false;
    visited[v] = 1;
    bool ret = true;
    if (next[v] != pr) ret = ret && dfs(next[v], v);
    if (prev[v] != pr) ret = ret && dfs(prev[v], v);
    return ret;
}

LL solve() {
    cin >> n;
    next.assign(256, 0);
    prev.assign(256, 0);
    insides.assign(256, 0);
    weights.assign(256, 0);

    bool bad = false;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;

        vector<char> chars;
        chars.push_back(str[0]);
        for (size_t i = 1; i < str.size(); ++i)
            if (str[i] != str[i - 1])
                chars.push_back(str[i]);
        if (chars.size() == 1)
            ++weights[(unsigned)chars[0]];
        for (size_t i = 1; i + 1 < chars.size(); ++i)
            ++insides[(unsigned)chars[i]];
        if (chars.size() > 1) {
            unsigned fr = (unsigned)chars.front(), back = (unsigned)chars.back();
            if (next[fr] || prev[back])
                bad = true;
            next[fr] = back;
            prev[back] = fr;
        }
    }
    if (bad)
        return 0;

    for (int i = 0; i < 256; ++i)
        if (insides[i] > 1 || (insides[i] && (next[i] || prev[i] || weights[i])))
            return 0;

    LL result = 1;
    for (int i = 0; i < 256; ++i)
        result = (result * fact(weights[i])) % MOD;

    int comps = 0;
    visited.assign(256, -1);
    for (int i = 0; i < 256; ++i) {
        if (visited[i] == 1) continue;
        if (insides[i]) continue;
        if (!next[i] && !prev[i]) {
            if (weights[i])
                ++comps;
            continue;
        }
        if (!dfs(i))
            return 0;
        ++comps;
    }
    result = (result * fact(comps)) % MOD;

    return result;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}

