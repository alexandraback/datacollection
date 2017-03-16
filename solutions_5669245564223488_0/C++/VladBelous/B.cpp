#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

template<typename T> inline int sz(const T& x) { return (int)x.size(); }

int main() {
    int tc; cin >> tc;

    for(int t = 1; t <= tc; ++t) {
        int n; cin >> n;

        vector<string> cars(n);
        set<char> alpha;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> cars[i];
            for (int j = 0; j < sz(cars[i]); ++j) {
                alpha.insert(cars[i][j]);
            }
            a[i] = i;
        }

        int ans = 0;
        string train; train.reserve(128);
        int cnt = sz(alpha);
        do {
            train.clear();
            for (int i = 0; i < sz(cars); ++i) {
                train += cars[a[i]];
            }
            int len = unique(train.begin(), train.end()) - train.begin();
            if (len == cnt) ++ans;
        } while (next_permutation(a.begin(), a.end()));

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
