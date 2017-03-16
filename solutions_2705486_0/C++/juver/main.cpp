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
#include <fstream> 
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

struct State {
  State(int first = -1, int last = -1, int cnt = 0, int id = -1)
    : first(first), last(last), cnt(cnt) {}
  int first, last, cnt, id;
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;

  VS dict;
  {
    ifstream in("dict.txt");
    string line;
    while (in >> line) dict.PB(line);
  }

  for (int tt = 0; tt < t; ++tt) {
    string pattern;
    cin >> pattern;

    vector<vector<State> > subs(SIZE(pattern));
    FOR (i, SIZE(pattern)) FOR (j, SIZE(dict)) {
      string const& d = dict[j];
      State s;

      if (i + SIZE(d) > SIZE(pattern)) continue;

      FOR (k, SIZE(d)) {
        if (d[k] != pattern[i + k]) {
          ++s.cnt;
          if (s.first == -1)
            s.first = i + k;
          if (s.cnt > 15 || s.last != -1 && i + k - s.last < 5) {
            s.cnt = 1000;
            break;
          }
          s.last = i + k;
        }
      }

      if (s.cnt < 15) {
        s.id = j;
        subs[i].PB(s);
      }
    }

    int const INF = 12345678;
    int const n = SIZE(pattern);
    VVI dp(n + 1, VI(n + 1, INF));
    
    dp[0][0] = 0;

    int res = INF;
    FOR (i, n) FOR (k, n + 1) if (dp[i][k] != INF) {
      FOR (j, SIZE(subs[i])) {
        int lastChange = k - 1;
        State const& s = subs[i][j];
        string const& d = dict[s.id];

        int nextLastChange;
        if (s.cnt == 0)
          nextLastChange = lastChange;
        else {
          if (lastChange != -1 && s.first - lastChange < 5) continue;
          nextLastChange = s.last;
        }

        dp[i + SIZE(d)][nextLastChange + 1] = min(dp[i + SIZE(d)][nextLastChange + 1], dp[i][k] + s.cnt);
      }
    }

    FOR (k, n + 1) res = min(res, dp[n][k]);

    printf("Case #%d: %d\n", tt + 1, res);
  }
  
  return 0;
}