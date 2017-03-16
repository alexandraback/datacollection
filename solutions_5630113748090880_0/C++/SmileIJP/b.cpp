#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>

typedef long long ll;

using namespace std;

template<typename T>
T next() { T tmp; cin >> tmp; return tmp; }

void solve() {
    int n = next< int >();
    map< int, int > cnt; 
    for (int i = 0; i < n * (2 * n - 1); ++i) {
        cnt[ next< int >() ]++;
    }
    vector< int > ans;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if (it -> second % 2 == 1) {
            ans.push_back(it -> first);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int n = next< int >();
    for (int i = 1; i <= n; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
