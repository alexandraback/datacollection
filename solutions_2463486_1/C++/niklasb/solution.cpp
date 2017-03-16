#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;
using namespace std::tr1;

typedef long long llong;
typedef pair<int, int> int2;
typedef pair<llong, llong> llong2;
#define foreach(v,c) for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define rep(i,n) for (int i = 0; i < (n); ++i)

template <typename T>
bool is_palin(T n) {
  stringstream s;
  s << n;
  const string& x = s.str();
  for (int i = 0, j = x.size() - 1; i < j; ++i, --j)
    if (x[i] != x[j]) return false;
  return true;
}

int tenpow(int n) {
  llong res = 1;
  while (n--) res *=10;
  return res;
}

int revdec(int x, bool droplast) {
  int res = 0;
  while (x) {
    res *= 10;
    if (!droplast) res += x % 10;
    droplast=0;
    x /= 10;
  }
  return res;
}

vector<llong> nums;
int doit(llong x) {
  return upper_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int main() {
  ios_base::sync_with_stdio(false);
  for (int n = 1; n <= 7; ++n) {
    int h = (n+1)/2;
    int l = tenpow(h-1), r = tenpow(h);
    int mult = (n%2) ? tenpow(n/2) : tenpow(h);
    for (int x = l; x < r; ++x) {
      llong full = (llong)mult * x + revdec(x, n%2);
      llong sq = full*full;
      if (is_palin(sq))
        nums.push_back(sq);
    }
  }
  //foreach(it, nums) cout << *it << endl;
  int T; cin >> T;
  for (int t_ = 0; t_ < T; ++t_) {
    llong A, B; cin >> A >> B;
    cout << "Case #" << (t_+1) << ": " << (doit(B)-doit(A-1))  << endl;
  }
}
