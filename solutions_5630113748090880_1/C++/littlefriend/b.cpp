#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int cnt[2505];
int main(int argc, char** argv)
{
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	int T, n, a;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d:", i+1);
		scanf("%d", &n);
		for (int j = 1; j <= 2500; ++j)
			cnt[j] = 0;
		for (int j = 0; j < 2*n-1; ++j)
			for (int k = 0; k < n; ++k)
			{
				scanf("%d", &a);
				cnt[a]++;
			}
		for (int j = 1; j <= 2500; ++j)
			if (cnt[j]&1)
				printf(" %d", j);
		puts("");
	}
	return 0;
}