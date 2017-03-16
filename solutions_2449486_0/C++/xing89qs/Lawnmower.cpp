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

int g[101][101];
int row[101],col[101];

int main(void){
      freopen("data.in","r",stdin);
	  freopen("data.out","w",stdout);
	  int t,tt = 1;
	  cin>>t;
	  while(t--){
		  int n,m;
		  cin>>n>>m;
		  memset(row,0,sizeof(row));
		  memset(col,0,sizeof(col));
		  for(int i = 0;i<n;i++)
			  for(int j = 0;j<m;j++){
				  cin>>g[i][j];
				  row[i] = max(row[i],g[i][j]);
				  col[j] = max(col[j],g[i][j]);
			  }
		  bool flag = true;
		  for(int i = 0;i<n&&flag;i++){
			  for(int j = 0;j<m&&flag;j++){
				  if(g[i][j]!=row[i]&&g[i][j]!=col[j]) flag = false;
			  }
		  }
		  cout<<"Case #"<<tt++<<": ";
		  if(flag) cout<<"YES"<<endl;
		  else cout<<"NO"<<endl;
	  }
}

