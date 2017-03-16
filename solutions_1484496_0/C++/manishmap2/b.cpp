#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <utility>
#include <sstream>

#define FOR(i,a,n) for(i=(a);i<(n);++i)
#define FORIT(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define f0(a) memset(a,0,sizeof(a))
#define fx(a,x) memset(a,(x),sizeof(a))

#define _bc(i) __builtin_popcount(i)
#define all(v) v.BE,v.EN
#define sz size()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define BE begin()
#define EN end()
#define IT iterator

using namespace std;
typedef vector <int> 	VI;
typedef vector < VI > 	VVI;
typedef vector<string> 	VS;
typedef pair<int,int> 	II;
typedef vector<II > 	VII;
typedef map<int,int> 	MII;
typedef long long 	lint;

#define INF (1<<30)		//or 0x7ffffff0 for 2^31-16 = 2147483647 
#define MINF 0x80000000		//-2^31
#define INFLL (1LL<<62)

template<class T> string i2s(T x) { ostringstream o; o<<x; return o.str(); }
int s2i(string x) {int r=0;istringstream sin(x);sin>>r;return r; }
template<class T>
inline void _min(T &mn, T x)
{
	if(mn > x) mn=x;
}
template<class T>
inline void _max(T &mx, T x)
{
	if(mx < x) mx=x;
}
#define sci(a) scanf("%d",&a)
#define scc(a) scanf("%c",&a)
#define scl(a) scanf("%lld",&a)
#define scf(a) scanf("%lf",&a)
#define scs(a) scanf("%s",a)
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})

/*******************/
int a[555];
void solve()
{
	
	VVI v(2000001);
	int i,n,j,k,x,y;
	n=SS;
	FOR(i,0,n){
		a[i]=SS;
	}
	int sum=0;
	for(i=1; i<(1<<n)-1; i++){
		sum=0;
		for(j=0; j<n; j++){
			if(i&(1<<j)){
				sum+=a[j];
			}
		}
		v[sum].PB(i);
	}
	VI ans1,ans2;
	for(i=0; i<2000001; i++){
		for(j=0; j<v[i].sz; j++)
			for(k=j+1; k<v[i].sz; k++)
				if(v[i][j]&v[i][k] == v[i][j]^v[i][k])
				{
					//cout<<i<<endl;
					for(x=0; x<n; x++)
						if(v[i][j]&(1<<x))
							ans1.PB(a[x]);
					for(x=0; x<n; x++)
						if(v[i][k]&(1<<x))
							ans2.PB(a[x]);
					for(x=0; x<ans1.sz-1; x++)
						printf("%d ",ans1[x]);
					printf("%d\n",ans1[x]);
					
					for(x=0; x<ans2.sz-1; x++)
						printf("%d ",ans2[x]);
					printf("%d\n",ans2[x]);
					return;
				}
	}
}
int main()
{
	int t,test;
	scanf("%d\n",&test);
	for(int t=1; t<=test; t++)
	{
		printf("Case #%d:\n",t);
		solve();
	}
	return 0;
}
