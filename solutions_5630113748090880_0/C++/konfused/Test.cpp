#include <cstdio>
#include <algorithm>
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int i = 1; i <= T; ++i)
	{
		int N;
		scanf("%d", &N);

		int lines = (N<<1)-1;
		int Hash[2501] = {0};
		for(int j = 0; j < lines; ++j)
			for(int k = 0; k < N; ++k)
			{
				int num;
				scanf("%d", &num);

				++Hash[num];
			}

		int missingLine[50], missingLinePtr = 0;
		for(int j = 1; j <= 2500; ++j)
			if(Hash[j]&1)
				missingLine[missingLinePtr++] = j;

		std::sort(missingLine, missingLine+N);

		printf("Case #%d: ", i);
		for(int j = 0; j < N; ++j)
			printf("%d ", missingLine[j]);
		printf("\n");
	}
	
	return 0;
}
