#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string.h>
#include <queue>
#include <cstdio>
#include <cassert>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define forv(i, v) forn(i, v.size())

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll p10[16];

template<typename T>
string toString(T t) {
    ostringstream out;
    out << t;
    return out.str();
}

template<typename T>
T fromString(string s) {
    T t;
    istringstream in(s);
    in >> t;
    return t;
}

int solveBfs(ll n) {
    queue<ll> q;
    map<ll, int> d;
    q.push(1);
    d[1] = 1;
    while (!q.empty() && d.count(n) == 0) {
        ll x = q.front(); q.pop();
        if (x + 1 <= 1e6 && d.count(x + 1) == 0) {
            d[x + 1] = d[x] + 1;
            q.push(x + 1);
        }
        string str = toString<ll>(x);
        reverse(all(str));
        ll y = fromString<ll>(str);
        if (y <= 1e6 && d.count(y) == 0) {
            d[y] = d[x] + 1;
            q.push(y);
        }
    }
    return d[n];
}

void solveCase(int tc) {
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    ll n;
    cin >> n;
    string str = toString<ll>(n);
    ll cnt = 1;
    for (int k = 0; k < (int)str.size() - 1; k++) {
        int t = (k + 1) / 2;
        cnt += p10[t] - 1 + p10[k + 1 - t] - 1;
        if (k) cnt++;
    }
    ll cur = p10[str.size() - 1];
    ll ans = cnt + n - cur;
//    cerr << cnt << " " << cur << " " << ans << endl;

    //ll bfs = solveBfs(n);
    if (n == cur) {
        //assert(ans == bfs);
        cout << ans << endl;
        return;
    }
    if (n % 10 == 0) {
        n--;
        str = toString<ll>(n);
        cnt++;
    }
    for (int p = 1; p <= (int)str.size(); p++) {
        string s = str.substr(0, p);
        reverse(all(s));
        while (s.size() + 1 < str.size()) s = "0" + s;
        if (s.size() < str.size()) s = "1" + s;
        ll add = fromString<ll>(s) - cur;
        if (add < 0) throw;
        reverse(all(s));
        if (n - fromString<ll>(s) < 0) throw;
        ans = min(ans, cnt + 1 + add + n - fromString<ll>(s));
    }
    /*if (ans != bfs) {
        cerr << "Error" << endl;
        cerr << n << " " << ans << " " << bfs << endl;
        exit(0);
    }*/
    cout << ans << endl;
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    p10[0] = 1;
    for (int i = 1; i < 16; i++) p10[i] = p10[i - 1] * 10;
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
