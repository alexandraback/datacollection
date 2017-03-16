#include <cstdio>
#include <string>
typedef long long ll;

ll A,B,a[128];
int al;

bool
is_palindrome (ll n)
{
	char s[128];
	sprintf (s, "%lld", n);
	int len = strlen (s);
	for (int i = 0; i < len/2; i ++)
		if (s[i] != s[len-1-i])
			return false;
	return true;
}

int
main ()
{	
	for (ll i = 1; i <= 10000000; i ++)
		if (is_palindrome (i) && is_palindrome (i*i))
			a[al ++] = i*i;
	freopen ("Cs.in","r",stdin);
	freopen ("Cs.out","w", stdout);
	int t;
	scanf ("%d", &t);
	for (int tc = 1; tc <= t; tc ++){
		scanf ("%lld %lld", &A, &B);
		int ans = 0;
		for (int i = 0; i < al; i ++)
			if (A <= a[i] && a[i] <= B) ans ++;
		printf ("Case #%d: %d\n", tc, ans);
	}
	return 0;
}