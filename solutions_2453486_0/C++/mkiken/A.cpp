#include <iostream>
//#include <cstdio>
//#include <cmath>
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
//const int INF = INT_MAX;
const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};


void doIt(){
  int t;
  string f[4], ans = "";
  cin >> t;
  rep(ii, 0, t){
	bool bOwin = false, bXwin = false, bEnd = true;
	rep(i, 0, 4) cin >> f[i];
	//rep(i, 0, 4) cout << f[i] << endl;

	rep(i, 0, 4) rep(j, 0, 4){
	  if(f[i][j] == '.') bEnd = false;
	  rep(k, 0, 8){
		int x = i, y = j, cO = 0, cX = 0, cT = 0;
		rep(l, 0, 4){
		  if(0 <= x && x < 4 && 0 <= y && y < 4){
			if(f[x][y] == 'O') cO++;
			else if(f[x][y] == 'X') cX++;
			else if(f[x][y] == 'T') cT++;
		  }
		  else{
			cO = cX = cT = 0;
			break;
		  }
		  x += dx[k];
		  y += dy[k];
		}
		if(cO == 4 || cO == 3 && cT == 1) bOwin = true;
		if(cX == 4 || cX == 3 && cT == 1) bXwin = true;
	  }
	}
	//cout << "bOwin = " << bOwin << ", bXwin = " << bXwin << ", bEnd = " << bEnd << endl;
	if(bOwin) ans = "O won";
	else if(bXwin) ans = "X won";
	else if(bEnd) ans = "Draw";
	else ans = "Game has not completed";
	cout << "Case #" << ii+1 << ": " << ans << endl;
  }
}

int main() {
	doIt();
	return 0;
}
