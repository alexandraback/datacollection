#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

typedef long long ll;

ll reverse(ll x)
{
  ostringstream oss;

  oss << x;
  string s = oss.str();
  reverse(s.begin(), s.end());

  istringstream iss(s);
  iss >> x;

  return x;
}
/*

void solve()
{
  ll N;

  cin >> N;

  ll ans = 1;
  ll curr = 1;
  while (curr != N) {
    ll rev = reverse(curr);
    if (rev <= N && rev > curr+1) {
      curr = rev;
    } else {
      curr++;
    }
    ans++;
  }

  cout << ans << endl;
  }
*/

#include <climits>
#include <queue>

ll ans[1000001];

void BFS(void)
{
  ans[1] = 1;
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    int next = curr+1;
    if (next <= 1000000 && !ans[next]) {
      ans[next] = ans[curr]+1;
      q.push(next);
    }

    next = reverse(curr);
    if (next <= 1000000 && !ans[next]) {
      ans[next] = ans[curr]+1;
      q.push(next);
    }
  }
}

void solve()
{
  ll N;
  cin >> N;
  cout << ans[N] << endl;
  
}

int main()
{
  BFS();
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
