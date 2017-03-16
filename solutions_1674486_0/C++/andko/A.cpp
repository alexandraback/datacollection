#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
#define MAXN 1004
using namespace std;

void solve(int num)
{
//	zeruj();
	int N;
	scanf("%d",&N);
	vector<vector<int> >tab;
	tab.resize(N+2);
	int stopien[MAXN];
//set<int> prevs[MAXN];
	vector<int> prevstab[MAXN];
	//int parent[MAXN];
	for(int i=0;i<MAXN;i++)stopien[i]=0;
	queue<int>Q;
	for(int i=0;i<N;i++)
	{
		int t,a;
		scanf("%d",&t);
//		tab[i].resize(t);
		for(int j=0;j<t;j++)
		{
			scanf("%d",&a);
			tab[i+1].push_back(a);
			stopien[a]++;
		}
	}
	for(int i=0;i<N;i++)if(stopien[i+1]==0)
	{
		//printf("%d\n",i+1);
		Q.push(i+1);
	}
	while(!Q.empty())
	{
		int a = Q.front();Q.pop();
		//printf("%d\n",a);
		sort(prevstab[a].begin(),prevstab[a].end());
		for(int i=0;i<(long long)prevstab[a].size()-1;i++)
		{
			//printf("%d\n",i);
			if(prevstab[a][i]==prevstab[a][i+1])
			{
			
			printf("Case #%d: Yes\n",num);
			return;
			}
		}
		for(int i=0;i<tab[a].size();i++)
		{
			int p = tab[a][i];
			stopien[p]--;
			for(int i=0;i<prevstab[a].size();i++)
			{
				prevstab[p].push_back(prevstab[a][i]);
			}
			prevstab[p].push_back(a);
			//printf("%d %d\n",p,stopien[p]);
			if(stopien[p] == 0)
			{
				Q.push(p);
			}
			
		}
	}
	printf("Case #%d: No\n",num);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)solve(i+1);
	return 0;
}