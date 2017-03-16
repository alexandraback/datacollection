# include <stdio.h>


long long gcd(long long a, long long b){
	return a%b ? gcd(b, a%b) : b;
}
	

long long gao(long long p, long long q)
{
	long long _240 = (1LL << 40);
	if (_240 % q != 0) return 0;
	p *= (_240/q);
	int ans = 40;
	while (p){
		
		p/= 2;
		if (p ==0) break;
		ans--;
	}
	return ans;
}

	
int main ()
{

	long long ans;
	long long p, q, g;
	int T, cas;
	
	freopen ("A-large.in", "r", stdin);
	freopen ("A_large.txt", "w", stdout);
	
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%I64d/%I64d", &p, &q);
		g = gcd(p,q);
		p /= g, q /= g;
		
		ans = gao(p, q);
		printf ("Case #%d: ", cas);
		if (ans <= 0) puts ("impossible");
		else printf ("%I64d\n", ans);
	}
}
