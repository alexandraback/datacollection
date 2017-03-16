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

void countRotates(int n, vector<PII>& pairs) {
  ostringstream oss;
  oss << n;

  string nstr = oss.str();
  set<int> res;

  FOR (i, SIZE(nstr) - 1) {
    nstr = nstr.back() + nstr;
    nstr.pop_back();

    if (nstr[0] == '0') continue;
    int const newNumber = atoi(nstr.c_str());
    if (newNumber < n) {
      if (res.count(newNumber) == 0) {
        pairs.PB(MP(newNumber, n));
        res.insert(newNumber);
      }
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int const MAX_N = 2000005;
  vector<PII> pairs;

  REP (i, 1, MAX_N) {
    countRotates(i, pairs);
  }

  int t;
  cin >> t;

  FOR (tt, t) {
    int a, b;
    cin >> a >> b;
    int res = 0;
    FOR (i, SIZE(pairs))
      res += pairs[i].first >= a && pairs[i].first <= b && pairs[i].second >= a && pairs[i].second <= b;
    printf("Case #%d: %d\n", tt + 1, res);
  }

  return 0;
}