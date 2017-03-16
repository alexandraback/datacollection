#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())


#define debugger cerr
#define debug(args...)			{mdbg,args; debugger<<endl;}
#define PRINT_CONTAINER(o,v)    {if(v.size()==0) return o<<"{}"; o<<"{"; foreach(it,v) o<<*it<<" "; return o<<"\b}";}
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}} mdbg;
template<class T> ostream& operator << (ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator << (ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const pair<A,B> &p) {o<<"("<<p.first<<","<<p.second<<")"; return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; for(int i=0;i<n;i++) debugger<<v[i]<<" "; debugger<<"\b}"<<endl;}


typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<TRI> VT;




/*Main code begins now */
int testnum;


char grid[5][10];

int status(bool x, bool o, bool t, bool dot) {
	if(!o && !dot) {
		printf("X won\n");
		return 1;
	}
	if(!x && !dot) {
		printf("O won\n");
		return 2;
	}
	return 0;
}

void solve()
{
	bool x,o,t,dot;
	int ans;
	for(int i=0;i<4;i++) {
		x=false;
		o=false;
		t=false;
		dot=false;
		
		for(int j=0;j<4;j++) {
			if(grid[i][j]=='.') dot=true;
			if(grid[i][j]=='X') x=true;
			if(grid[i][j]=='O') o=true;
			if(grid[i][j]=='T') t=true;
		}
		
		ans = status(x,o,t,dot);
		if(ans) return;

		x=false;
		o=false;
		t=false;
		dot=false;
		
		for(int j=0;j<4;j++) {
			if(grid[j][i]=='.') dot=true;
			if(grid[j][i]=='X') x=true;
			if(grid[j][i]=='O') o=true;
			if(grid[j][i]=='T') t=true;
		}
		
		ans = status(x,o,t,dot);
		if(ans) return;
	}
	
	x=false;
	o=false;
	t=false;
	dot=false;
	for(int i=0;i<4;i++) {
		if(grid[i][i]=='.') dot=true;
		if(grid[i][i]=='X') x=true;
		if(grid[i][i]=='O') o=true;
		if(grid[i][i]=='T') t=true;
	}
	ans = status(x,o,t,dot);
	if(ans) return;
	
	x=false;
	o=false;
	t=false;
	dot=false;
	for(int i=0;i<4;i++) {
		if(grid[i][3-i]=='.') dot=true;
		if(grid[i][3-i]=='X') x=true;
		if(grid[i][3-i]=='O') o=true;
		if(grid[i][3-i]=='T') t=true;
	}
	ans = status(x,o,t,dot);
	if(ans) return;
	
	dot=false;
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			if(grid[i][j]=='.') {
				printf("Game has not completed\n");
				return;
			}
		}
	}
	
	printf("Draw\n");
		
	
}

bool input()
{
	for(int i=0;i<4;i++) {
		ss(grid[i]);
	}
	printf("Case #%d: ", testnum);
	return true;
}


int main()
{
	int T; s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}
