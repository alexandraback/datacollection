#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
typedef long long ll;
using namespace std;
using namespace boost;
int dfs(string & t, string const & k, string const & l, int s, int & m, int & n) {
    if (t.size() == s) {
        int result = 0;
        for (int i : irange<int>(0,s-l.size()+1)) {
            if (t.substr(i,l.size()) == l) result += 1;
        }
        m = max(m, result);
        n += 1;
        return result;
    } else {
        int result = 0;
        for (char c : k) {
            t += c;
            result += dfs(t, k, l, s, m, n);
            t.pop_back();
        }
        return result;
    }
}
double solve(string const & k, string const & l, int s) {
    assert (k.size() <= 7 and l.size() <= s and s <= 7);
    int m = 0, n = 0;
    string t = "";
    int a = dfs(t,k,l,s,m,n);
    if (m == 0) return 0;
    return m - a /(double) n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout << setprecision(10);
    int t; cin >> t;
    for (int i : irange(0, t)) {
        int kl, ll, s; string k, l; cin >> kl >> ll >> s >> k >> l;
        assert (kl == k.length());
        assert (ll == l.length());
        // cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": " << solve(k,l,s) << endl;
    }
    return 0;
}
