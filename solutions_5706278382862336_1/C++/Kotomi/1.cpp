#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{	 
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){	
		long long  a, b;
		scanf("%I64d/%I64d", &a, &b);
		long long d = gcd(a, b);
		a /= d;
		b /= d;
		if (b != (b & -b))
			printf("Case #%d: impossible\n", cas);
		else{
			int ans = 1;
			while(a * 2 < b){
				b /= 2;
				ans++;
			}
			printf("Case #%d: %d\n", cas, ans);
		}
	}
    return 0;
}
