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
#define tr(it,c) for(auto it=(c).begin(); it!=(c).end(); ++it)
#define all(c) (c).begin(), (c).end()

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;
typedef pair<int,int> pii;

int a[100], b[100], ans[100];
int T;

void setIO(string s)
{
	string inF=s+".in";
	string outF=s+".out";
	freopen(inF.c_str(),"r",stdin);
	freopen(outF.c_str(),"w",stdout);
}

string toString(int s)
{
	ostringstream out; out<<s; return out.str();
}

int toInt(string s)
{
	istringstream in(s);
	int res; in>>res;
	return res;
}

void deal(int n)
{
	string s=toString(n);
	int l=s.size();
	set<int> se;
	REP(x,l-1)
	{
		string ns=s.substr(x)+s.substr(0,x);
		if(ns[0]!='0')
		{
			int p=toInt(ns);
			if(n<p) se.insert(p);
		}
	}
	tr(it,se)
	{
		rep(i,T) if(a[i]<=n && *it<=b[i]) ++ans[i];
	}
}


int main(void)
{
	setIO("C-large");
	cin>>T;
	rep(i,T) cin>>a[i]>>b[i];
	FOR(i,1,2000000) deal(i);
	rep(i,T) cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
}
