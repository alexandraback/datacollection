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
#define pks printf("Case #%d:",++ks);
using namespace std;
template<class T> inline T sqr(T x){return x*x;}
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef long long i64;
typedef unsigned long long ui64;
double log(double N,double B){	return (log10l(N))/(log10l(B));	}
vector< string > token(char *a,char *b) {vector<string>v; char *p=strtok(a," "); while(p) {v.pb(p);p=strtok(NULL," ");} return v;}
vector<string>token(string a,char *b){char temp[100002]; strcpy(temp,a.c_str()); return token(temp,b);       }


//bool operator < ( const node& p ) const {      return w < p.w;   }
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};


#define on(n,pos) n=(n | (1<<(pos)))
#define off(n,pos) n= n & ~(1<<(pos))
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,4)s+=(isOn(n,i)+'0');return s;}

#define mx 55

vector<int>pro;
bool eval(string &s)
{
	int ache[7*7*7]={0};
	int n=SZ(s);
	vector<int>v;
	rep(i,1<<n)
	{
		int p=1;
		rep(j,n)
		if(isOn(i,j)) p*=(s[j]-'0');
		
		ache[p]=1;
	}
	rep(i,SZ(pro)){
		 if(!ache[pro[i]]) return 0;
	 }
	return 1;
}
vector<string>sav;
int r,n,m,k;
string s;
void gen()
{
	if(SZ(s)==n)
	{
		sav.pb(s);
		//cout<<s<<endl;
		return;
	}
	for(int i=2;i<=m;i++)
	{
		s+=i+'0';
		gen();
		s.erase(s.end()-1);
	}
}
int main()
{
	READ("in");
	WRITE("CoutSmall");
	//WRITE("CoutLarge");
	
	int t,ks=0;
	cin>>t;
	while(t--)
	{
		sav.clear();
		cin>>r>>n>>m>>k;
		gen();
		pks;
		puts("");
		rep(st,r)
		{
			pro.clear();
			rep(i,k)
			{
				int x;
				cin>>x;
				pro.pb(x);
			}
			string ans;
			rep(i,n)
			ans+="2";
			rep(i,SZ(sav))
			{
				
				if(eval(sav[i]))
				{
					ans=sav[i];
				}
			}
			cout<<ans<<endl;
		}
	}
	
}
