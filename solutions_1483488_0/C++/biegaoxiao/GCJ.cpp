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
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,i,j,l,n,k,p,q,s;
	for (k=10;k<M;k++)
	{
		if (fg[k]) continue;
		vector<int> &now=f(k);
		if (now.size()>1) 
		{
			mp[k]=now;
			REP(i,now.size()) fg[now[i]]=true;
		}
	}
	
	cin>>T; 
	for (l=1;l<=T;l++)
	{
		int A,B;
		cin>>A>>B;
		ll ans=0;
		map<int,vector<int> >::iterator it;
		for (it=mp.begin();it!=mp.end() && it->first<B;it++)
		{
			vector<int> &now=it->second;
			p=0;
			REP(i,now.size())
			{
				if (now[i]>=A&&now[i]<=B) p++;
			}
			if (p>1) ans+=p*(p-1)/2;
		}
		
		printf("Case #%d: ",l); cout<<ans<<endl;
	}
	return 0;
}

/*
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