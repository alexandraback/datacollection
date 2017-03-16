#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

template < typename T > T next() { T tmp; cin >> tmp; return tmp; }
typedef long long ll;

int m[8][8] = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {1, 4, 3, 6, 5, 0, 7, 2},
    {2, 7, 4, 1, 6, 3, 0, 5},
    {3, 2, 5, 4, 7, 6, 1, 0},
    {4, 5, 6, 7, 0, 1, 2, 3},
    {5, 0, 7, 2, 1, 4, 3, 6},
    {6, 3, 0, 5, 2, 7, 4, 1},
    {7, 6, 1, 0, 3, 2, 5, 4}
};

int num[256];

void solve() {
    int l = next< int >();
    ll x = next< ll >();
    string inp = next< string >();

    int val = 0;
    for (size_t i = 0; i < inp.size(); ++i) {
        val = m[val][num[inp[i]]];
    }
    int tmp = 0;
    for (int i = 0; i < x % 4; ++i) {
        tmp = m[tmp][val];
    }
    
    if (tmp != 4) {
        cout << "NO" << endl; return;
    }
    ll left = 0;
    int lv = 0;
    for (; left < x * l && left < 5 * l; ++left) {
        lv = m[lv][ num[inp[left % l]] ];
        if (lv == 1) {
            break;
        }
    }
    ll right = x * l - 1;
    int rv = 0;
    for (; right >= 0 && x * l - right < 5 * l; --right) {
        rv = m[ num[inp[right % l]] ][rv];
        if (rv == 3) {
            break;
        }
    }
    if (lv != 1 || rv != 3 || left >= right) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    num['i'] = 1;
    num['j'] = 2;
    num['k'] = 3;

    int t = next< int >();
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
