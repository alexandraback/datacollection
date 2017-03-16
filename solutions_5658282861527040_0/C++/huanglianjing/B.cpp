#include <cstdio>

int t, a, b, k;

int main()
{
	scanf("%d",&t);
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d",&a,&b,&k);
		long long res = 0;
		for (int i=0; i<a; ++i) for (int j=0; j<b; ++j) {
			if ((i&j) < k) ++res;
		}
		printf("Case #%d: %lld\n",cas,res);
	}
	return 0;
}
