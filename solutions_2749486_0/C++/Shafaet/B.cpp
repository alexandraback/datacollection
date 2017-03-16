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
#define pks printf("Case #%d: ",++ks);


int d[5502][5502];

int fx[]={0,0,+1,-1};
int fy[]={+1,-1,0,0};
struct node
{
	int x,y;
	node(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
	node(){}
};
int off=2300;
void mvis(int x,int y)
{
	x+=off;
	y+=off;
	d[x][y]=0;
}
node par[5502][5502];
void bfs(int dx,int dy)
{
	mem(d,63);
	queue<node>q;
	q.push(node(0,0));
	mvis(0,0);
	while(!q.empty())
	{
		node top=q.front(); q.pop();
		if(top.x==dx and top.y==dy) break;
		rep(k,4)
		{
			int tx=top.x+ fx[k]*(d[top.x+off][top.y+off]+1);
			int ty=top.y+ fy[k]*(d[top.x+off][top.y+off]+1);
			
			
			if(tx>=-2000 and tx<=2000 and ty>=-2000 and ty<=2000)
			{
				
				if(d[top.x+off][top.y+off]+1<d[tx+off][ty+off])
				{
					
					
					d[tx+off][ty+off]=d[top.x+off][top.y+off]+1;
					par[tx+off][ty+off]=node(top.x,top.y);
					q.push(node(tx,ty));
				}
			}
		}
	}
}
string out;
void print(int x,int y)
{
	
	if(!x and !y) return;
	int px=par[x+off][y+off].x;
	int py=par[x+off][y+off].y;
	
	print(px,py);
	if(y>py) out+="N";
	if(y<py) out+="S";
	
	if(x>px) out+="E";
	if(x<px) out+="W";
	//cout<<px<<" "<<py<<" "<<x<<" "<<y<<endl;
}
int main()
{
	READ("in");
	WRITE("myBOUTTTTTTTT");
	int t,ks=0;
	cin>>t;
	while(t--)
	{
		out="";
		int x,y;
		cin>>x>>y;
		bfs(x,y);
		print(x,y);
		pks;
		cout<<out<<endl;
	}
	return 0;
}
