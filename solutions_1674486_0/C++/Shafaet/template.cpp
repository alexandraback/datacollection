#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
typedef long long i64;
typedef unsigned long long ui64;
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair


using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return 
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return 
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }


#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E16;


int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
double dist2d(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(long long a){if(a==0) return "0";string ret;for(long long i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(ret.begin(),ret.end());return ret;}

vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;}

//bool operator < ( const node& p ) const {      return w < p.w;   }
int isvowel(char s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=reset(N,pos);return N=Set(N,pos);}
void pbit(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}

#define mx 1002
vector<int>g[mx];

bool vis[mx];
vector<int>order;
void top(int  u)
{
	if(!vis[u])
	{
		vis[u]=1;
		rep(i,g[u].size())
		top(g[u][i]);
		order.pb(u);
		
	}
	
}
int flag=0;
void dfs(int u)
{
	rep(i,g[u].size())
	{
		int v=g[u][i];
		if(vis[v]) flag=1;
		else
		{
			vis[v]=1;
			dfs(v);
		}
		
	}
	
	
}
int main()
{	
	READ("in");
	WRITE("AOO.txt");
	int kas=0;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			int q;
			cin>>q;
			for(int j=0;j<q;j++)
			{
				int u=i;
				int v;
				cin>>v;
				g[u].pb(v);
				
				
			}
		}
		mem(vis,0);
		order.clear();
		for(int i=1;i<=n;i++)
		top(i);
		reverse(all(order));
		
		mem(vis,0);
		flag=0;
		rep(i,order.size())
		{
			int u=order[i];
			if(vis[u]==0)
			{
				vis[u]=1;
				dfs(u);
				mem(vis,0);
				
			}
		}
		printf("Case #%d: ",++kas);
		if(!flag) puts("No");
		else puts("Yes");
		
	}
	
}
