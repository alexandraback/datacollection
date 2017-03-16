#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

using namespace std;

char g[4][5];

int main(void){
      freopen("data.in","r",stdin);
	  freopen("data.out","w",stdout);
	  int t,tt = 1;
	  scanf("%d",&t);
	  while(t--){
		  for(int i = 0;i<4;i++) scanf("%s",g[i]);
		  bool x = false,o = false;
		  for(int i = 0;i<4;i++){
			  bool xx = true,oo = true;;
			  for(int j = 0;j<4;j++){
				  if(g[i][j]=='.'||g[i][j]=='O') xx = false;
				  if(g[i][j]=='.'||g[i][j]=='X') oo = false;
			  }
			  if(xx) x = true;
			  if(oo) o = true;
			  xx = oo = true;
			  for(int j = 0;j<4;j++){
				  if(g[j][i]=='.'||g[j][i]=='O') xx = false;
				  if(g[j][i]=='.'||g[j][i]=='X') oo = false;
			  }
			  if(xx) x = true;
			  if(oo) o = true;
		  }
		  bool oo = true,xx = true;
		  for(int i = 0;i<4;i++){
			  if(g[i][i]=='.'||g[i][i]=='O') xx = false;
			  if(g[i][i]=='.'||g[i][i]=='X') oo = false;
		  }
		  if(xx) x = true;
		  if(oo) o = true;
		  oo = xx = true;
		  for(int i = 0;i<4;i++){
			  if(g[i][3-i]=='.'||g[i][3-i]=='O') xx = false;
			  if(g[i][3-i]=='.'||g[i][3-i]=='X') oo = false;
		  }
		  if(xx) x = true;
		  if(oo) o = true;
		  bool has = false;
		  for(int i = 0;i<4;i++)
			  for(int j = 0;j<4;j++) if(g[i][j]=='.') has = true;
		  printf("Case #%d: ",tt++);
		  if(!x&&!o&&!has) puts("Draw");
		  else if(x) puts("X won");
		  else if(o) puts("O won");
		  else puts("Game has not completed");
	  }
}

