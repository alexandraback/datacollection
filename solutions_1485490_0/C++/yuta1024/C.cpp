#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

const int INF = 1 << 30;

long long int dp[100][100];

long long int solve(int b, int a, int bit, vector<pair<long long int, int> >& A, vector<pair<long long int, int> >& B)
{
  if (b == B.size())
    return 0;

  if (dp[b][bit] != -1)
    return dp[b][bit];

  long long int res = 0;
  for (int i = a; i < A.size(); ++i) {
    if (B[b].second == A[i].second) {
      long long int toy = min(B[b].first, A[i].first);
      A[i].first -= toy;
      B[b].first -= toy;
      if (A[i].first == 0 && B[b].first == 0)
	res = max(res, solve(b+1, i+1, 0, A, B)+toy);
      else if (A[i].first == 0)
	res = max(res, solve(b, i+1, bit | 1 << i, A, B)+toy);
      else
	res = max(res, solve(b+1, i, 0, A, B)+toy);
      A[i].first += toy;
      B[b].first += toy;
    }
  }
  res = max(res, solve(b+1, a, 0, A, B));
  return dp[b][bit] = res;
}

int main()
{
  int T;
  cin >> T;
  for (int Testcase = 1; Testcase <= T; ++Testcase) {
    int N, M;
    cin >> N >> M;
    vector<pair<long long int, int> > A(N), B(M);
    for (int i = 0; i < N; ++i)
      cin >> A[i].first >> A[i].second;
    for (int i = 0; i < M; ++i)
      cin >> B[i].first >> B[i].second;

    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j)
	dp[i][j] = -1;
    }

    long long int ans = 0;
    for (int i = 0; i < M; ++i)
      ans = max(ans, solve(i, 0, 0, A, B));

    cout << "Case #" << Testcase << ": " << ans << endl;
  }
  return 0;
}
