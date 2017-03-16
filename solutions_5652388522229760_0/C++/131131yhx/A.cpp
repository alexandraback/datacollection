#include <bits/stdc++.h>

using namespace std;

bool B[10];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int s = 1; s <= T; s++)
	{
		int i;
		scanf("%d", &i);
		printf("Case #%d: ", s);
		if(i == 0)
		{
			puts("INSOMNIA");
			continue;
		}
		memset(B, 0, sizeof B);
		for(int j = 1; ; j++)
		{
			long long tmp = 1ll * j * i;
			while(tmp) B[tmp % 10] = 1, tmp /= 10;
			bool getans = 1;
			for(int k = 0; k < 10; k++) if(!B[k]) getans = 0;
			if(getans)
			{
				printf("%lld\n", 1ll * i * j);
				break;
			}
		}
	}
	return 0;
}
