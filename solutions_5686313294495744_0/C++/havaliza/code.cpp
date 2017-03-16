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

int maximum_cheaters(vector<pair<string, string> > topics) {
  int n = topics.size();
  int result = 0;
  FOR(mask, 0, 1 << n) {
    set<string> firsts, seconds;
    bool ok = true;
    FOR(i, 0, n) {
      string first = topics[i].first;
      string second = topics[i].second;
      if (!(mask & (1 << i))) {
        firsts.insert(first);
        seconds.insert(second);              
      }
    }
    FOR(i, 0, n) {
      string first = topics[i].first;
      string second = topics[i].second;
      if (mask & (1 << i)) {
        if (!in(firsts, first) || !in(seconds, second)) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      result = max(result, __builtin_popcount(mask));
    }
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  FOR(test_number, 1, t + 1) {
    int n;
    vector<pair<string, string> > topics;
    cin >> n;
    FOR(i, 0, n) {
      string first, second;
      cin >> first >> second;
      topics.pb(mk(first, second));
    }
    cout << "Case #" << test_number << ": " << maximum_cheaters(topics) << endl;
  }
	return 0;
}
