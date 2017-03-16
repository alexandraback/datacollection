#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long lint;
typedef unsigned long long ull;

const int INF = 1000000000;
const lint LINF = 1000000000000000000ll;
const double eps = 1e-8;

int n;
lint m;

void solve()
{
	scanf("%d%lld", &n, &m);

	lint mx = 1ll << (n - 2);
	if (m > mx)
	{
		printf("IMPOSSIBLE\n");
		return;
	}

	printf("POSSIBLE\n");

	if (m == mx)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d", j > i ? 1 : 0);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			printf("%d", j > i ? 1 : 0);
		}

		if (i == 0)
		{
			printf("0");
		}
		else
		{
			int val = ((m >> (i - 1)) & 1);
			printf("%d", val);
		}

		printf("\n");
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	scanf("%d", &tn);
	for (int i = 0; i < tn; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}

	return 0;
}
