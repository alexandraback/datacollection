#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cstdio>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i,m,n) for (int i = (n)-1; (i) >= (m); --(i))
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
typedef long long ll;
template <class T> bool setmax(T & l, T const & r) { if (not (l < r)) return false; l = r; return true; }
template <class T> bool setmin(T & l, T const & r) { if (not (r < l)) return false; l = r; return true; }
using namespace std;
template <class T> ostream & operator , (ostream & out, T a) { return out << a; }
#define endl "\n"
template <class T>
using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T> istream & operator >> (istream & in, vector<T> & a) { for (T & it : a) in >> it; return in; }
void enumerate(int i, string const & s, ll acc, function<void (ll)> cont) {
    int n = s.length();
    if (i < n) {
        if (s[i] == '?') {
            repeat (j,10) {
                enumerate(i+1, s, acc * 10 + j, cont);
            }
        } else {
            enumerate(i+1, s, acc * 10 + (s[i] - '0'), cont);
        }
    } else {
        cont(acc);
    }
}
string zfill(string const & s, int n) {
    string t(n - s.length(), '0');
    return t + s;
}
void solve() {
    string s, t; cin >> s >> t;
    int n = s.length();
    auto ans = make_tuple<ll,ll,ll>(1e18+9, -1, -1);
    enumerate(0, s, 0, [&](ll a) {
        enumerate(0, t, 0, [&](ll b) {
            auto key = make_tuple(llabs(a - b), a, b);
            setmin(ans, key);
        });
    });
    cout << zfill(to_string(get<1>(ans)), n) << ' ' << zfill(to_string(get<2>(ans)), n) << endl;
}
int main() {
    int t; cin >> t;
    repeat (i,t) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
