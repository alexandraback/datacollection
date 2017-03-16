//#pragma comment(linker,"/STACK:102400000,102400000")
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
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/B.in","r",stdin);
	freopen("/Users/mac/Desktop/B.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		int ans = 0;
		for(int i = 0;i<a;i++){
			for(int j = 0;j<b;j++){
				if((i&j)<k) ans++;
			}
		}
		static int ca = 1;
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}

