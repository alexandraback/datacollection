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

char s[1000005];
bool vo[26];

int main(void){
      freopen("A.in","r",stdin);
	  freopen("data.out","w",stdout);
	  memset(vo,0,sizeof(vo));
	  int tt = 1;
	  vo[0] = vo[4] = vo['i'-'a'] = vo['o'-'a'] = vo['u'-'a'] = true;
	  int t;
	  scanf("%d",&t);
	  while(t--){
		  int n;
		  scanf("%s %d",s,&n);
		  int cnt = 0,pre = -1;
		  LL ans = 0;
		  for(int i = 0;s[i];i++){
			  if(!vo[s[i]-'a']) cnt++;
			  else cnt = 0;
			  if(cnt>=n) pre = i-n+1;
			  if(pre==-1) continue;
			  ans+=pre+1;
		  }
		  printf("Case #%d: %lld\n",tt++,ans);
	  }
}

