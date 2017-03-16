#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;
typedef map<int,int>::iterator mit;

struct sets
{
	vector<int> item;
	bool b[130];
	sets(vector<int> &_item)
	{
		item = _item;
		memset(b,0,sizeof(b));
		for (int i = 0;i < (1 << item.size());++i)
		{
			int t = 1;
			for (int j = 0;j < item.size();++j)
				if (i & (1 << j))
					t *= item[j];
			b[t] = 1;
		}
	}

	bool check(int num)
	{
		return b[num];
	}
};

vector<sets> Set;
vector<int> tmp;
bool b[1111];

void dfs(int s,int n,int bot,int m)
{
	if (s == n)
	{
		Set.push_back(sets(tmp));
		return;
	}
	for (int t = bot;t <= m;++t)
	{
		tmp.push_back(t);
		dfs(s+1,n,t,m);
		tmp.pop_back();
	}
}

void work()
{
	int R,N,M,K;
	scanf("%d%d%d%d",&R,&N,&M,&K);
	Set.clear();
	dfs(0,N,2,M);
	for (int times = 0;times < R;++times)
	{
		memset(b,0,sizeof(b));
		for (int i = 0;i < K;++i)
		{
			int t;
			scanf("%d",&t);
			for (int j = 0;j < Set.size();++j)
			{
				if (!Set[j].check(t))
					b[j] = 1;
			}
		}
		for (int i = 0;i < Set.size();++i)
		{
			if (!b[i])
			{
				for (vit it = Set[i].item.begin();it != Set[i].item.end();++it)
					printf("%d",*it);
				puts("");
				break;
			}
		}
	}
}

int main()
{
	int times;
	scanf("%d",&times);
	puts("Case #1:");
	work();
	return 0;
}
