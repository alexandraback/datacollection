#include <cstdio>
#include <cstring>
int main(int argc, char** argv)
{
	int n;
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		printf("Case #%d:\n", i+1);
		int l, cnt;
		scanf("%d%d", &l, &cnt);
		for (int j = 0; j < cnt; ++j)
		{
			char a[50];
			a[l] = 0;
			int tj = j;
			for (int k = l/2-1; k >= 0; --k)
			{
				if (k == 0 || k == l/2-1)
					a[k] = a[k+l/2] = '1';
				else
				{
					a[k] = a[k+l/2] = '0'+tj%2;
					tj/=2;
				}
			}
			printf("%s", a);
			for (int bs = 2; bs <= 10; ++bs)
			{
				long long tt = 0;
				for (int k = 0; k < l/2; ++k)
					tt = tt * bs + a[k] - '0';
				printf(" %lld", tt);
			}
			puts("");
		}
	}
	return 0;
}