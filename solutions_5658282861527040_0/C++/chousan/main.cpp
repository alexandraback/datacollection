#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a, b, k;
long long solve()
{
	long long  ans = 0;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			if ((i & j) < k) ans++;
	return ans;
}
int main()
{
    freopen("1.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas)
	{
	    printf("Case #%d: ",cas);
		scanf("%d%d%d", &a, &b, &k);
		printf("%lld\n", solve());
	}
	return 0;
}
