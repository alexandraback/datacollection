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
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
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
namespace mp = boost::multiprecision;
void solve() {
    random_device device;
    default_random_engine gen(device());
    uniform_int_distribution<int> dist(0,1); // bool
    int n, j; cin >> n >> j;
    set<string> used;
    while (used.size() < j) {
        string s; s += '1'; repeat (i,n-2) s += dist(gen) + '0'; s += '1';
        if (used.count(s)) continue;
        vector<ll> witnesses;
        repeat_from (base,2,10+1) {
            mp::cpp_int p = 0;
            repeat (i,n) {
                p *= base;
                if (s[i] == '1') p += 1;
            }
            repeat_from (i,2,10000) {
                if (p % i == 0) {
                    witnesses.push_back(i);
                    goto next;
                }
            }
            break;
next:;
        }
        if (witnesses.size() == 9) {
            cout << s;
            for (ll it : witnesses) cout << ' ' << it;
            cout << endl;
            used.insert(s);
        }
    }
}
int main() {
    int t; cin >> t;
    repeat (i,t) {
        cout << "Case #" << i+1 << ":" << endl;
        solve();
    }
    return 0;
}
