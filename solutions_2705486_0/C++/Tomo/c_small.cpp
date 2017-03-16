#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

#define REP(i, n)      for (int (i) = 0, __n = (int)(n); (i) < __n; ++(i))
#define REPS(i, s, n)  for (int (i) = (s), __n = (int)(n); (i) < __n; ++(i))
#define REPD(i, n)     for (int (i) = (n); (i) >= 0; --(i))
#define FOREACH(i, x)  for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define SIZE(x)        (int)((x).size())

const int INF  = 31337;
const int MAXN = 64;
const int MAXD = 5;

vector<string> dict;
string         S;
int            memo[MAXN][MAXD];
int            N, K;

int f(int p, int w) {
  if (p >= N) return 0;
  int& res = memo[p][w];
  if (res != -1) return res;

  res = INF;

  REP(i, K) {
    int k = dict[i].length();
    if (k > N-p) continue;
    
    int last = -INF, changed = 0; 
    bool ok = true;

    REP(j, k) {
      if (S[p+j] != dict[i][j]) {
        if (j < w || j - last < 5) { ok = false; break; }
        last = j; ++changed;
      }
    }

    if (ok) {
      int ww = (last >= 0 ? 4 - (k - last - 1) : max(0, w - k));
      res = min(res, changed + f(p + k, max(0, ww)));
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);

  fstream fin("garbled_email_dictionary.txt");
  while (fin >> S) dict.push_back(S);
  K = dict.size();

  int T; cin >> T;
  REP(tc, T) {
    cin >> S; N = S.length();

    memset(memo, -1, sizeof(memo));
    cout << "Case #" << (tc+1) << ": " << f(0, 0) << endl;
  }

  return EXIT_SUCCESS;
}
