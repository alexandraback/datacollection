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
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
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
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl	

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}





typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;


/*Main code begins now */

int testnum;
int N;
int spd[50];
int pos[50];

struct event
{
	double t;
	bool add;
	int u,v;
	
	event() {}
	
	event(double _t, bool _add, int _u, int _v)
	{
		t=_t;
		add=_add;
		u=_u;
		v=_v;
	}
};

bool operator < (event a,event b)
{
	bool equals = (abs(a.t-b.t) < EPS);
	if(!equals)
		return a.t < b.t;
	else
	{
		if(!a.add && b.add) return true;
		if(a.add && !b.add) return true;
		if(a.u != b.u) return a.u < b.u;
		return a.v < b.v;
	}
}

vector<event> q;
bool adj[50][50];
bool side[50];


void solve()
{
	fill(adj,false);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(j==i) continue;
			double d = abs(pos[i]-pos[j]);
			if(d<5-EPS)
				adj[i][j]=true;
		}

	q.clear();
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
		{
			if(spd[i] == spd[j]) continue;
			if(spd[i] > spd[j])
			{
				double rel = spd[i]-spd[j];
				double tbeg = (pos[j]-pos[i]-5)/rel;
				double tend = (pos[j]-pos[i]+5)/rel;			
				if(tbeg>-EPS)	q.pb( event(tbeg,true,i,j) );				
				if(tend>-EPS)	q.pb( event(tend,false,i,j) );
			}
			else
			{
				double rel = spd[j]-spd[i];
				double tbeg = (pos[i]-pos[j]-5)/rel;
				double tend = (pos[i]-pos[j]+5)/rel;			
				if(tbeg>-EPS)	q.pb( event(tbeg,true,i,j) );				
				if(tend>-EPS)	q.pb( event(tend,false,i,j) );
			}
		}
		
	sort(all(q));
	
	for(int i=0;i<q.size();i++)
	{
		event z = q[i];
		int u=z.u;
		int v=z.v;
		//debug(z.t, z.add, u,v);
		
		if(!z.add)
		{
			adj[u][v] = false;
			adj[v][u] = false;
			continue;
		}		
		
		adj[u][v] = true;
		adj[v][u] = true;
		if(side[u] != side[v]) continue;
		
		bool shiftu=true;
		bool shiftv=true;
		for(int j=0;j<N;j++)
		{
			if(side[j] != side[u] && adj[j][u]) shiftu=false;
			if(side[j] != side[v] && adj[j][v])	shiftv=false;
		}
		
		if(!shiftu && !shiftv)
		{
			printf("Case #%d: %.9lf\n",testnum,z.t);
			return;
		}
			
		if(shiftu)
			side[u] = !side[u];
		else
			side[v] = !side[v];
	}
	printf("Case #%d: Possible\n",testnum);

		
}

bool input()
{
	s(N);
	char dummy;
	for(int i=0;i<N;i++)
	{
		sc(dummy);
		side[i] = (dummy=='L');
		s(spd[i]);
		s(pos[i]);
	}
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
