#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 1
#define LIM 2000005

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	//vars
	int N,M,S,E;
	int i,j,k,p,no;
	static LL fun[LIM]={0};
	static vector <int> con[LIM],rcon[LIM];
	static bool good[LIM]={0},vis[LIM]={0};
	static bool ncon[LIM],nrcon[LIM];
	static int ind[LIM]={0},ord[LIM];
	static LL dyn[LIM]={0};
	queue <int> Q;
	stack <PR> St;
	//input
	scanf("%d%d%d%d",&N,&M,&S,&E),S--,E--;
		For(i,N)
			scanf("%lld",&fun[i]);
		while (M--)
		{
			scanf("%d%d",&i,&j),i--,j--;
			con[i].pb(j);
			rcon[j].pb(i);
		}
	//BFS from end to find useful nodes
	Q.push(E),good[E]=1;
		while (!Q.empty())
		{
			i=Q.front(),Q.pop();
				For(j,Sz(rcon[i]))
					if (!good[k=rcon[i][j]])
						Q.push(k),good[k]=1;
		}
	//DFS to find and collapse cycles
	St.push(mp(S,0)),vis[S]=1;
		while (!St.empty())
		{
			//get instance
			i=St.top().x,j=St.top().y,St.pop();
			//done with this node?
				if (j==Sz(con[i]))
					continue;
			//take next edge
			St.push(mp(i,j+1));
			k=con[i][j];
				if (!good[k])	//useless - ignore it
					continue;
				if (!vis[k])	//not yet visited - go there
					St.push(mp(k,0)),vis[k]=1;
				else			//already visited - cycle found, create a new node for it
				{
					//go through all nodes in the cycle, collect fun values and edges
					Fill(ncon,0);
					Fill(nrcon,0);
					p=k;
						while (i!=p)
						{
							i=St.top().x,St.pop();
							good[i]=0;
							fun[N]+=fun[i];
								For(j,Sz(con[i]))
									if ((good[k=con[i][j]]) && (!ncon[k]))
									{
										con[N].pb(k),ncon[k]=1;
										rcon[k].pb(N);
									}
								For(j,Sz(rcon[i]))
									if ((good[k=rcon[i][j]]) && (!nrcon[k]))
									{
										rcon[N].pb(k),nrcon[k]=1;
										con[k].pb(N);
									}
								if (i==S)
									S=N;
								if (i==E)
									E=N;
						}
					St.push(mp(N,0)),vis[N]=1;
					good[N++]=1;
				}
		}
	//calculate in-degrees of useful nodes
		For(i,N)
			if (good[i])
				For(j,Sz(rcon[i]))
					if (good[rcon[i][j]])
						ind[i]++;
	//run topological sort to find DAG ordering
	no=0;
	Q.push(S);
		while (!Q.empty())
		{
			i=Q.front(),Q.pop();
			ord[no++]=i;
				For(j,Sz(con[i]))
					if (good[k=con[i][j]])
						if (!(--ord[k]))
							Q.push(k);
		}
	//DP on DAG
	//output
	return(0);
}