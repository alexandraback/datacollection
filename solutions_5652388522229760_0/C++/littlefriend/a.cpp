#include <cstdio>
#include <cstring>
void check(int &cnt, int* ta, int j)
{
	do
	{
		if (!ta[j%10]) ta[j%10] = 1, ++cnt;
		j /=10;
	} while (j);
}
int main(int argc, char** argv)
{
	int n;
	int ta[10];
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t == 0)
		{
			printf("Case #%d: INSOMNIA\n", i+1);
			continue;
		}
		memset(ta, 0, sizeof ta);
		int cnt = 0;
		for (int j = t;; j+=t)
		{
			check(cnt, ta, j);
			if (cnt == 10)
			{
				printf("Case #%d: %d\n", i+1, j);
				break;
			}
		}
	}
	return 0;
}