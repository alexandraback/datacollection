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
int a[222];
void solve()
{
	int i,n;
	
	n=SS;
	int sum=0;
	for(i=0; i<n; i++)
	{
		a[i]=SS;
		sum+=a[i];
	}
	double xx=2.0*sum/(double)n;
	int sum1=0,nn=0;
	bool flag=false;
	for(i=0; i<n; i++)
		if(xx-a[i]<0)
			flag=true;
		else
		{
			sum1+=a[i];
			nn++;
		}
	if(!flag)
	{
		for(i=0; i<n; i++){
			double x=xx-a[i];
			x=x*100/(double)sum;
			if(i<n-1)
				printf("%lf ",x);
			else
				printf("%lf\n",x);
		}
	}
	else
	{
		vector<double> ans;
		double ad=0;
		double yy=(double)(sum+sum1)/(double)nn;
		//cout<<sum<<" "<<sum1<<" "<<yy<<endl;
		for(i=0; i<n; i++){
			if(xx-a[i]<0)
				ans.PB(0.0);
			else{
				double x=sum+sum1-a[i]*nn;
				x=x*100.0/(double)(sum*nn);
				ans.PB(x);
			}
		}
		for(i=0; i<n-1; i++){
			printf("%lf ",ans[i]);
			ad+=ans[i];
		}
		printf("%lf\n",ans[i]);
		ad+=ans[i];
		//cout<<nn<<"totat="<<ad<<endl;
	}
	
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
