#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 11;
int t1[N][N], t2[N][N], t3[N][N];
int a, b, c, k, ans;

int main()
{
	//freopen("3.in", "r", stdin);
	//freopen("3.out", "w", stdout);
	int T, Case = 0;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d%d%d%d", &a, &b, &c, &k);
		++ Case;
		printf("Case #%d: %d\n", Case, a * b * min(c, k));
		for (int i = 1; i <= a; ++ i)
			for (int j = 1; j <= b; ++ j)
				for (int x = 1; x <= min(c, k); ++ x)
					printf("%d %d %d\n", i, j, (i + j + x - 1) % c + 1);
	}
}