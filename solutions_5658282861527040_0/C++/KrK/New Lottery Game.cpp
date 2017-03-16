#include <cstdio>
using namespace std;

int t;
int a, b, k;
int res;

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &a, &b, &k);
		res = 0;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				res += (i & j) < k;
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}