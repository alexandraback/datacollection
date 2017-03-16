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

ll minimum_difference_greedy(string first, string second) {
  enum { EQ, LT, GT };
  int state = EQ;
  int n = first.size();
  FOR(i, 0, n) {
    char a = first[i];
    char b = second[i];
    if (state == EQ) {
      if (a == '?') {
        if (b == '?') {
          a = b = '0';
        } else {
          a = b;
        }
      } else if (b == '?') {
        b = a;
      } else {
        if (a < b) {
          state = LT;
        } else if (b < a) {
          state = GT;
        }
      }
    } else if (state == LT) {
      a = a == '?' ? '9' : a;
      b = b == '?' ? '0' : b;
    } else if (state == GT) {
      a = a == '?' ? '0' : a;
      b = b == '?' ? '9' : b;
    }
    first[i] = a;
    second[i] = b;
  }
  istringstream sin(first + " " + second);
  ll a, b;
  sin >> a >> b;
  return a > b ? a - b : b - a;
}

ll minimum_difference(string first, string second) {
  int n = first.size();
  vector<ll> results;
  FOR(i, 0, n) {
    char a = first[i];
    char b = second[i];
    int min_a = a == '?' ? '0' : a;
    int max_a = a == '?' ? '9' : a;
    FOR(new_a, min_a, max_a + 1) {
      int min_b = b == '?' ? '0' : b;
      int max_b = b == '?' ? '9' : b;
      FOR(new_b, min_b, max_b + 1) {
        first[i] = new_a;
        second[i] = new_b;
        ll distance = minimum_difference_greedy(first, second);
        results.pb(distance);
      }
    }
    first[i] = a;
    second[i] = b;
  }
  sort(all(results));
  return results[0];
}

pair<string, string> solve(string first, string second) {
  int n = first.size();
  FOR(i, 0, n) {
    vector<pair<ll, pair<string, string> > > results;
    char a = first[i];
    char b = second[i];
    int min_a = a == '?' ? '0' : a;
    int max_a = a == '?' ? '9' : a;
    FOR(new_a, min_a, max_a + 1) {
      int min_b = b == '?' ? '0' : b;
      int max_b = b == '?' ? '9' : b;
      FOR(new_b, min_b, max_b + 1) {
        first[i] = new_a;
        second[i] = new_b;
        ll distance = minimum_difference(first, second);
        results.pb(mk(distance, mk(first, second)));
      }
    }
    sort(all(results));
    first = results[0].second.first;
    second = results[0].second.second;
  }
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
