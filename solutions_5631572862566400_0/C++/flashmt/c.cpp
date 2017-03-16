#include <bits/stdc++.h>
using namespace std;

vector <int> a[1111];
int n, f[1111];

int visit(int x)
{
  int res = 0;
  for (int y : a[x])
    if (y != f[x])
      res = max(res, visit(y));
  return res + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cerr << "Running test " << iTest << "..." << endl;
    int flag[1111] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
      a[i].clear();
    for (int i = 0; i < n; i++)
    {
      cin >> f[i];
      f[i]--;
      a[f[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
      if (!a[i].empty())
      {
        int x = i, cnt = 0;
        vector <int> path;
        while (!flag[x])
        {
          path.push_back(x);
          flag[x] = ++cnt;
          x = f[x];
        }
        ans = max(ans, cnt - flag[x] + 1);
      }

    for (int i = 0; i < n; i++)
      if (!flag[i])
      {
        int x = i, cnt = 0;
        while (!flag[x])
        {
          flag[x] = ++cnt;
          x = f[x];
        }
        ans = max(ans, cnt);
      }

    int sum = 0;
    for (int i = 0; i < n; i++)
      if (i < f[i] && f[f[i]] == i)
        sum += visit(i) + visit(f[i]);
    ans = max(ans, sum);

    cout << "Case #" << iTest << ": " << ans << endl;
  }
}