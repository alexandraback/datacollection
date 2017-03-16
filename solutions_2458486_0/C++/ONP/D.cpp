#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> has[100];
int N, K, keys[1 << 20][25], ori[1000], need[100];
int f[1 << 20];

inline bool dfs(int mask)
{
	if (mask + 1 == 1 << N)
	{
		return true;
	}
	int &res = f[mask];
	if (res!=-1){
		return res;
	}
	res=0;
	for (int i = 0; i < N ; ++ i)
	{
		if (! (mask >> i & 1))
		{
			if (keys[mask][need[i]] > 0)
			{
				res|=dfs( mask | (1 << i));
			}
		}
	}
	return res;
}

inline void go(int mask)
{
	if (mask + 1 == 1 << N)
	{
		return;
	}
	for (int i = 0; i < N ; ++ i)
	{
		if (! (mask >> i & 1))
		{
			if (keys[mask][need[i]] > 0)
			{
				if (dfs(mask | (1 << i)))
				{
					printf(" %d", i + 1);
					go(mask | (1 << i));
					return;
				}
			}
		}
	}
}

int main()
{
	int T, caseNum = 1;
	for (scanf("%d", &T);T --;)
	{
		scanf("%d%d", &K, &N);
		for (int i = 0; i < K; ++ i)
		{
			scanf("%d", &ori[i]); 
		}
		
		for (int i = 0; i < N; ++ i)
		{
			int number;
			scanf("%d%d", &need[i], &number);
			has[i].clear();
			for (int j = 0; j < number; ++ j)
			{
				int x;
				scanf("%d", &x);
				has[i].push_back(x);
			}
		}
fprintf(stderr,"hello~");
		for (int mask = 0; mask < 1 << N; ++ mask)
		{
			memset(keys[mask], 0, sizeof(keys[mask]));
			for (int i = 0; i < K; ++ i)
			{
				keys[mask][ori[i]] ++;
			}
			for (int i = 0; i < N; ++ i)
			{
				if (mask >> i & 1)
				{
					keys[mask][need[i]] --;
					for (int j = 0; j < (int)has[i].size(); ++ j)
					{
						keys[mask][has[i][j]] ++;
					}
				}
			}
		}
fprintf(stderr,"hi~~");
		memset(f,-1,sizeof(f));
		if (!dfs(0))
		{
			printf("Case #%d: IMPOSSIBLE\n",caseNum);
		}else
		{
			printf("Case #%d:",caseNum);
			go(0);
		}
		puts("");
		++caseNum;
	}
	return 0;
}
