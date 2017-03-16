#include <iostream>
#include <set>

using namespace std;

const int HI = 30;
const int N = 100;

set< pair<bool, int> > all[HI+1];
int n, s, p;
int scores[N];
int dp[N][N+1];
bool known[N][N+1];

void init() {
  for (int a = 0; a <= 10; a++) {
    for (int b = 0; b <= 10; b++) {
      for (int c = 0; c <= 10; c++) {
        int lo = min(a, min(b, c));
        int hi = max(a, max(b, c));
        if (hi-lo > 2) continue;
        int sum = a + b + c;
        bool surprising = (hi-lo == 2);
        all[sum].insert(make_pair(surprising, hi));
      }
    }
  }
}

int go(int idx, int ss) {
  if (ss > s) return -1;
  if (idx == n) return (ss == s ? 0 : -1);
  if (known[idx][ss]) return dp[idx][ss];
  known[idx][ss] = true;

  set< pair<bool, int> >& poss = all[scores[idx]];
  int best = -1;
  for (set< pair<bool, int> >::iterator it(poss.begin()); it != poss.end(); it++) {
    int next = go(idx+1, ss + (it->first ? 1 : 0));
    if (next < 0) continue;
    next += (it->second >= p) ? 1 : 0;
    best = max(best, next);
  }
  return dp[idx][ss] = best;
}

int main() {
  init();
  int t; cin >> t;
  for (int caseNo = 1; caseNo <= t; caseNo++) {
    cin >> n >> s >> p;
    for (int i = 0; i < n; i++) cin >> scores[i];
    memset(known, false, sizeof(known));
    cout << "Case #" << caseNo << ": " << go(0, 0) << endl;
  }
  return 0;
}

