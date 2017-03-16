#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long _int64;
_int64 GCD(_int64 a, _int64 b) { for (_int64 t; b; t=a%b, a=b, b=t); return a; }

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int cas, T;
	
	for (cas = scanf("%d", &T); cas <= T; cas++)
	{
		_int64 p, q;
		scanf("%I64d/%I64d", &p, &q);
		
		_int64 gcd = GCD(p, q);
		p /= gcd;
		q /= gcd;
		
		int cnt = 0, mark = 0;
		for (_int64 n = q; n > 1; n >>= 1) if (n & 1) mark = 1;
		for ( ; p < q; p <<= 1) cnt ++;

		
		printf("Case #%d: ", cas);
		if (mark == 1) { puts("impossible"); continue ; }
		
		cout << cnt << endl;
	}
	
	return 0;
}
