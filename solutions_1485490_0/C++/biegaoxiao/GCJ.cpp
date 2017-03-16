#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T gcd(T a,T b){return a==0?b:gcd(b%a,a);}
template<class T> inline int countbit(T n){return n==0?0:(1+countbit(n&(n-1)));}
template<class T> inline void pout(T A[],int n){cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}
template<class T> inline void pout(vector<T> A,int n=-1){if (n==-1) n=A.size();cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,cs,h) for(i=(cs);i<=(h);++i)
#define FORD(i,h,cs) for(i=(h);i>=(cs);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;



void solve();
ll ans;

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,i,j,cs,n,k,p,q;
	cin>>T; 
	for (cs=1;cs<=T;cs++)
	{
		printf("Case #%d: ",cs); solve();cout<<ans<<endl;
	}
	return 0;
}


const int NN=200;
ll aa[NN],A[NN],bb[NN],B[NN];


map<PII,ll> mp;
ll f(vector<ll> a, vector<ll> b,int n,int m)
{
	
	if (n<0||m<0) return 0;
//	if (mp.find(PII(n,m))!=mp.end()) return mp[PII(n,m)];
	if (A[n]==B[m])
	{
		if (a[n]<b[m])
		{
			b[m]-=a[n];
			return mp[PII(n,m)]=a[n]+f(a,b,n-1,m);
		}
		else
		{
			a[n]-=b[m];
			return mp[PII(n,m)]=b[m]+f(a,b,n,m-1);
		}
	}
	return mp[PII(n,m)]=max(f(a,b,n-1,m),f(a,b,n,m-1));
}
void solve()
{
	mp.clear();
	ans=0;
	int i,k,j,n,m;
	cin>>n>>m;
	REP(i,n) cin>>aa[i]>>A[i];
	REP(i,m) cin>>bb[i]>>B[i];
	vector<ll> a,b;
	REP(i,n) a.push_back(aa[i]);
	REP(i,m) b.push_back(bb[i]);
	ans=f(a,b,n-1,m-1);
}


/*
const double eps=1e-9;



bool solve();

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,i,j,cs,n,k,p,q;
	cin>>T; 
	for (cs=1;cs<=T;cs++)
	{
		printf("Case #%d: ",cs);
		if (solve()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}


const int N=1001;
int a[N][N];
vector<vector<int> > vs;
bool f(int i,int j)
{
//	cout<<i<<" "<<j<<endl;
	if (i==j) return false;
	if (a[i][j]>=0) return a[i][j];
	int k;
	REP(k,vs[i].size())
	{
		if (f(vs[i][k],j)) return a[i][j]=1;
	}
	return a[i][j]=0;
}
bool solve()
{
	vs.clear();
	
	int i,j,k,n,m,p;
	cin>>n;
	REP(i,n) REP(j,n) a[i][j]=-1;
	REP(i,n)
	{
		cin>>m;
		vector<int> vi;
		REP(j,m) 
		{
			cin>>k;
			k--;
			vi.push_back(k);
			a[i][k]=1;
		}
		vs.push_back(vi);
	}
//	cout<<"ok"<<endl;
	REP(i,n) REP(j,n)
	{
	//	cout<<i<<" "<<j<<endl;
		if (j==i) continue;
		int sum=0;
		REP(k,vs[i].size())
		{
			if (f(vs[i][k],j)||vs[i][k]==j)
			{
				sum++;
				if (sum>1) return true;
			}
		}
	}
	return false;

}












void solve()
{
	int i,k,j,n;
	double a[300];
	cin>>n;
	REP(i,n) cin>>a[i];
	double x=0;
	REP(i,n) x+=a[i];
	REP(i,n)
	{
		double y1=0,y2=1;
		REP(k,100)
		{
			double y=(y1+y2)/2;
			double sum=0;
			double p=a[i]+x*y;
			REP(j,n)
			{
				if (j!=i)
				{
					double yj=(a[i]-a[j])/x+y;
					if (yj<0) yj=0;
					sum+=yj;
				}
			}
			if (sum>1-y-eps) y2=y;
			else y1=y;
		}
		printf("%.6f",(y1+y2)/2*100);
		if (i<n-1) cout<<" ";
		else cout<<endl;
	}
}




*/
