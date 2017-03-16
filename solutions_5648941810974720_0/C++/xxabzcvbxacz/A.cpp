#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 2000
#define INF (1<<30)

struct edge
{
	int s, e;
	bool operator < (const edge &a) const
	{
		return (e < a.e);
	}
};

char buff[MAX_N+5];

char *dig[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[10][26];
int cnta[26];
int res[10];

int main()
{
	int T;
	int N;
	scanf("%d\n", &T);

	for (int i=0; i<10; ++i)
		for (int j=0; dig[i][j]; ++j)
			++cnt[i][dig[i][j]-'A'];

	/*for (int i=0; i<10; ++i)
	{
		printf("%d: ", i);
		for (int j=0; j<26; ++j)
			printf("%d ", cnt[i][j]);
		printf("\n");
	}*/

	for (int t=0; t<T; ++t)
	{
		scanf("%s\n", buff);

		memset(cnta, 0, sizeof(cnta));
		for (int i=0; buff[i]; ++i)
			++cnta[buff[i]-'A'];

		const int arr[] = {0, 'Z', 6, 'X', 2, 'W', 4, 'U', 8, 'G', 3, 'T', 7, 'S', 1, 'O', 5, 'V', 9 , 'E'};
		for (int j=0; j<10; ++j)
		{
			int x = arr[j*2];
			int y = arr[j*2+1]-'A';
			int c = cnta[y];
			res[x] = c;
			for (int i=0; i<26; ++i)
				cnta[i] -= cnt[x][i] * c;
		}

		printf("Case #%d: ", t+1);
		for (int i=0; i<10; ++i)
			for (int j=0; j<res[i]; ++j)
				printf("%d", i);
		printf("\n");
	}
	return 0;
}
