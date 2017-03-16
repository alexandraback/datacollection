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
#include <tuple>
using namespace std;

#define PB push_back
#define MP make_pair

#define rep(i,n) for(int i=0;i<(n);++i)
#define REP(i,n) for(int i=1;i<=(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define print(expr) cout<<(#expr)<<" : "<<(expr)<<endl

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;
typedef pair<int,int> pii;
#define tr(it,c) for(auto it=(c).begin(); it!=(c).end(); ++it)
#define all(c) (c).begin(), (c).end()

void setIO(string s)
{
	string inF=s+".in";
	string outF=s+".out";
	freopen(inF.c_str(),"r",stdin);
	freopen(outF.c_str(),"w",stdout);
}

void solve(void);
int main(void)
{
	setIO("D-small-attempt0");
	int T; cin>>T;
	REP(Case,T)
	{
		cout<<"Case #"<<Case<<": ";
		solve();
	}
}

inline int sqr(int t){return t*t;}

int gcd(int a,int b) {return b==0 ? a :gcd(b,a%b);}

void simp(pii &a)
{
	//if(a.second<0) a.first=-a.first, a.second=-a.second;
	int g=gcd(abs(a.first),abs(a.second));
	a.first/=g; a.second/=g;
}

char buf[100][100];

void solve()
{
	set<pii> s;		
	int h,w,d;
	cin>>h>>w>>d;
	rep(i,h) cin>>buf[i];
	int si=0, sj=0;
	rep(i,h) rep(j,w) if(buf[i][j]=='X') si=i-1,sj=j-1;
	si=si*2+1;
	sj=sj*2+1;
	h-=2; w-=2;
	FOR(i,-100,100) FOR(j,-100,100) if(i && j)
	{
		int di,dj;
		if(i%2==0) di=i*h;
		else
		{
			di=(i/2)*2*h;
			if(i<0) di-=si;
			else di+=2*h-si;
		}
		if(j%2==0) dj=j*w;
		else
		{
			dj=(j/2)*2*w;
			if(j<0) dj-=sj;
			else dj+=2*w-sj;
		}
		/*if(abs(i)<3 &&abs(j)<3)
		{
			cout<<"-----------------"<<endl;
			print(i); print(j); print(di); print(dj);
			cout<<"-----------------"<<endl;
		}*/
		if(sqr(di)+sqr(dj)<=sqr(d))
		{
			pii tmp=MP(di,dj);
			simp(tmp);
			if(j) s.insert(tmp);
		}
	}
	int ans=s.size();
	if(d>=h) ans+=2;
	if(d>=w) ans+=2;
	cout<<ans<<endl;
}