#include <cstring>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iomanip>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v)                                          \
  for (int X = 0; X < v.size(); X++) cout << printf("%d "); \
  printf("\n");
#define grid(v)                                                   \
  for (int X = 0; X < v.size(); X++) {                            \
    for (int Y = 0; Y < v[X].size(); Y++) printf("%d ", v[X][Y]); \
    printf("\n");                                                 \
  }
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
const int MOD = 1e9 + 7;
void solve(int t)
{
  cout << "Case #" << t << ": ";
  ll b, m;
  cin >> b >> m;
  ll maximo = (1 << (b - 2));
  vvi v(b, vi(b, 0));
  if (maximo >= m) {
    cout << "POSSIBLE" << endl;
    ll i = 0;
    ll tot = i;
    for (i = 0; i < b; i++) {
      ll aux = (1 << i);
      if (aux > m) break;
    }
    tot = i;
    ll add=0;
    for (i = 0; i < tot; i++)
      for (ll j = i + 1; j < tot; j++) v[i][j] = 1;
    for (i = 0; i < tot; i++) {
      if(i==b-1) continue;
      v[i][b - 1] = 1;
    }
    ll ant=tot;
    while (m > 0) {
      m -= (1<<(i-1));
      tot--;
      if(m==0) break;
      for (i = 0; i < b; i++) {
        ll aux = (1 << (i-1));
        if (aux > m) break;
      }
      v[i-1][ant]=1;
      v[ant][b-1]=1;
    }
    grid(v);
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}
int main()
{
  BUFF;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
