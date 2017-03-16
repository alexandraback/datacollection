#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;

//#define NAME "my"
//#define NAME "A-small-attempt0"
#define NAME "A-large"

const int SZ = 10000007;

int64_t n;
int dp[SZ];
int prv[SZ];
unordered_map<int64_t, int64_t> M;

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

int64_t tform(int64_t v) {
  stringstream sin;
  sin << v;
  string s;
  sin >> s;
  if (s[0] == '1') return -1;
  s[0]--;
  for (int i = 1; i < (int)s.size(); i++)
    s[i] = '9';
  stringstream sin2;
  sin2 << s;
  int64_t ret;
  sin2 >> ret;
  //cerr << v << " -> " << ret << endl;
  return ret;
}

int solve_dumb() {
  if (n == 1) return 1;
  memset(dp, -1, sizeof(dp));
  dp[1] = 1;
  prv[1] = 1;
  queue<pair<int64_t, int>> q;
  q.push(make_pair(1, 1));
  while (!q.empty()) {
    int64_t v = q.front().first;
    int dist = q.front().second;
    q.pop();
    //cerr << v << " " << dist << endl;
    int next = v + 1;
    int next_rev = rev(v);
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
    if (next == n || next_rev == n) {
      vector<int> path;
      path.push_back(n);
      int64_t v = n;
      while (v != 1) {
        v = prv[v];
        path.push_back(v);
      }
      reverse(path.begin(), path.end());
      for (auto v : path) cerr << v << " ";
      cerr << endl;
      return dist + 1;
    }
  }
  return -1;
}

int64_t go(int64_t v) {
  if (v == 1) return 1;
  auto it = M.find(v);
  if (it != M.end()) return it->second;
  //cerr << v << endl;
  int64_t ret = v;
  if (v % 10) {
    int64_t rv = rev(v);
    if (rv < v) {
      ret = min(ret, go(rv) + 1);
    }
  }
  for (int64_t i = 10; i < 1000000000000000000LL; i *= 10) {
    int64_t v2 = v - (v % i) + 1;
    if (v2 < v) {
      int64_t cur = (v - v2) + go(v2);
      ret = min(ret, cur);
    }
    if (v2 == 1) break;
  }
  int64_t tt = tform(v);
  if (tt != -1) {
    int64_t cur = (v - tt) + go(tt);
    ret = min(ret, cur);
  }
  if (v % 10 == 0)
    ret = min(ret, go(v-1)+1);
  for (int64_t d9 = 9; d9 <= 1000000000000000000LL; d9 = d9*10 + 9) {
    if (d9 >= v) break;
    int64_t cur = (v - d9) + go(d9);
    ret = min(ret, cur);
  }

  M[v] = ret;
  return ret;
}

int64_t solve_smart() {
  if (n == 1) return 1;
  return go(n);
}

void solveCase(int tc) {
  cin >> n;
  //if (tc == 31) cerr << n << endl;
  int answer = solve_smart();
  /*
  int answer2 = solve_dumb();
  if (answer != answer2) {
    cerr << "WA: " << answer << " " << answer2 << endl;
    return;
  }
  */
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
