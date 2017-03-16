#include <algorithm>
#include <iostream>
#include <valarray>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (int i = (a); i < int(n); ++i)
#define error(x) cout << #x << " = " << (x) << endl;
#define all(n) (n).begin(), (n).end()
#define Size(n) ((int)(n).size())
#define mk make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class P, class Q> void smin(P &a, Q b) { if (b < a) a = b; }
template <class P, class Q> void smax(P &a, Q b) { if (b > a) a = b; }
template <class P, class Q> bool in(const P &a, const Q &b) { return a.find(b) != a.end(); }

pair<string, string> solve(string first, string second) {
  int n = first.size();
  vector<pair<int, pair<string, string> > > results;
  int z = count(all(first), '?') + count(all(second), '?');
  int lim = 1;
  FOR(i, 0, z) {
    lim *= 10;
  }
  FOR(mask, 0, lim) {
    int m = mask;
    string a = first;
    string b = second;
    FOR(i, 0, Size(a)) if (a[i] == '?') { a[i] = '0' + m % 10; m /= 10; }
    FOR(i, 0, Size(b)) if (b[i] == '?') { b[i] = '0' + m % 10; m /= 10; }
    int ia, ib;
    istringstream sin(a + " " + b);
    sin >> ia >> ib;
    int d = abs(ia - ib);
    results.pb(mk(d, mk(a, b)));
  }
  sort(all(results));
  first = results[0].second.first;
  second = results[0].second.second;
  return mk(first, second);
}

int main() {
  int t;
  cin >> t;
  FOR(test_number, 1, t + 1) {
    string first, second;
    cin >> first >> second;
    pair<string, string> result = solve(first, second);
    cout << "Case #" << test_number << ": " << result.first << " " << result.second << endl;
  }
	return 0;
}
