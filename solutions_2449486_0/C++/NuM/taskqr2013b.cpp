#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

#define pb push_back
#define mp make_pair
#define PI 3.14159265358979
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

const int maxn = 110;
int a[maxn][maxn];
int row[maxn], col[maxn];


void solve() {
  int n, m; scanf("%d%d", &n, &m);
  memset(row,0,sizeof(row));
  memset(col,0,sizeof(col));
  forn(i, n) forn(j, m) {
    scanf("%d", &a[i][j]);
    row[i] = max(row[i], a[i][j]);
    col[j] = max(col[j], a[i][j]);
  }
  bool ok = true;
  forn(i,n) forn(j, m) if (a[i][j] != min(row[i],col[j])) ok = false;
  if (ok) printf("YES\n");
  else printf("NO\n");

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  int T; scanf("%d", &T);
  forn(iter, T) {
    printf("Case #%d: ", iter+1);
    solve();
  }
	return 0;
}