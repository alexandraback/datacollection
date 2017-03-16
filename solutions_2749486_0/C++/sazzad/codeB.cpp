
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <limits>
#include <utility>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace std;

const int INF=(1<<30)-1;
const long long LINF=(1ll<<62)-1;
const int DIRX[]={-1,0,0,1,-1,-1,1,1}, DIRY[]={0,-1,1,0,-1,1,-1,1};
const double ERR=1e-11, PI=(2*acos(0.0));

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
template<class T> inline T MIN(T a,T b) {return ((a<b)?(a):(b));}
template<class T> inline T MAX(T a,T b) {return ((b<a)?(a):(b));}
template<class T> inline T ABS(T a) {return ((a<0)?(-a):(a));}
template<class T> inline void checkMIN(T& a,T b) {if(b<a) a=b;}
template<class T> inline void checkMAX(T& a,T b) {if(a<b) a=b;}
template<class T> inline T SQR(T x) {return (x*x);}
template<class T> inline T GCD(T a,T b) {T c; while((c=a%b)!=0)a=b,b=c; return b;}
template<class T> inline T fastPow(T Base,T Power) {T Result=1; while(Power>0){if(Power&1)Result*=Base; Power>>=1; Base*=Base;} return Result;}
template<class T> inline T fastModPow(T Base,T Power,T Mod) {T Result=1;while(Power>0){if(Power&1)Result=(Result*Base)%Mod; Power>>=1; Base=(Base*Base)%Mod;} return (Result%Mod);}
inline int compDouble(double x,double y) {double d=x-y; if(d-ERR>0.0) return 1; else if(d+ERR<0.0) return -1; else return 0;}

#define ALL(X)       (X).begin(),(X).end()
#define Size(X)      ((int)(X).size())
#define MEM(X,with)  memset((X),(with),sizeof(X))
#define EACH(X,itr)  for( __typeof((X).begin()) itr=(X).begin(); itr!=(X).end(); itr++)
#define Contains(X,item)    ((X).find(item)!=(X).end())
#define Contains_n(X,item)	(find((X).begin(),(X).end(),(item))!=(X).end())
#define PB  push_back
#define MP  make_pair
#define fs  first
#define sc  second

typedef unsigned long long ULL;
typedef long long      LL;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL>     VL;
typedef vector<int>    VI;
typedef pair<int,int>  Pii;

#define sz 1000009

map<Pii,char> md;
map<Pii,int> mv;

void bfs(int X,int Y)
{
	int x,y,v;
	Pii p=MP(0,0);
	queue<Pii> q;
	md.clear();
	mv.clear();
	
	q.push(p);
	md[p]=' ';
	mv[p]=0;
	
	while(!q.empty())
	{
		x=q.front().fs;
		y=q.front().sc;
		if(x==X && y==Y) return;
		q.pop();
		
		v=mv[MP(x,y)];
		
		// N
		p=MP(x,y+(v+1));
		if(MAX(ABS(p.fs),ABS(p.sc))<250)
		if(!Contains(mv,p))
		{
			q.push(p);
			md[p]='N';
			mv[p]=v+1;
		}
		
		// S
		p=MP(x,y-(v+1));
		if(MAX(ABS(p.fs),ABS(p.sc))<250)
		if(!Contains(mv,p))
		{
			q.push(p);
			md[p]='S';
			mv[p]=v+1;
		}
		
		// E
		p=MP(x+(v+1),y);
		if(MAX(ABS(p.fs),ABS(p.sc))<250)
		if(!Contains(mv,p))
		{
			q.push(p);
			md[p]='E';
			mv[p]=v+1;
		}
		
		// W
		p=MP(x-(v+1),y);
		if(MAX(ABS(p.fs),ABS(p.sc))<250)
		if(!Contains(mv,p))
		{
			q.push(p);
			md[p]='W';
			mv[p]=v+1;
		}
	}
}

char ans[sz];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int kases;scanf("%d",&kases);
	//string ans;
	int X,Y;
	Pii p;
	int v;
	
	for(int kase=1;kase<=kases;kase++)
	{
		cerr<<kase<<endl;
		
		scanf(" %d %d",&X,&Y);
		bfs(X,Y);
		
		p=MP(X,Y);
		v=mv[p];
		ans[v]=0;
		
		while(v>0)
		{
			ans[v-1]=md[p];
			//cerr<<v<<", "<<ans[v-1]<<endl;
			
			if(ans[v-1]=='N') p.sc-=v; else
			if(ans[v-1]=='S') p.sc+=v; else
			if(ans[v-1]=='E') p.fs-=v; else
			if(ans[v-1]=='W') p.fs+=v;
			
			v=mv[p];
		}
		
		cout<<"Case #"<<kase<<": "<<ans<<endl;
	}
	
	return 0;
}
