#include <stdio.h>


typedef long long ll ;

ll pow[110];


void gao(ll k, ll c, ll s)
{
	if (c * s < k){
		puts ("IMPOSSIBLE");
		return;
	}
	ll cur;
	ll level, pos;
	pow[0] = 1;
	for (int i = 1; i <= c; i++)
		pow[i] = pow[i-1]*k;
	int flag = 1;
	for (cur = 0; cur < k && flag; )
	{
		pos = 0;
		for (level = 1; level <= c; level ++)
		{
			pos += pow[c-level] * (cur);
			cur ++;
			if (cur >= k) cur = k - 1, flag = 0;
		}
		printf ("%I64d ", pos + 1);
	}
	puts ("");
}


int main()
{
	int T, cas;
	int k, c, s;
	freopen ("D-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d %d %d", &k, &c, &s);
		printf ("Case #%d: ", cas);
		gao(k, c, s);
	}
	return 0;
}
