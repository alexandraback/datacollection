#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<sstream>

#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<string> vs; 
typedef pair<int,int> ii;
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define sz(a)                        int((a).size()) 
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define present(c,x)                 ((c).find(x) != (c).end()) 
#define cpresent(c,x)                (find(all(c),x) != (c).end())
#define tr(c,i)                      for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(c)                       (c).begin(),(c).end()
#define si(n)                        scanf("%d",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%f",&n)
#define sd(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)

#define INF                          INT_MAX
#define LINF                         (long long)1e18
#define EPS                          1e-9
#define max(a,b)                     ((a)>(b)?(a):(b))
#define min(a,b)                     ((a)<(b)?(a):(b))
#define abs(x)                       ((x)<0?-(x):(x))
#define fill(a,v)                    memset((a),(v),sizeof (a))

vi v[1010];
int color[1010];

int dfs(int node)
{
	if(color[node] == 1)
		return 1;
	color[node] = 1;
	int lim = v[node].size();
	for(int i=0; i<lim; i++)
	{
		int parent = v[node][i];
		if(dfs(parent))
			return 1;
	}
	return 0;
}

int main()
{
	int t,n,m,temp;
	si(t);
	for(int cases=1; cases<=t; cases++)
	{
		for(int i=0; i<1010; i++)
			v[i].clear();
		si(n);
		for(int i=1; i<=n; i++)
		{
			si(m);
			for(int j=0; j<m; j++)
			{
				si(temp);
				v[i].pb(temp);
			}
		}

		int flag = 0;
		for(int i=1; i<=n; i++)
		{
			fill(color,0);
			if(dfs(i))
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			printf("Case #%d: Yes\n",cases);
		else
			printf("Case #%d: No\n",cases);
	}
	return 0;
}
