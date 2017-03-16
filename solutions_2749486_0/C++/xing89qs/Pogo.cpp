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

int main(void){
      freopen("data.in","r",stdin);
	  freopen("data.out","w",stdout);
	  int t,tt = 1;
	  scanf("%d",&t);
	  while(t--){
		  int x,y;
		  scanf("%d %d",&x,&y);
		  printf("Case #%d: ",tt++);
		  if(x>=0){
			  int tmp = 0;
			  while(tmp<x) printf("WE"),tmp++;
		  }else{
			  int tmp = 0;
			  while(tmp>x) printf("EW"),tmp--;
		  }
		  if(y>0){
			  int tmp = 0;
			  while(tmp<y) printf("SN"),tmp++;
		  }else{
			  int tmp = 0;
			  while(tmp>y) printf("NS"),tmp--;
		  }
		  putchar('\n');
	  }
}

