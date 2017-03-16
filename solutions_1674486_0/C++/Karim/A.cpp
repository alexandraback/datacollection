#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <climits>
#include <queue>
#include <ctime>

using namespace std;


#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define rep(i,x,n) for(int i = (x) ; i < (int)(n) ; ++i)
#define repit(it,x,n) for(__typeof(x) it = (x) ; it!=(n) ;++it)

int n;
vector<vector<int> >adjl;
bool vis[1001];
int indeg[1001];

void f(int cur)
{
	if(vis[cur])
		throw 1;
	vis[cur] = 1;
	rep(i,0,adjl[cur].size())
		f(adjl[cur][i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
#endif
	int t,x,m;
	scanf("%d",&t);

	rep(tt,0,t)
	{
		adjl.clear();
		scanf("%d",&n);
		adjl.resize(n);
		memset(indeg,0,sizeof(indeg));
		rep(i,0,n)
		{
			scanf("%d",&m);
			rep(j,0,m)
				scanf("%d",&x),adjl[i].PB(x-1),indeg[x-1]++;
		}
		rep(i,0,n)
			if(!indeg[i])
			{
				memset(vis,0,sizeof(vis));
				try{f(i);
				}catch(...)
				{
					printf("Case #%d: Yes\n",tt+1);
					goto bara;
				}
			}
		printf("Case #%d: No\n",tt+1);
		bara:;
	}

	return 0;
}
