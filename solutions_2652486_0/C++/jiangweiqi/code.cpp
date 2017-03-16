#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <string.h>

using namespace std; 

#define ALL(X)       (X).begin(),(X).end()
#define SIZE(X)      ((int)(X).size())
#define FORI(x,a,b)  for(x=(a);x<=(b);x++)
#define FORD(x,a,b)  for(x=(a);x>=(b);x--)
#define min(a,b)     ((a)<(b)?(a):(b))
#define max(a,b)     ((a)<(b)?(b):(a))
#define MEM(X,with)  memset((X),(with),sizeof(X))
#define Contains(X,item)    ((X).find(item)!=(X).end())
#define Contains_n(X,item)	(find((X).begin(),(X).end(),(item))!=(X).end())
#define rep(i,m,n) for((i)=m;(i)<(int)(n);(i)++)
#define PQ priority_queue
#define IT iterator
#define N 1000005

//bool prime[N];
const int inf =(1<<30)-1;
const long long linf = (1ll<<62)-1;
const int dirx[]={-1,0,0,1,-1,-1,1,1}, diry[]={0,-1,1,0,-1,1,-1,1};
const double ERR = 1e-11, PI=(2*acos(0.0));


template<class T> bool cmpmin(T a, T b){return a<b;}
template<class T> bool cmpmax(T a, T b){return a>b;}
template<class T> inline T ABS(T a) {return ((a<0)?(-a):(a));}
template<class T> T GCD(T a,T b) {return ((!b)?(a):GCD(b,a%b));}
template<class T> T fastPow(T Base,T Power) {T Result=1; while(Power>0){if(Power&((T)1))Result*=Base; Power>>=1; Base*=Base;} return Result;}
template<class T> T fastModPow(T Base,T Power,T Mod) {T Result=1;while(Power>0){if(Power&((T)1))Result=(Result*Base)%Mod; Power>>=1; Base=(Base*Base)%Mod;} return (Result%Mod);}
inline int compDouble(double x,double y) {double d=x-y; if(d-ERR>0.0) return 1; else if(d+ERR<0.0) return -1; else return 0;}
inline void file(){freopen("C-small-1-attempt0.in","r",stdin);freopen("rle-size.txt","w",stdout);}
//void prim(){prime[0]=1;prime[1]=1;int i;long long j;for(i=2;i<N;i++){if(prime[i]==0){for(j=i,j=j*i;j<N;j+=i){prime[j]=1;}}}}

typedef long long ll;
typedef unsigned long long ull;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<ll>     VL;
typedef vector<int>    VI;

//int e,r,n;
//int v[100];
//int dp[100][100];
//void dfs(int day,int en){
//	if(day == n+1)return ;
//	int i,ee;
//	for(i=0;i<=en;i++){
//		ee = min(e,en-i+r);
//		if(dp[day-1][en] + v[day]*i > dp[day][ee]){
//			dp[day][ee] = dp[day-1][en] + v[day]*i;
//			dfs(day+1,ee);
//		}
//	}
//}
//
//int main(){
//	file();
//	int T,cas,i;
//	scanf("%d",&T);
//	for(cas=1;cas<=T;cas++){
//		MEM(dp,0);
//		scanf("%d %d %d",&e,&r,&n);
//		for(i=1;i<=n;i++)scanf("%d",&v[i]);
//		dfs(1,e);
//		int mx = 0;
//		for(i=0;i<=e;i++){
//			mx = max(dp[n][i],mx);
//		}
//		printf("Case #%d: %d\n",cas,mx);
//	}
//	return 0;
//}
//
int main(){
	file();
	int cas,T,i,j,r,n,m,k,v[10];
	scanf("%d",&T);
	printf("Case #1:\n");
	for(cas=1;cas<=T;cas++){
		scanf("%d %d %d %d",&r,&n,&m,&k);
		for(i=0;i<r;i++){
			for(j=0;j<k;j++){
				scanf("%d",&v[j]);
			}
			int a,b,c;
			for(a=2;a<=m;a++){
				for(b=2;b<=m;b++){
					for(c=2;c<=m;c++){
						for(j=0;j<k;j++){
							if(v[j]==1)continue;
							if(a==v[j]||b==v[j]||c==v[j]
							||a*b==v[j] || a*c==v[j] || b*c==v[j]||
							 a*b*c==v[j])continue;
							break;
						}
						if(j==k){
							printf("%d%d%d\n",a,b,c);
							break;
						}
					}
					if(c!=m+1)break;
				}
				if(b!=m+1)break;
			}
		}
	}
	return 0;
}