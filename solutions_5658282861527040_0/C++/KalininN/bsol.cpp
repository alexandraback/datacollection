#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int A, B, K;
ll ans[32][2][2][2];

inline bool can(int i, bool isC, int x, int C)
{
	i--;
	return !isC || x <= ((C >> i) & 1);
}

inline bool check(int i, bool isC, int x, int C)
{
	i--;
	return isC && x == ((C >> i) & 1);
}

int main()
{
	int NT = 0;
	scanf("%d", &NT);
	for (int T = 1; T <= NT; T++)
	{
		printf("Case #%d:", T);
		
		scanf("%d%d%d", &A, &B, &K);
		memset(ans, 0, sizeof(ans));
		ans[31][1][1][1] = 1;
		for (int i = 31; i > 0; i--)
		{
			for (int isA = 0; isA < 2; isA++)
			{
				for (int isB = 0; isB < 2; isB++)
				{
					for (int isK = 0; isK < 2; isK++)
					{
// 						if (ans[i][isA][isB][isK] > 0)
// 						{
// 							cout << i << ' ' << isA << ' ' << isB << ' ' << isK << ' ' << ans[i][isA][isB][isK] << endl;
// 						}
						for (int x = 0; x < 2; x++) if (can(i, isA, x, A))
						{
							for (int y = 0; y < 2; y++) if (can(i, isB, y, B) && can(i, isK, x & y, K))
							{
								ans[i - 1][check(i, isA, x, A)][check(i, isB, y, B)][check(i, isK, x & y, K)] += ans[i][isA][isB][isK];
							}
						}
					}
				}
			}
		}
		ll answer = 0;
		answer += ans[0][0][0][0];
		printf(" " LLD "\n", answer);
		fprintf(stderr, "%d/%d cases done!\n", T, NT);
	}
	return 0;
}
