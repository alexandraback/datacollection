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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

int mul [5][5] = {
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}
};

int sign(int x){
	return x>0?1:-1;
}

int ret[1000005];
int mp[128];
char s[100005];

int Mul(int cur,char c){
	int tmp = mp[(int)c];
	int flag = sign(cur);
	cur = abs(cur);
	cur = mul[cur][tmp];
	return cur*flag;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in","r",stdin);
	freopen("/Users/mac/Desktop/data.out","w",stdout);
#endif
	mp[(int)'i'] = 2,mp[(int)'j'] = 3,mp[(int)'k'] = 4;
	int t;
	cin>>t;
	while(t--){
		LL l,x;
		cin>>l>>x;
		cin>>s;
		for(int i = 0;i<x;i++){
			for(int j = 0;j<l;j++) s[i*l+j] = s[j];
		}
		s[l*x] = '\0';
		int now = 1;
		int cur = 2;
		for(int i = 0;s[i];i++){
			now = Mul(now,s[i]);
			if(now==cur){
				cur++;
				now = 1;
			}
		}
		int ans = 0;
		if(now==1&&cur==5) ans = 1;
		else ans = 0;
		static int ca = 1;
		printf("Case #%d: %s\n",ca++,ans?"YES":"NO");
	}
	return 0;
}

