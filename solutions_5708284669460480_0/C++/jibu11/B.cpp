#include <stdio.h>
#include <string.h>

char lin[30], wd[30], tmp[30];
int key[30], l, s, k, sol = 0, cases = 0;

int nfin()
{
	int i;
	for(i = 0; i < l; i++)
		if(key[wd[i] - 'A'] == 0)
			return 1;
	return 0;
}

int count()
{
	int i, j, cen = 0;
	for(i = 0; i < s; i++)
	{
		int fl = 1;
		for(j = 0; j < l && j + i < s; j++)
			if(tmp[j + i] != wd[j])
				fl = 0;
		cen += fl;
	}
	return cen;
}

void dfs(int cur)
{
	if(cur == s)
	{
		sol += count();
		cases++;
		return;
	}
	int i;
	for(i = 0; i < k; i++)
	{
		tmp[cur] = lin[i];
		dfs(cur + 1);
	}
	return;
}

int gen()
{
	int i;
	for(i = 0; i < s; i++)
	{
		int j, t;
		for(j = 0; j < i; j++)
		{
			int fl = 1;
			for(t = j; t < i; t++)
				if(tmp[t] != wd[t - j])
					fl = 0;
			if(fl)
				break;
		}
		tmp[i] = wd[i - j];
	}
	return count();
}

int main()
{
	int t, t1;
	scanf("%d", &t1);
	for(t = 1; t <= t1; t++)
	{
		memset(key, 0, sizeof key);
		scanf("%d%d%d", &k, &l, &s);
		int i;
		scanf(" %s", lin);
		scanf(" %s", wd);
		for(i = 0; i < k; i++)
			key[lin[i] - 'A']++;
		dfs(0);
		double tot = gen();
		if(nfin())
			tot = 0.0;
		double p = (sol) / (cases);
		printf("Case #%d: %.7lf\n", t, tot - p);
	}
}
