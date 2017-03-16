#include<cstdio>
#include<vector>
#include<algorithm>
#define PB push_back
#define MAXN 1001
using namespace std;

vector<int> v[MAXN];
int vis[MAXN], stw[MAXN];
int n, x, a;

bool napierdalaj(int x, int num)
{
	vis[x] = num;
	for(int i = 0; i < v[x].size(); i++)
	{
		if(vis[v[x][i]] == num)return 1;
		else if(napierdalaj(v[x][i], num))return 1;
	}
	return 0;
}

void clear()
{
	for(int i = 0; i < MAXN; i++)
	{
		v[i].clear();
		vis[i] = 0;
		stw[i] = 0;
	}
}

void solve(int num)
{
	clear();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		for(int j = 0; j < x; j++)
		{
			scanf("%d", &a);
			v[i].PB(a);
			stw[a]++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(!stw[i])if(napierdalaj(i, i))
		{
			printf("Case #%d: Yes\n", num);
			return;
		}
	}
	printf("Case #%d: No\n", num);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)solve(i+1);
}
