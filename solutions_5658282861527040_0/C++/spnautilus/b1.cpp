#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN (1024)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

int T;
int A, B, K;

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		int i, j;
		scanf("%d %d %d", &A, &B, &K);

		int sol = 0;
		for(i = 0; i < A; ++i)
		{
			for(j = 0; j < B; ++j)
			{
				sol += ((i & j) < K);
			}
		}

		printf("Case #%d: %d\n", TT, sol);
	}

	return 0;
}
