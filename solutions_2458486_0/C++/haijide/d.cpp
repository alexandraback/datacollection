#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int M = 205;
const int inf = 0x7fffffff;

int T;
int knum, n;
vector<int> key;//开始的钥匙
vector<int> open[M];//第i把钥匙可以开哪些柜子
int num[M];//此时每把钥匙的数目
vector<int> getkey[M];//打开第i个柜子可以得到的钥匙
bool vis[M];
int ans[M];
int need[M];
bool mark;
int tnum[M];

void dfs(int box, int deep)
{
	if(deep == n)
	{
		mark = true;
//		cout<<"last "<<box<<endl;
		ans[deep] = box;
		return;
	}
	int len = getkey[box].size();
	for(int i = 0; i < len; i++)
	{
		num[getkey[box][i]]++;
	}
	num[need[box]]--;
	int mx = 1000, id = -1;
	for(int i = 1; i <= 200; i++)
	{
		if(num[i] == 0)
			continue;
		int l = open[i].size();
		if(l > 0)
		{
			if(open[i][0] < mx)
			{
				mx = open[i][0];
				id = i;
			}
		}
	}
	if(id == -1)
		return;
//	for(int i = 1; i <= 200; i++)
//	{
//		if(num[i] == 0)
//			continue;
		int l = open[id].size();
		int v;
		for(int j = 0; j < l; j++)
		{
			v = open[id][j];
			if(!vis[v])
			{
				vis[v] = true;
				int ll = getkey[v].size();
				for(int ii = 0; ii < ll; ii++)
					num[getkey[v][ii]]++;
				dfs(v, deep + 1);
				if(mark)
				{
					ans[deep] = box;
					return;
				}
				for(int ii = 0; ii < ll; ii++)
					num[getkey[v][ii]]--;
				vis[v] = false;
			}
		}
//	}
	num[need[box]]++;
}

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-out.out", "w", stdout);
	scanf("%d", &T);
	int cs = 1;
	while(T--)
	{
		for(int i = 0; i < M; i++)
		{
			open[i].clear();
			getkey[i].clear();
			num[i] = 0;
			tnum[i] = 0;
		}
		key.clear();
		scanf("%d%d", &knum, &n);
		int k;
		for(int i = 0; i < knum; i++)
		{
			scanf("%d", &k);
			key.push_back(k);
			tnum[k]++;
		}
		int kneed, gnum, tmp;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &kneed, &gnum);
			need[i] = kneed;
			open[kneed].push_back(i);
			for(int j = 0; j < gnum; j++)
			{
				scanf("%d", &tmp);
				getkey[i].push_back(tmp);
			}
		}
		for(int i = 1; i <= 200; i++)
		{
			sort(open[i].begin(), open[i].end());
		}
		if(knum == 0)
		{
			printf("Case #%d: IMPOSSIBLE\n", cs++);
			continue;
		}
		mark = false;
		for(int i = 1; i <= n; i++)
		{
			if(tnum[need[i]] == 0)
				continue;
			mark = false;
			memset(vis, 0, sizeof(vis));
			for(int j = 0; j < M; j++)
				num[j] = tnum[j];
			vis[i] = true;
			dfs(i, 1);
			vis[i] = false;
			if(mark)
				break;
		}
		if(!mark)
		{
			printf("Case #%d: IMPOSSIBLE\n", cs++);
		}
		else
		{
			printf("Case #%d:", cs++);
			for(int i = 1; i <= n; i++)
				printf(" %d", ans[i]);
			printf("\n");
		}
	}
	return 0;
}
