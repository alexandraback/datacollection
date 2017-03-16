#include <cstdio>
#include <cstdlib>
using namespace std;
int T, n, x, y, flag, j, nowx, nowy, cnt, p[1001], dx[10], dy[10], ddx[10], ddy[10], w;
int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		printf("Case #%d: ", ++w);
		scanf("%d%d", &x, &y);
		flag = 1;
		if (x > 0)
			for (int i = 1; i <= x; i++) printf("WE");
		else
			for (int i = 1; i <= -x; i++) printf("EW");
		if (y > 0)
			for (int i = 1; i <= y; i++) printf("SN");
		else
			for (int i = 1; i <= -y; i++) printf("NS");
		printf("\n");
	}
	return 0;
}
