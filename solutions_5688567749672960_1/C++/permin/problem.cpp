#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <valarray>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL_RUN
#define debug(x) cerr << #x << ": "  << (x) << "\n";
#else
#define debug(x) ;
#endif

#define all(v) (v).begin(), (v).end()
#define MP make_pair

template<class T>
class IsIterable__ {static void f(...); template<class U> static typename U::const_iterator f(const U&);
public:const static bool value = !std::is_same<void, decltype(f(std::declval<T>()))>::value;};

template <class F, class S> ostream& operator << (ostream& o, const pair<F,S>& p) {
return o << "(" << p.first << ", " << p.second << ")";}

template<class C>void O__(ostream& o, const C& c) {
bool f = 1; for(const auto& x: c) {if (!f) o << ", "; if (IsIterable__<decltype(x)>::value) o << "\n"; f = 0; o << x;}}

template <class T>
ostream& operator << (ostream& o, const vector<T>& v) {o << "[";O__(o, v);o << "]";return o;}

template <class T, class V>
ostream& operator << (ostream& o, const map<T, V>& v) {o << "{";O__(o, v);o << "}"; return o;}

template <class T>
ostream& operator << (ostream& o, const set<T>& v) {o << "{";O__(o, v);o << "}";return o;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

#if GCC_VERSION > 40900
// supports find_by_order(int) and order_of_key(Key)
template<class Key, class Value>
using MapWithOrderStatistics = tree<Key, Value,
      std::less<Key>, rb_tree_tag /*splay_tree_tag*/,
      tree_order_statistics_node_update>;
#endif

string toStr(ll n) {
    stringstream o;
    o << n;
    string s;
    o >> s;
    return s;
}

ll toInt(const string& s) {
    ll n;
    stringstream o2;
    o2 << s;
    o2 >> n;
    return n;
}

ll rev(ll n) {
    string s = toStr(n);
    reverse(all(s));
    return toInt(s);
}

ll p10(int k);
ll solve2(ll n);

void solve() {
    ll n;
    cin >> n;
    //int k;
    //cin >> k;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    std::map<ll, ll> dist;
    std::map<ll, ll> prev;
    dist[1] = 1;
    queue<ll> Q;
    Q.push(1);
    while(!Q.empty()) {
        ll v = Q.front();
        Q.pop();
        for (ll v2: {v + 1, rev(v)}) {
            if (v2 <= v)
                continue;
            if (dist.count(v2) > 0)
                continue;
            dist[v2] = dist[v] + 1;
            prev[v2] = v;
            if (v2 == n) {
                ll x = n;
                std::vector<ll> path;
                while(x!=1) {
                    path.push_back(x);
                    x = prev[x];
                }
                reverse(all(path));
                debug(path);
                cout << dist[n] << "\n";
                debug(min(solve2(n-1) + 1, solve2(n)));
                return;
            }
            Q.push(v2);
        }
    }
}

ll p10(int k) {
    if (k == 1)
        return 10;
    ll res = p10(size_t(k - 1));

    ll x = 1;
    for (int i = 0; i < (k+1)/2; ++i) {
        x *= 10;
    }
    res += x - 1;
    res += 1;
    ll y = 1;
    for (int i = 0; i < (k)/2; ++i) {
        y *= 10;
    }
    res += y - 1;
    return res;
}

ll solve2(ll n) {
    if (n <= 10) {
        return n;
    }
    string s = toStr(n);
    ll res = 0;
    res += p10(int(s.size()) - 1);

    ll z10 = 1;
    for (size_t i = 0; i + 1 < s.size(); ++i) {
        z10*=10;
    }
    debug(n);
    debug(z10);
    debug(res);
    ll add = n - z10;

    for (size_t i = 1; i < s.size(); ++i) {
        string left = s.substr(0, i);
        string right = s.substr(i, s.size() - i);
        ll cur = 0;
        reverse(all(left));
        ll x = toInt(left);
        cur += x;
        ll y = toInt(s.substr(i, s.size() - i));
        if (y < 1)
            continue;
        cur += y - 1;
        add = min(cur+1, add);
    }
    return add + res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    debug(rev(123));
    assert(rev(12340) == 4321);
    size_t tests;
    cin >> tests;
    for (size_t t = 0; t < tests; ++t) {
        cout << "Case #" << t + 1 << ": ";
        ll n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
        } else {
            cout << min(solve2(n), 1+ solve2(n-1)) << "\n";
        }
    }
    return 0;
}
