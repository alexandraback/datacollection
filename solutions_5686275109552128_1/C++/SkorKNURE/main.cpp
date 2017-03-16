#include <iostream>
#include <vector>

using namespace std;

//#define NAME "my"
//#define NAME "B-small-attempt1"
#define NAME "B-large"

int n;
int p[1000];
int dp[1001][1001];

int getSplitTime(int val, int maxVal) {
  if (val < 0 || maxVal < 0) throw 1;
  if (val <= maxVal) return 0;
  if (dp[val][maxVal] != -1) return dp[val][maxVal];
  int ret = 1000000000;
  for (int i = 1; i <= maxVal; i++) {
    int cur = 1;
    cur += getSplitTime(i, maxVal);
    cur += getSplitTime(val - i, maxVal);
    if (cur < ret) ret = cur;
  }
  return dp[val][maxVal] = ret;
}

void solveCase(int tc) {
  cin >> n;
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    maxi = max(maxi, p[i]);
  }
  int answer = 1000000000;
  for (int target = 1; target <= 1000; target++) {
    int total = 0;
    for (int i = 0; i < n; i++) {
      total += getSplitTime(p[i], target);
    }
    total += target;
    answer = min(answer, total);
  }
  if (answer > maxi) throw 1;
  cout << "Case #" << (tc + 1) << ": " << answer << endl;
  cerr << "Case #" << (tc + 1) << ": " << answer << endl;
}

void initialize() {
  memset(dp, -1, sizeof(dp));
}

int main() {
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  int T;
  cin >> T;
  initialize();
  for (int i = 0; i < T; i++) {
    solveCase(i);
  }
  return 0;
}
