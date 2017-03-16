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
#define SSL ({lint x;scanf("%lld", &x);x;})

/*******************/

lint a[111],b[111],bb[111],A[111],B[111];
lint m,n;
lint min(lint a,lint b){
	if(a<b)
		return a;
	return b;
}
lint get(lint x,lint y,lint aa,lint AA){
	lint i,sum=0;
	if(x>y) return 0;
	
	//printf("x=%d y=%d aa=%d type=%d\n",x,y,aa,AA);
	
	i=x;
	while(i<=y){
		if(B[i]==AA){
			sum+=min(aa,bb[i]);
			lint tmp=min(aa,bb[i]);
			bb[i]=bb[i]-tmp;
			aa-=tmp;
		}
		else
			i++;
		if(aa==0)
			break;
		if(bb[i]==0)
			i++;
	}
//	printf("%d %d type=%d sum=%d\n",x,y,AA,sum);
	return sum;
}
void solve()
{
	lint i,j,k,x,y,z,ii;
	
	n=SSL;m=SSL;
	for(i=1; i<=n; i++)
	{
		a[i]=SSL;
		A[i]=SSL;
	}
	for(i=1; i<=m; i++)
	{
		b[i]=SSL;B[i]=SSL;
	}
	if(n==2)
	{	
		a[3]=0;
		A[3]=A[2];
	}
	else if(n==1)
	{
		a[2]=a[3]=0;
		A[2]=A[3]=A[1];
	}
	n=3;
	//x=get(1,m,a[1],A[1]);
	//y=get(1,m,a[2],A[2]);
	//z=get(1,m,a[3],A[3]);
	
	
	//printf("%d %d %d\n",x,y,z);
	//x=max(x,max(y,z));
	x=0;
	for(i=0; i<=m; i++)
		for(j=i; j<=m; j++)
		{
				FOR(ii,1,m+1)
				 bb[ii]=b[ii];
				 
				y=get(1,i,a[1],A[1])
				  +get(i,j,a[2],A[2])
				  +get(j,m,a[3],A[3]);
		//		cout<<y<<endl;
				x=max(x,y);
		}
	printf("%lld\n",x);
}
int main()
{
	int t,test;
	scanf("%d\n",&test);
	for(int t=1; t<=test; t++)
	{
		printf("Case #%d: ",t);
		solve();
	}
	return 0;
}
