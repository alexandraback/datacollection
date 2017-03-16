#include <cstdio>
#include <cstring>

struct C
{
	int t, k;
	int keys[40];
};

int dp[1048576];
int n;
int types[201];
int curTypes[201];
C chests[20];
int res[20];

void setCurTypes(int w)
{
	for (int i = 0; i < 201; ++i)
		curTypes[i] = types[i];
	int w2 = 1;
	for (int i = 0; i < n; ++i)
	{
		if ((w & w2) > 0)
		{
			for (int k = 0; k < chests[i].k; ++k)
				curTypes[chests[i].keys[k]]++;
			curTypes[chests[i].t]--;
		}
		w2 *= 2;
	}
}

bool f(int w)
{
	if (w == (1 << n) - 1)
		return true;
	if (dp[w] != -1)
		return dp[w] == 0 ? false : true;
	
	setCurTypes(w);
	
	int w2 = 1;
	bool any = false;
	for (int i = 0; i < n; ++i)
	{
		if ((w & w2) == 0 && curTypes[chests[i].t] > 0)
		{
			any |= f(w | w2);
		}
		w2 *= 2;
	}
	
	dp[w] = any ? 1 : 0;
	return any;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int x = 0; x < t; ++x)
	{
		memset(types, 0, sizeof(types));
		
		int k;
		scanf("%d %d", &k, &n);
		for (int i = 0; i < k; ++i)
		{
			int type;
			scanf("%d", &type);
			types[type]++;
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &chests[i].t, &chests[i].k);
			for (int j = 0; j < chests[i].k; ++j)
			{
				scanf("%d", &chests[i].keys[j]);
			}
		}
		
		int w = 0;
		bool valid = false;
		int pos = 0;
		
		for (int i = 0; i < (1 << n); ++i)
			dp[i] = -1;
		
		while (w != (1 << n) - 1)
		{
			int w2 = 1;
			for (int i = 0; i < n; ++i)
			{
				setCurTypes(w);
				if ((w & w2) == 0 && curTypes[chests[i].t] > 0 && f(w | w2))
				{
					res[pos++] = i;
					valid = true;
					break;
				}
				w2 *= 2;
			}
			
			if (!valid)
				break;
				
			w |= w2;
		}
		
		
		printf("Case #%d: ", x + 1);
		if (valid)
		{
			for (int i = 0; i < n; ++i)
				printf("%d%s", res[i] + 1, i == n - 1 ? "\n" : " ");
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

