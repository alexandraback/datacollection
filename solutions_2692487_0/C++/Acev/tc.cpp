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
int N;
vector<int> v;
const int maxSize = 1000001;
const int maxN = 101;
int dp[maxSize][maxN];


int solve(int currSize, int currIndex) {
  if (currIndex == N) {
    return 0;
  }

  int &curr = dp[currSize][currIndex];
  if (curr == -1) {
    if (v[currIndex] < currSize) {
      curr = solve(min(maxSize, currSize + v[currIndex]), currIndex + 1);
    } else {
      // 1. create a smaller mote.
      int curr1 = solve(min(currSize * 2 - 1, maxSize), currIndex) + 1;

      // 2. Skip the next mote.
      int curr2 = solve(currSize, currIndex + 1) + 1;
      curr = min(curr1, curr2);  
    }
  }

  return curr;
}

int main() {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;

  for (int k = 1; k <= T; ++k) {
    int A;
    cin >> A >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    int res = N;
    if (A > 1) {
      res = solve(A, 0);
    }

    cout << "Case #" << k << ": " << res;
    cout << endl;
  }
  
  return 0;
}
