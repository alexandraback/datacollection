#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <assert.h>
 
#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
 
#define SZ(x) (int)x.size()
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second
using namespace std;
template<class T> inline T sqr(T x){return x*x;}
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;
}
#define on(n,pos) n=(n | (1<<pos))
#define off(n,pos) n= n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}
//bool operator < ( const node& p ) const {      return w < p.w;   }
 
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
 
#define mx 1002

int savlast;
int diff(char *s,string &w,int last)
{
	int c=0;
	
	for(int i=0;s[i];i++)
	{
		last++;
		if(s[i]==w[i]) continue;
		if(s[i]!=w[i]){
			if(last<5)	return 1<<28;
			last=0;
		}
		c+=(s[i]!=w[i]);
	}
	savlast=last;
	return c;
}
//int sendlast;
vector<string>sav[12];
/*
int match(char *w,int len,int last)
{

	int mn=1<<28;
	rep(i,SZ(sav[len]))
	{
		int ret=diff(w,sav[len][i],last);
		if(ret<mn)
		{
			mn=ret;
			sendlast=savlast;
		}
	}
	return mn;
}*/
#define pks printf("Case #%d: ",++ks);
string w;
int dp[52][7];
int call(int idx,int last)
{
		if(idx==SZ(w)) return 0;
		if(dp[idx][last]!=-1) return dp[idx][last];
		char temp[22];
		int len=0,ans=1<<28;
		for(int j=idx;j<SZ(w);j++)
		{
			if(len>10) break;
			temp[len]=w[j];
			temp[len+1]=0;
			rep(k,SZ(sav[len+1]))
			{
				int cc=diff(temp,sav[len+1][k],last);
				
				if(cc!=1<<28)
				{
					if(savlast>5) savlast=5;
					int get=cc+call(j+1,savlast);
					ans=min(ans,get);
				}
			}
			
			//int get=match(temp,len+1,last);
			
			
			len++;
		}
		return dp[idx][last]=ans;
}
int main()
{
	READ("in");
	WRITE("ccccsmall66");
	FILE *fp=fopen("dic.txt","r");
	char sp[100];
	while(fscanf(fp,"%s",sp)==1)
	{
		int len=strlen(sp);
		sav[len].pb(sp);
		
	}
	int t,ks=0;
	cin>>t;
	while(t--)
	{
		mem(dp,-1);
		cin>>w;
		int ans=call(0,5);
		pks;
		cout<<ans<<endl;
	}
	return 0;
}
