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
int K,C,S;
int main(){
	int t = 0;
	scanf("%d",&T);
	while(t++ < T){
		scanf("%d %d %d",&K, &C, &S);
		printf("Case #%d:",t);
		if(C*S < K) puts(" IMPOSSIBLE");
		else{
			for(int i=0; i<K; i+=C){
				long long now = 0;
				for(int j=i; j<i+C; j++){
					if(j<K) now = now * K + j;
				}
				printf(" %lld", now+1);
			}
			puts("");
		}
	}
}
