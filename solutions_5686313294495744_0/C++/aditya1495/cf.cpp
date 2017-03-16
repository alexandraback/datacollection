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
        for (int i = 0; i < N; ++i) {
            cin >> s >> t;
            a.push_back(PII(c(s), c(t)));
        }
        int res = N;
        for (int i = 0; i < (1 << N); ++i) {
            set<int> f, l;
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (i & (1 << j)) {
                    ++cnt;
                    f.insert(a[j].first);
                    l.insert(a[j].second);
                }
            }
            bool ok = 1;
            for (int j = 0; j < N; ++j) {
                if (!(i & (1 << j))) {
                    if (f.find(a[j].first) == f.end()) ok = 0;
                    if (l.find(a[j].second) == l.end()) ok = 0;
                }
            }
            if (ok) res = min(res, cnt);
        }
        cout << (N - res) << "\n";
    }
    return 0;
}