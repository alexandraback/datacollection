#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include <ctime> 
#include <float.h> 

using namespace std; 

#define REP(i, from, to) for (int i = (from); i < (to); ++i) 
#define FOR(i, n) REP(i, 0, (n)) 
#define ALL(x) x.begin(), x.end() 
#define SIZE(x) (int)x.size() 
#define PB push_back 
#define MP make_pair 

typedef long long i64; 
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef vector<string> VS; 
typedef vector<VS> VVS; 
typedef pair<int, int> PII; 

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;

  for (int tt = 0; tt < t; ++tt) {
    int a, n;
    multiset<int> sizes;
    cin >> a >> n;
    FOR (i, n) {
      int value;
      cin >> value;
      sizes.insert(value);
    }

    int best = n;
    int res = 0;
    while (!sizes.empty() && a > 1) {
      // eat all
      multiset<int>::const_iterator it = sizes.begin();
      for (; it != sizes.end() && *it < a; ) {
        if (*it < a) {
          a += *it;
          it = sizes.erase(it);
        } else {
          ++it;
        }
      }

      best = min(best, res + SIZE(sizes));
      if (sizes.empty()) break;

      a += a - 1;
      ++res;
    }

    printf("Case #%d: %d\n", tt + 1, best);
  }
  
  return 0;
}