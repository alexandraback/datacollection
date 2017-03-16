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
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
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
int res;
bool w=false;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B3.out","w",stdout);
	int T,i,j,l,n,k,p,q;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		solve();
		printf("Case #%d: ",l);
		if (!w) printf("%d\n",res);
		else cout<<"Too Bad"<<endl;
	}
	return 0;
}

int a[2000],b[2000];
bool f[2000],g[2000];
void solve()
{
	int i,k,j,n;
	cin>>n;
	REP(i,n) cin>>a[i]>>b[i];
	REP(i,n) f[i]=g[i]=false;
	int m=n;
	int s=0;
	res=0;
	w=false;
	while (m)
	{
		bool flag=false;
		REP(i,n) if (!g[i]&&s>=b[i])
		{
			if (f[i]) s+=1;
			else s+=2;
			res++; 
			g[i]=true;
			flag=true; m--;
		}
		if (flag) continue;
		int t=-1,d=-1;
		REP(i,n) 
		{
			if (!f[i]&&!g[i]&&s>=a[i])
			{
				if (b[i]>t) 
				{
					t=b[i];
					d=i;
				}
			}
		}
		if (t>-1)
		{
			s+=1;
			f[d]=flag=true; res++;
		}
		else
		{
			w=true; 
			return ;
		}
	}
}


