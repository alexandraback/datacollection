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
template <class T> ostream & operator << (ostream & out, vector<T> const & a) { bool i = false; for (T const & it : a) { if (i) out << ' '; else i = true; out << it; } return out; }
void solve() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    int ln = 0, rn = 0; {
        map<string,int> dict_l, dict_r;
        repeat (i,n) {
            string s, t; cin >> s >> t;
            if (not dict_l.count(s)) dict_l[s] = ln ++;
            if (not dict_r.count(t)) dict_r[t] = rn ++;
            l[i] = dict_l[s];
            r[i] = dict_r[t];
        }
    }
    int ans = 0;
    repeat (s,1<<n) {
        vector<bool> is_fake(n); repeat (i,n) is_fake[i] = s & (1 << i);
        vector<bool> exists_l(ln);
        vector<bool> exists_r(rn);
        repeat (i,n) if (not is_fake[i]) {
            exists_l[l[i]] = true;
            exists_r[r[i]] = true;
        }
        bool valid = true;
        repeat (i,n) if (is_fake[i]) {
            if (not exists_l[l[i]] or not exists_r[r[i]]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            setmax(ans, __builtin_popcount(s));
        }
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    repeat (i,t) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
