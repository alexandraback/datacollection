/*
 * Author: 67h2gak0
 * PROG: A
 * DATE: 2013.4.13
*/
#include <cstdio>

using namespace std;

const int maxn = 105;

int num[maxn][maxn];
int N, M, ret;

void init()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= M; j ++)
			scanf("%d", &num[i][j]);
}

int x[maxn], y[maxn];

void work()
{
	ret = 1;
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= M; j ++){
			int flag = 1;
			for (int k = 1; k <= M && flag; k ++)
				if (num[i][k] > num[i][j]) flag = 0;
			if (flag) continue;
			flag = 1;
			for (int k = 1; k <= N && flag; k ++)
				if (num[k][j] > num[i][j]) flag = 0;
			if (flag) continue;
			ret = 0; return;
		}
}

void print()
{
	if (ret == 1) puts("YES");
		else puts("NO");
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, t = 0;
	scanf("%d", &T);
	while (T --){
		init();
		work();
		printf("Case #%d: ", ++ t);
		print();
	}
	return 0;
}
