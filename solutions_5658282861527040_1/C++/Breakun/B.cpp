#include <cstdio>
using namespace std;

typedef long long ll;
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int A, B, C, abit, bbit, cbit;
		int na[2], nb[2], nc[2], la, lb, lc;
		scanf("%d %d %d", &A, &B, &C);
		ll ans = 0LL;
		for(int a = A; a; )
		{
			abit = a & -a;
			a -= abit;

			for(int b = B; b; )
			{
				bbit = b & -b;
				b -= bbit;

				for(int c = C; c; )
				{
					cbit = c & -c;
					c -= cbit;

					ll cans = 1LL;
					bool ok = true;
					for(int i = 0; i < 30; i++)
					{
						int bit = (1 << i);
						if(bit >= abit)
							la = 1, na[0] = a;
						else
							la = 2, na[0] = a & (~bit), na[1] = na[0] + bit;
						if(bit >= bbit)
							lb = 1, nb[0] = b;
						else 
							lb = 2, nb[0] = b & (~bit), nb[1] = nb[0] + bit;
						if(bit >= cbit)
							lc = 1, nc[0] = c;
						else 
							lc = 2, nc[0] = c & (~bit), nc[1] = nc[0] + bit;

						ll mult = 0LL;
						for(int i = 0; i < la; i++)
							for(int j = 0; j < lb; j++)
								for(int k = 0; k < lc; k++)
									if((na[i] & nb[j] & bit) == (nc[k] & bit))
										mult++;
						cans *= mult;
					}
					ans += cans;
				}
			}
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
