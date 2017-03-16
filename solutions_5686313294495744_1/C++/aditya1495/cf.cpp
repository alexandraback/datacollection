#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;

#define all(X) (X).begin(), (X).end()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

const int mod = 1e9 + 7;
const int maxn = 100001;

map<string, int> M;
int dis;

int c(const string &s) {
    if (M.find(s) != M.end()) return M[s];
    return (M[s] = dis++);
}

int main() {
    int T, N;
    string s, t;
    cin >> T;
    for (int _test = 1; _test <= T; ++_test) {
        cout << "Case #" << _test << ": ";
        cerr << "On test:" << _test << "\n";
        cin >> N;
        M.clear();
        dis = 0;
        vector<PII> a;
        set<int> f, l;
        for (int i = 0; i < N; ++i) {
            cin >> s >> t;
            a.push_back(PII(c(s), c(t)));
            f.insert(a[i].first);
            l.insert(a[i].second);
        }
        int tot = f.size() + l.size();
        VVI w(tot, VI(tot, 0));
        VI mr, mc;
        for (int i = 0; i < N; ++i) {
            w[a[i].first][a[i].second] = 1;
        }
        int res = tot - BipartiteMatching(w, mr, mc);
        cout << (N - res) << "\n";
    }
    return 0;
}