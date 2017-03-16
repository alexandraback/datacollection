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

const double eps=1e-9;

void solve();

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,i,j,cs,n,k,p,q;
	cin>>T; 
	for (cs=1;cs<=T;cs++)
	{
		printf("Case #%d: \n",cs);solve();
	}
	return 0;
}


map<int,vector<int> > mp;

void solve()
{
	mp.clear();
	int i,j,k,n;
	cin>>n;
	int a[20];
	REP(i,n) cin>>a[i];
	for (k=1;k<(1<<20);++k)
	{
		int t=0;
		REP(i,20) if ((1<<i)&k) t+=a[i];
		if (!mp[t].empty())
		{
			vector<int> v=mp[t];
			REP(i,v.size())
			{
				int p;
				REP(p,20)
				{
					if ((v[i]&(1<<p))&&(k&(1<<p))) break;
				}
				if (p==20)
				{
					vector<int> r;
					REP(p,20) if (k&(1<<p)) r.push_back(a[p]);
					REP(p,r.size()-1) cout<<r[p]<<" ";cout<<r[r.size()-1]<<endl;
					r.clear();
					REP(p,20) if (v[i]&(1<<p)) r.push_back(a[p]);
					REP(p,r.size()-1) cout<<r[p]<<" ";cout<<r[r.size()-1]<<endl;
					return ;
				}
				else mp[t].push_back(k);
			}
		}
		else mp[t].push_back(k);
	}
	cout<<"Impossible"<<endl;
}
/*
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
