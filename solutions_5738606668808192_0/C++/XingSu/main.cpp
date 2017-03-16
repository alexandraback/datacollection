#include <stdio.h>


typedef long long ll;
int isP[1000010] = {0};
ll Ps[1000010];
ll pN;


void init()
{
	ll mV = 1000000;
	ll i, j;
	
	for (i = 2; i <= mV; i++)
		isP[i] = 1;
	for (i = 2; i <= mV; i++) if (isP[i])
	{
		Ps[pN++] = i;
		for (j = i*i; j <= mV && i <= 1000; j += i)
			isP[j] = 0;
	}
}


ll ans[55][15];


ll findFact(ll x)
{
	ll i;
	for (i = 0; i < pN && Ps[i]*Ps[i] <= x; i++)
	{
		if (x % Ps[i] == 0)
			return Ps[i];
	}
	return -1;
}


void gao(ll n, ll J)
{
	ll i, j;
	ll discov = 0;
	ll num, b, bs, fc;
	for (i = (1<<(n-1))+1; i < (1<<n) && discov < J; i+=2)
	{
		//printf ("i = %d\n", i);
		for (b = 2; b <= 10; b++)
		{
			num = 0;
			bs = 1;
			for (j = 0; j < n; j++)
			{
				if (i & (1<<j))
					num += bs;
				bs *= b;
			}
			if ((fc = findFact(num))==-1)
				break;
			ans[discov][b] = fc;
		}
		if (b > 10) ans[discov][1] = num, discov++;
	}
	for (i = 0; i < J; i++)
	{
		for (j = 1; j <= 10; j++)
			printf (j == 1 ? "%I64d" : " %I64d", ans[i][j]);
		printf ("\n");
	}
}


int main()
{
	int T, cas;
	int n, j;
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	init();
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d%d", &n, &j);
		printf ("Case #%d:\n", cas);
		gao(n, j);
	}
}