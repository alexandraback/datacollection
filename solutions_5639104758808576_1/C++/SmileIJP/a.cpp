#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

template < typename T > T next() { T tmp; cin >> tmp; return tmp; }

void solve() {
    int smax = next< int >();
    string s = next< string >();
    int ans = 0;
    int cnt = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        cnt += s[i] - '0';
        if (cnt == 0) {
            ans++;
            cnt++;
        }
        cnt--;
    }
    cout << ans << endl;
}

int main() {
    int t = next< int >();
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
