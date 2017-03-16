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
	setIO("B-large");
	int T; cin>>T;
	REP(Case,T)
	{
		cout<<"Case #"<<Case<<": ";
		solve();
	}
}

const int maxn=3000;
int buf[maxn][2];
bool vis[maxn][2];
int star=0;

void solve()
{
	int n; cin>>n;
	rep(i,n) cin>>buf[i][0]>>buf[i][1];
	memset(vis,false,sizeof vis);
	star=0;
	int ans=0;
	while(star<n+n)
	{
		bool tag=false;
		rep(i,n) if(!vis[i][1] && star>=buf[i][1])
		{
			if(!vis[i][0]) ++star, vis[i][0]=true;
			++star; vis[i][1]=true;
			tag=true; ++ans; break;
		}
		if(tag) continue;
		int no=-1, b=-1;
		rep(i,n) if(!vis[i][0] && star>=buf[i][0] && b<buf[i][1]) b=buf[no=i][1];
		if(no==-1)
		{
			cout<<"Too Bad"<<endl; return;
		}
		++star; vis[no][0]=true; ++ans;
	}
	cout<<ans<<endl;
}