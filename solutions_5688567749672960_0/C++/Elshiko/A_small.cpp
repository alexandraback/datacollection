#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

const int LIM = 1e+7;
const int INF = 1e+9;

int dp[LIM];

int get_rev(int x) {
  int res = 0;
  while (x > 0) {
    res *= 10;
    res += (x % 10);
    x /= 10;
  }
  return res;
}

void init() {
  fill(dp, dp + LIM, INF);
  dp[1] = 1;
  priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
  pq.push(make_pair(1, 1));
  int cur = 0, nxt, rev, len;
  while (!pq.empty()) {
    cur = pq.top().second;
    if (dp[cur] != pq.top().first) {
      pq.pop();
      continue;
    }
    pq.pop();
    nxt = cur + 1;
    rev = get_rev(cur);
    len = dp[cur] + 1;
    if (nxt < LIM && dp[nxt] > len) {
      dp[nxt] = len;
      pq.push(make_pair(len, nxt));
    }
    if (rev < LIM && dp[rev] > len) {
      dp[rev] = len;
      pq.push(make_pair(len, rev));
    }
  }
}

int main() {
  ifstream cin("A-small-attempt0.in");
  ofstream cout("A_small_out");
  init();
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    int x;
    cin >> x;
    cout << "Case #" << test + 1 << ": " << dp[x] << '\n';
  }
  return 0;
}
