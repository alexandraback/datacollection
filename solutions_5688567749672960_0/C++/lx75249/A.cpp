#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int revs[1000001];
int rev(int n)
{
  if (revs[n] != -1)
    return revs[n];
  string s = to_string(n);
  reverse(s.begin(), s.end());
  return revs[n] = stoi(s);
}

int rec[1000001];

int main()
{
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  memset(revs, 0xff, sizeof(revs));
  memset(rec, 0x7f, sizeof(rec));

  queue<int> Q;
  Q.push(1);
  rec[1] = 1;
  while(!Q.empty())
  {
    int now = Q.front(); Q.pop();
    if (now+1 < 1000001)
      if (rec[now+1] > rec[now])
      {
        Q.push(now+1);
        rec[now+1] = rec[now]+1;
      }
    if (rev(now) < 1000001)
      if (rec[rev(now)] > rec[now])
      {
        Q.push(rev(now));
        rec[rev(now)] = rec[now]+1;
      }
  }

  int T, N;
  cin >> T;
  for(int i=1; i<=T; ++i)
  {
    cin >> N;
    printf("Case #%d: %d\n", i, rec[N]);
  }
}
