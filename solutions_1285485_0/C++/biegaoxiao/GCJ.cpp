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

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int T,i,j,l,n,k,p,q;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		int h,w,ans=0;
		double d;
		cin>>h>>w>>d;
		vector<string> mr;
		string s;
		REP(i,h)
		{
			cin>>s;
			mr.push_back(s);
		}
		double ox,oy;
		REP(i,h) REP(j,w) if (mr[i][j]=='X') ox=j-0.5,oy=i-0.5;
		h-=2;w-=2;
		double hd[]={2*(h-oy),2*oy};
		vector<PDD> pts;
		double x,y;
		x=ox,y=oy;
		int num=100;
		pts.push_back(PDD(ox,oy));
		REP(i,num)
		{
			y+=hd[i%2];
			pts.push_back(PDD(x,y));
		}
		x=ox,y=oy;
		REP(i,num)
		{
			y-=hd[(i+1)%2];
			pts.push_back(PDD(x,y));
		}
		double wd[]={2*(w-ox),2*ox};
		n=pts.size();
		REP(k,n)
		{	
			x=pts[k].first; y=pts[k].second;
			REP(i,num)
			{
				x+=wd[i%2]; pts.push_back(PDD(x,y));
			}
			x=pts[k].first; y=pts[k].second;
			REP(i,num)
			{
				x-=wd[(i+1)%2]; pts.push_back(PDD(x,y));
			}
		}
		set<pair<int,double> > sp;
		d*=d;
		REP(k,pts.size())
		{
			if (k==0) continue;
			x=pts[k].first; y=pts[k].second;
			if ((x-ox)*(x-ox)+(y-oy)*(y-oy)>=d+eps) continue;
			double kv;
			if (fabs(x-ox)<eps) kv=1e20*(y>oy?1:-1);
			else kv=(y-oy)/(x-ox);
			int f=0;
			if (x>=ox+eps)
			{
				if (y>=oy+eps) f=0;
				else f=1;
			}
			else
			{
				if (y>=oy+eps) f=2;
				else f=3;
			}
			sp.insert(pair<int,double>(f,kv));
		}
//		set<double>::iterator it;
//		FORIT(it,sp) cout<<*it<<endl;
		ans=sp.size();
		printf("Case #%d: ",l); cout<<ans<<endl;
//		return 0;
	}
	return 0;
}



/*
const int M=2000001;
bool fg[M];
map<int,vector<int> > mp;
int d[]={1,10,100,1000,10000,100000,1000000,10000000};
vector<int> f(int n)
{
	int i,j,num=0,a=n;
	while (a)
	{
		num++;
		a/=10;
	}
	set<int> sp;
	vector<int> ans;
	REP(i,num)
	{
		a=n/d[i]+(n%d[i])*d[num-i];
		if (a>=d[num-1]&&a<M) sp.insert(a);
	}
	set<int>::iterator it;
	FORIT(it,sp) ans.push_back(*it);
	return ans;
}



int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,i,j,l,n,k,p,q,s;
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		cin>>n>>s>>p;
		int a[200];int ans=0;
		REP(i,n) cin>>a[i];
		REP(i,n)
		{
			q=a[i];
			if (q>=3*p-2)
			{
				ans++;
				continue;
			}
			if (q>=3*p-4&&p>1&&s>0)
			{
				s--;
				ans++;
			}
		}
		
		printf("Case #%d: ",l); cout<<ans<<endl;
	}
	return 0;
}


string s1=" qzejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
string s2=" zqourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
map<char,char> mp;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,i,j,l,n,k,p,q;
	REP(i,s1.size()) mp[s1[i]]=s2[i]; 
	cin>>T; 
	string s;
	getline(cin,s);
	for (l=1;l<=T;l++)
	{
		string ans;
		getline(cin,ans);
		REP(i,ans.size())  ans[i]=mp[ans[i]];
		printf("Case #%d: ",l); cout<<ans<<endl;
	}
	return 0;
}
*/