#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "A"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

ll gcd(ll a, ll b) {
  if (!b) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    string input;
    cin >> input;
    replace(input.begin(), input.end(), '/', ' ');
    istringstream in(input);
    ll A, B;
    in >> A >> B;
    ll g = gcd(A, B);
    A /= g;
    B /= g;
    cerr << A << ' ' << B << endl;
    cout << "Case #" << (test_index + 1) << ": ";
    int pow2b = 0;
    ll B_copy = B;
    while (B_copy > 1) {
      if (B_copy % 2) {
        pow2b = -1;
        break;
      } else {
        B_copy /= 2;
        pow2b++;
      }
    }
    if (pow2b == -1) {
      cout << "impossible" << endl;
      continue;
    }
    if (pow2b > 40) {
      cout << "impossible" << endl;
      continue;
    }
    int steps = 1;
    while (2 * A < B) {
      ++steps;
      A *= 2;
    }
    cout << steps << endl;
  }
  return 0;
}
