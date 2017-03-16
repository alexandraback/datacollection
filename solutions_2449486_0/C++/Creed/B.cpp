#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair <int, int> pii;
#define mp make_pair
#define pb push_back
const int N = 110;
int a[N][N], T, n, m;
int u_str[N], u_col[N];

bool cmp(pii pa, pii b)
{
  return a[pa.first][pa.second] > a[b.first][b.second];
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> T;
  for(int q = 1; q <= T; q++)
  {
    vector <pii> t;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
      {
        cin >> a[i][j];
        t.pb(mp(i, j));
      }

    sort(t.begin(), t.end(), cmp);

    bool impossible = false;
    for(int i = 0; !impossible && i < (int)t.size(); )
    {
      int r = i;
      while(r < (int)t.size() && a[t[i].first][t[i].second] == a[t[r].first][t[r].second])
      {
        if (u_str[t[r].first] == q && u_col[t[r].second] == q)
          impossible = true;
        r++;
      }

      while(i < r)
      {
        u_str[t[i].first] = u_col[t[i].second] = q;
        i++;
      }
    }

    cout << "Case #" << q << ": " << (impossible ? "NO" : "YES") << endl;
  }
  return 0;
}
