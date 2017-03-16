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

bool is_palin(int n) {
  stringstream s;
  s << n;
  const string& x = s.str();
  for (int i = 0, j = x.size() - 1; i < j; ++i, --j)
    if (x[i] != x[j]) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  static bool is_magic[1001];
  for (int i = 0; i < 100; ++i) {
    if (is_palin(i) && is_palin(i*i)) {
      is_magic[i*i] = 1;
    }
  }
  int T; cin >> T;
  for (int t_ = 0; t_ < T; ++t_) {
    int res = 0;
    int A, B; cin >> A >> B;
    for (int j = A; j <= B; ++j)
      if (is_magic[j]) res++;
    cout << "Case #" << (t_+1) << ": " << res << endl;
  }
}
