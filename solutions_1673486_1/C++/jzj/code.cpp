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
	setIO("A-large");
	int T; cin>>T;
	REP(Case,T)
	{
		cout<<"Case #"<<Case<<": ";
		solve();
	}
}

const int maxn=100050;
double p[maxn];
double pro[maxn];
int A,B;
double ans;

void solve()
{
	cin>>A>>B; pro[0]=1;
	REP(i,A) cin>>p[i], pro[i]=pro[i-1]*p[i];
	ans=min( pro[A]*(B-A+1) + (1.-pro[A])*(B+B-A+2),
		double(B+2));
	REP(s,A-1) ans=min(ans, pro[s]*(A+B+1-s-s) + (1.-pro[s])*(A+B+B+2-s-s));
	printf("%.20lf\n",ans);
}