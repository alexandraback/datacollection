#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int X, Y, N;
double dp[10000][10000];

double solve(int balls, int curr) {
  if (curr >= Y) {
    return 1.0;
  } else if (!balls) {
    return 0.0;
  }

  if (dp[balls][curr + 1] < 0.0) {
    dp[balls][curr + 1] = 0.5 * solve(balls - 1, curr) + 0.5 * solve(balls - 1, curr + 1);
  }
  return dp[balls][curr + 1];
}

void init() {
  for (int i = 0; i < 10000; ++i) {
    for (int j = 0; j < 10000; ++j) {
      dp[i][j] = -1.0;
    }
  }
}

int main() {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;

  for (int k = 1; k <= T; ++k) {
    cin >> N >> X >> Y;
    X = abs(X);
    cout << "Case #" << k << ": ";
    double res = 0.0;
    long long height = X / 2 + X % 2 + Y - 1;
    long long a = (height * (height + 1)) / 2;

    //cerr << "Base: " << height << " total: " << a << endl;

    if (a > N) {
      res = 0.0;
    } else if (!X) {
      res = (((height + 1) * (height + 2)) / 2 <= N);
    } else {
      N -= a;
      if (N >= height + 2 + Y) {
        res = 1.0;
      } else {
        init();
        res = solve(N, -1);  
      }
    }

    printf("%.7lf\n", res);
  }
  
  return 0;
}
