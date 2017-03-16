#include <stdio.h>
#include <string.h>

int n;
char c[20], j[20], mc[20], mj[20], l, jans[20], cans[20], mmh;
long long int ans = 4000000000000000001LL;

int subtract(int cur, char * ll, char * mll)
{
	if(cur < 0)
		return 0;
	if(mll[cur] && ll[cur] != '0')
	{
		ll[cur]--;
		return 1;
	}
	if(mll[cur] && subtract(cur - 1, ll, mll))
	{
		ll[cur] = '9';
		return 1;
	}
	return 0;
}

int sum(int cur, char * ll, char * mll)
{
	if(cur < 0)
		return 0;
	if(mll[cur] && ll[cur] != '9')
	{
		ll[cur]++;
		return 1;
	}
	if(mll[cur] && sum(cur - 1, ll, mll))
	{
		ll[cur] = '0';
		return 1;
	}
	return 0;
}

void test(int i, int f)
{
	if(i == l)
	{
		long long int t1, tt1 = 0, tt2 = 0;
		for(t1 = 0; t1 < l; t1++)
			tt1 *= 10LL, tt1 += (long long int)(c[t1] - '0');
		for(t1 = 0; t1 < l; t1++)
			tt2 *= 10LL, tt2 += (long long int)(j[t1] - '0');
		long long int dif = tt1 - tt2;
		if(dif < 0)
			dif *= -1;
		if(dif < ans)
		{
			for(t1 = 0; t1 < l; t1++)
				cans[t1] = c[t1];
			for(t1 = 0; t1 < l; t1++)
				jans[t1] = j[t1];
			ans = dif;
		}
		//printf("%lld %lld %lld %lld %s %s\n", ans, dif, tt1, tt2, c, j);
		return;
	}
	if(f == 0)
	{
		if(c[i] == '?' && j[i] == '?')
		{
			c[i] = j[i] = '0';
			test(i + 1, f);
			return;
		}
		else if(c[i] == '?')
		{
			c[i] = j[i];
			test(i + 1, f);
			return;
		}
		else if(j[i] == '?')
		{
			j[i] = c[i];
			test(i + 1, f);
			return;
		}
		else if(c[i] != j[i])
		{
			if(i && (mc[i - 1] || mj[i - 1]))
			{
				test(i + 1, (c[i] > j[i]) ? 1 : 2);
				int t = c[i] - j[i];
				if(t > 5)
				{
					if(subtract(i - 1, c, mc))
						test(i + 1, 2);
					else if(sum(i - 1, j, mj))
						test(i + 1, 2);
					return;
				}
				else if(t < -5)
				{
					if(subtract(i - 1, j, mj))
						test(i + 1, 1);
					else if(sum(i - 1, c, mc))
						test(i + 1, 1);
					return;
				}
				else if(t == 5)
				{
					if(subtract(i - 1, c, mc))
						test(i + 1, 2);
					else if(sum(i - 1, j, mj))
						test(i + 1, 2);
				}
				else if(t == -5)
				{
					if(subtract(i - 1, j, mj))
						test(i + 1, 1);
					if(sum(i - 1, c, mc))
						test(i + 1, 1);
				}
			}
			else
				test(i + 1, (c[i] > j[i]) ? 1 : 2);
		}
		else
			test(i + 1, 0);
	}
	else if(f == 1)
	{
		if(mc[i] == 1)
			c[i] = '0';
		if(mj[i] == 1)
			j[i] = '9';
		test(i + 1, f);
	}
	else if(f == 2)
	{
		if(mc[i] == 1)
			c[i] = '9';
		if(mj[i] == 1)
			j[i] = '0';
		test(i + 1, f);
	}
}
int main()
{
	int t, k;
	scanf("%d", &t);
	for(k = 0; k < t; k++)
	{
		mmh = k;
		ans = 9000000000000000000LL;
		memset(mc, 0, sizeof mc);
		memset(mj, 0, sizeof mj);
		memset(cans, 0, sizeof cans);
		memset(jans, 0, sizeof jans);
		scanf(" %s %s", c, j);
		l = strlen(c);
		for(int i = 0; i < l; i++)
		{
			mc[i] = (c[i] == '?');
			mj[i] = (j[i] == '?');
		}
		test(0, 0);
		printf("Case #%d: %s %s\n", k + 1, cans, jans);		
	}
	return 0;
}
