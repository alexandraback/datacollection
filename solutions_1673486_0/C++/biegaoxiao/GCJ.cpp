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
double res;
int main()
{
	freopen("A-small-attempt5.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,i,j,l,n,k,p,q;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		solve();
		printf("Case #%d: ",l); printf("%.6f\n",res);
	}
	return 0;
}

double p[100002];
void solve()
{
	int i,k,j,n,a,b;
	cin>>a>>b;
	REP(i,a) cin>>p[i];
	double ans=b+2;
	double q=1;
	for(i=a;i>=0;i--)
	{
		double s=0;
		s=(b-a+1+2*i)*q+(2*b-a+2+i*2)*(1-q);
		if (a>0) q*=p[a-i];
		if (s<ans) ans=s;
//		cout<<s<<endl;
	}
	res=ans;
}


