//TC Accretia Code Template
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>
#include <string>

#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define FILL(arr,n) memset(arr,n,sizeof(arr))
#define FORUP(i,m,n) for(int i=(m); i<(n); i++)
#define FORDOWN(i,m,n) for(int i=(m)-1; i>=(n); i--)

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define INF 2000000000
#define EPS 1e-11
#define PI acos(-1.0)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;



bool run()
{
	vector<int> graph[1005];

	int N;

	scanf("%d", &N);
	for(int i = 1;i <= N;i++)
	{
		int sum;
		scanf("%d", &sum);
		for(int j = 0;j < sum;j++)
		{
			int tmp;
			scanf("%d", &tmp);
			graph[i].PB(tmp);
		}
	}
	for(int i = 1;i <= N;i++)
	{
		set<int> isVisited;
		queue<int> Q;
		Q.push(i);
		
		while(!Q.empty())
		{
			int news = Q.front();
			Q.pop();
			for(int i = 0;i < graph[news].size();i++)
			{
				int next = graph[news][i];
				if(isVisited.count(next) > 0)
				{
					return true;
				}
				else
				{
					isVisited.insert(next);
					Q.push(next);
				}
			}
		}
	}
	return false;
}

int
main()
{
	int T;
	scanf("%d", &T);
	for(int tc = 1;tc <= T;tc++)
	{
		bool yes = run();
		printf("Case #%d:",tc);
		if(yes)printf(" Yes\n");
		else printf(" No\n");
	}
return 0;
}