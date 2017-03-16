#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

inline void Init()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small.out","w",stdout);
}
#define N 1009

vector<int> v[N];
int isv[N];


inline void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
		v[i].clear();
}

int fun(int root,int n)
{
	int i;
	fill(isv,isv+n+1,0);
	isv[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int tt = q.front();
		q.pop();
		for(i=0;i<v[tt].size();i++)
		{
			if(isv[ v[tt][i] ] == 1)
				return 1;
			else
			{
				isv[ v[tt][i] ] = 1;
				q.push(v[tt][i]);
			}
		}
	}
	return 0;
}

int main(void)
{
	Init();

	int i,j,n,m,cases,T,tt;
	scanf("%d",&cases);
	for(T=1;T<=cases;T++)
	{	
		scanf("%d",&n);
		init(n);
		for(i=1;i<=n;i++)
		{
 			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&tt);
				v[i].push_back(tt);
			}
		}
		int state = 0;
		for(i=1;i<=n;i++)
		{
			int res = fun(i,n);
			if(res==1)
			{
				state = 1;
				break;
			}
		}
		if(state==1)
			printf("Case #%d: Yes\n",T);
		else
			printf("Case #%d: No\n",T);
	}

	return 0;
}