#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	freopen("d-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	for (int p = 1; p <= data; p++)
	{
		ll bas, kai, gen;
		scanf("%lld%lld%lld", &bas, &kai, &gen);
		printf("Case #%d:", p);
		if ((bas + kai - 1) / kai > gen)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		ll pt = 0;
		for (int i = 0; i < (bas + kai - 1) / kai; i++)
		{
			ll now = 0;
			for (int j = 0; j < kai; j++)
			{
				now *= bas;
				now += pt;
				pt++;
				if (pt >= bas)pt = bas - 1;
			}
			printf(" %lld", now + 1);
		}
		printf("\n");
	}
}