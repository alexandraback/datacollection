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
#define PROBLEM_ID "C"

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

bool IsGoodCircle(const vi& circle, const vi& bff) {
  for (int i = 0; i < circle.size(); ++i) {
    int nxt = (i + 1) % circle.size();
    int prv = (i + circle.size() - 1) % circle.size();
    if (circle[nxt] != bff[circle[i]] && circle[prv] != bff[circle[i]]) {
      return false;
    }
  }
  return true;
}

int MaxKidsSlow(int n, const vi& bff) {
  vi perm;
  for (int i = 0; i < n; ++i) {
    perm.push_back(i);
  }
  int res = 0;
  do {
    /*for (int len = 1; len <= n; ++len) {
      vi circle;
      for (int i = 0; i < len; ++i) {
        circle.push_back(perm[i]);
      }
      if (IsGoodCircle(circle, bff)) {
        res = max(res, circle.size());
      }
    }*/
    for (int len = 1; len <= n; ++len) {
      int a = perm[len - 1];
      if ((bff[a] == perm[0] || (len > 1 && bff[a] == perm[len - 2])) && (len == 1 || bff[perm[0]] == perm[1] || bff[perm[0]] == perm[len - 1])) {
        res = max(res, len);
      }
      if (len > 1 && bff[a] != perm[len - 2] && (len == n || bff[a] != perm[len])) {
        break;
      }
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return res;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n;
    cin >> n;
    vi bff(n);
    for (int i = 0; i < n; ++i) {
      cin >> bff[i];
      --bff[i];
    }
    int max_kids = MaxKidsSlow(n, bff);
    cout << "Case #" << (test_index + 1) << ": " << max_kids << endl;
    cerr << "Case #" << (test_index + 1) << ": " << max_kids << endl;    
  }
  return 0;
}
