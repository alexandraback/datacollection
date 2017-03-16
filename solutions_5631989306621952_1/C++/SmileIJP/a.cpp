#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <sstream>

typedef long long ll;

using namespace std;

template<typename T>
T next() { T tmp; cin >> tmp; return tmp; }

void solve() {
    string s = next< string >();
    vector< char > mx(s.size());
    mx[0] = s[0];
    for (size_t i = 1; i < s.size(); ++i) {
        mx[i] = max(mx[i - 1], s[i]);
    }
    stringstream left, right;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (mx[i] == s[i]) {
            left << s[i];
        } else {
            right << s[i];
        }
    }
    cout << left.str();
    string rest =  right.str();
    reverse(rest.begin(), rest.end());
    cout << rest << endl;
}

int main() {
    int n = next< int >();
    for (int i = 1; i <= n; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
