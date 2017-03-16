#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int infinity = 1e9 + 9;

int N;
int dp[1000009];
queue<int> Q;
queue<int> C;

int reverse(int x)
{
  int r = 0;
  while (x > 0)
  {
    r = 10 * r + (x % 10);
    x = x / 10;
  }
  return r;
}

int main()
{
  int T;
  cin >> T;
  for (int Ti = 1; Ti <= T; Ti++) {
    // input
    cin >> N;
    
    // init
    for (int n = 0; n <= N; ++n)
      dp[n] = infinity;
    dp[1] = 1;
    while (!Q.empty()) Q.pop();
    while (!C.empty()) C.pop();
    Q.push(1);
    C.push(1);
    
    // special case
    if (N == 1)
    {
      cout << "Case #" << Ti << ": " << 1 << endl;
      continue;
    }
    
    // dp
    while (true) {
      int q = Q.front(); Q.pop();
      int c = C.front(); C.pop();
      if (c + 1 < dp[q + 1])
      {
        Q.push(q + 1);
        C.push(c + 1);
        dp[q] = c;
      }
      if (c + 1 < dp[reverse(q)])
      {
        Q.push(reverse(q));
        C.push(c + 1);
        dp[reverse(q)] = c;
      }
      if ((q + 1 == N) || (reverse(q) == N))
      {
        cout << "Case #" << Ti << ": " << c + 1 << endl;
        break;
      }
    }
  }
  return 0;
}
