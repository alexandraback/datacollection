#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>

using namespace std;

//#define NAME "my"
#define NAME "A-small-attempt0"
//#define NAME "A-large"

const int SZ = 1000007;

int64_t n;
int dp[SZ];
int prv[SZ];

vector<int> tmp;
int64_t rev(int64_t d) {
  tmp.clear();
  while (d) {
    tmp.push_back(d % 10);
    d /= 10;
  }
  int64_t ret = 0;
  for (auto val : tmp) {
    ret = ret * 10 + val;
  }
  return ret;
}

void solveCase(int tc) {
  cin >> n;
  if (n == 1) {
    cerr << "Case #" << (tc + 1) << ": " << 1 << endl;
    cout << "Case #" << (tc + 1) << ": " << 1 << endl;
    return;
  }
  memset(dp, -1, sizeof(dp));
  dp[1] = 1;
  prv[1] = 1;
  queue<pair<int64_t, int>> q;
  q.push(make_pair(1, 1));
  int answer = -1;
  while (!q.empty()) {
    int64_t v = q.front().first;
    int dist = q.front().second;
    q.pop();
    //cerr << v << " " << dist << endl;
    int next = v + 1;
    int next_rev = rev(v);
    if (next == n || next_rev == n) {
      answer = dist + 1;
      break;
    }
    if (next < SZ && dp[next] == -1) {
      dp[next] = dist + 1;
      prv[next] = v;
      q.push(make_pair(next, dist+1));
    }
    if (next_rev < SZ && dp[next_rev] == -1) {
      dp[next_rev] = dist + 1;
      prv[next_rev] = v;
      q.push(make_pair(next_rev, dist+1));
    }
  }
  cerr << "Case #" << (tc + 1) << ": " << answer << endl;
  cout << "Case #" << (tc + 1) << ": " << answer << endl;
}

void initialize() {
}

int main() {
  freopen(NAME ".in", "rt", stdin);
  freopen(NAME ".out", "wt", stdout);
  int T;
  cin >> T;
  initialize();
  for (int i = 0; i < T; i++) {
    solveCase(i);
  }
  double totalTime = clock() * 1. / CLOCKS_PER_SEC;
  fprintf(stderr, "Time: %.2lf sec\n", totalTime);
  return 0;
}
