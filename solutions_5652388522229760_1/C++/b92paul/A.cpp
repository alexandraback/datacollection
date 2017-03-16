#include <bits/stdc++.h>
#define openfile(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define mpr std::make_pair
#define lg(x) (31-__builtin_clz(x))
#define lgll(x) (63-__builtin_clzll(x))
#define __count __builtin_popcount
#define __countll __builtin_popcountll
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define ALL(c) (c).begin(),(c).end()
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define FORit(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define pb push_back
#define RI(x) scanf("%d",&x)
#define RID(x) int x;RI(x)
using namespace std;
typedef long long LL;
typedef double LD;
typedef vector<int> VI;
typedef std::pair<int,int> PII;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
const int N=100100, INF=1e9;
const LD EPS=1e-7;
int T;

bool cnt[N];
int num = 0;
void calc(int x){
	while(x>0){
		int y = x%10;
		if(!cnt[y]){
			num ++;
			cnt[y] = true;
		}
		x/=10;
	}
}
int solve(int x){
	if(x == 0){
		return -1;
	} else{
		memset(cnt,0,sizeof(cnt));
		num= 0;
		int now = 0;
		while(num < 10){
			calc((now+1)*x);
			now++;
		}
		return now;
	}
}
int main(){
	int t = 0;
	scanf("%d",&T);
	while(t++ < T){
		RID(x);
		printf("Case #%d: ",t);
		int tmp = solve(x);
		if(tmp == -1) puts("INSOMNIA");
		else printf("%d\n", tmp*x);
	}
}
