#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

bool bin[70];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		int n;
		ll m;
		scanf("%d %lld", &n, &m);

		--m;
		int tam = 0;
		memset(bin, 0, sizeof bin);
		while (m)
			bin[tam++] = m&1, m >>= 1;

		printf("Case #%d: ", caso++);
		if (tam > n-2)
			printf("IMPOSSIBLE\n");
		else
		{
			printf("POSSIBLE\n");
			For(i, 0, n)
				For(j, 0, n)
				{
					if (j <= i)
						printf("0");
					else if (j < n-1)
						printf("1");
					else
					{
						if (i == 0 or bin[i-1])
							printf("1\n");
						else
							printf("0\n");
					}
				}
			printf("\n");
		}

	}

	return 0;
}