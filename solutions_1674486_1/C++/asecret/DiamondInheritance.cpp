#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<climits>
#include<fstream>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define pb						push_back
#define mp	 					make_pair
#define fill(a,v) 				memset(a, v, sizeof(a))
#define SZ(v)					((int)(v.size()))
#define all(x)					x.begin(), x.end()
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define FF						first
#define SS						second
#define T(t)           			int t;scanf ("%d",&t);while (t--)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<pair<int,int> > VPII;
typedef pair<double,double> PDD;

bool done[1001];
vector <vector <int> > adjl;
bool dfs(int u)
{
	done[u]=true;
	int len = adjl[u].size();
	bool ans = false;
	for(int i=0;i<len && ans==false;i++)
	{
		int v=adjl[u][i];
		if(!done[v])
			ans = dfs(v);
		else
			ans = true;
	}
return ans;
}


int main()
{
    int t;
    s(t);
	REP(k,t)
	{
		int n; s(n);
		adjl.clear();
		VI l; l.pb(0); adjl.pb(l);
		REP(i,n)
		{
			int m; s(m);
			VI line;
			REP(j,m)
			{
				int a; s(a);	
				line.pb(a);
			}
			adjl.pb(line);
		}
		
		bool ans = false;
		for(int i=1;i<=n && ans==false;i++)
		{
			fill(done, false);
			ans = dfs(i);
		}
		
		cout << "Case #" << k+1 <<":";
		if(ans)
			cout << " Yes" << endl;
		else
			cout <<" No" <<endl;
	}
    return 0;
}
