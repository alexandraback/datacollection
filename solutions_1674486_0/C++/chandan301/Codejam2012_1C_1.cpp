//============================================================================
// Name        : Codejam2012_1C_1.cpp
// Author      : Chandan Giri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>

//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define s(n)                                    scanf("%d",&n)
#define sl(n)                                   scanf("%lld",&n)
#define sf(n)                                   scanf("%lf",&n)
#define ss(n)                                   scanf("%s",n)
#define p(n)                                    printf("%d\n",n)
#define pl(n)                                   printf("%lld\n",n)
#define maX(a,b)                                ((a)>(b)?(a):(b))
#define miN(a,b)                                ((a)<(b)?(a):(b))
#define abS(x)                                  ((x)<0?-(x):(x))
#define FOR(i,a,b)                              for(int i=a;i<b;i++)
#define mp                                      make_pair
#define FF                                      first
#define SS                                      second
#define pb                                      push_back
#define SZ(v)                                   ((int)(v.size()))
#define all(x)                                  x.begin(),x.end()
#define INF                                     (int)1e9
#define LINF                                    (long long)1e18
#define EPS                                     1e-9
#define MOD                                     ((1 << 30)-1))
#define MSZ                                     80

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;

//=========================================================================================

/* Main Code begins here */
int N;
vector <int> E[1001];
int C[1000];

int color[MSZ],dist[MSZ],par[MSZ];


bool bfs(int start)
{
	int t,sz,i,tm;

	// color = -1 --> undiscovered
	// color = 0 --> discovered but still have some -1 nodes
	// color = 1 --> discovered but no -1 nodes

	for(i=0; i<N; i++)
	{
		color[i] = -1;
		par[i] = -1;
		dist[i] = INF;
	}
	color[start] = 0;
	dist[start] = 0;
	queue <int> myqueue;
	myqueue.push(start);

	while(!myqueue.empty())
	{
		t = myqueue.front();
		myqueue.pop();
		sz = E[t].size();
		for(i=0; i<sz; i++)
		{
			tm = E[t][i];
			if(color[tm] == -1)
			{
				color[tm] = 0;
				dist[tm] = dist[t]+1;
				par[tm] = t;
				myqueue.push(tm);
			}
			else
				return true;
		}
		color[t] = 1;
	}
	return false;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int t,i,j,num,k=1;
	bool flag;
	s(t);
	while(k<=t)
	{
		s(N);
		for(i=0; i<N; i++)
		{
			E[i].clear();
			s(C[i]);
			for(j=0; j<C[i]; j++)
			{
				s(num);
				E[i].pb(num-1);
			}
		}

		//do bfs from 1 to N
		flag = false;
		for(i=0; i<N; i++)
		{
			if(bfs(i))
			{
				flag = true;
				break;
			}
		}
		if(flag)
			printf("Case #%d: Yes\n",k);
		else
			printf("Case #%d: No\n",k);
		k++;
	}

	return 0;
}
