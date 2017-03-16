#include <iostream>
//#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
//#include <map>
//#include <set>
//#include <queue>
//#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v) fill((int *)a, (int *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define msort(a) sort(a, a + len(a))
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
const int INI = 100;
const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

void doIt(){
  int t, n, m, f[102][102], exp[102][102], row[102], col[102];
  cin >> t;
  rep(ii, 0, t){
	bool bOK = true;
	cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> f[i][j];
	mfill(row, 0);
	mfill(col, 0);
	rep(i, 0, n) rep(j, 0, m){
	  row[i] = max(row[i], f[i][j]);
	  col[j] = max(col[j], f[i][j]);
		};
	mfill2(exp, INI);
	rep(i, 0, n) rep(j, 0, m) exp[i][j] = min(exp[i][j], min(row[i], col[j]));
	rep(i, 0, n) rep(j, 0, m) if(f[i][j] != exp[i][j]) bOK = false;

	cout << "Case #" << ii+1 << ": " << (bOK? "YES" : "NO") << endl;
  }
}

int main() {
	doIt();
	return 0;
}
