#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);

		printf("Case #%d: ", tc);

		long long len = 1;
		for(int i=0; i < C; i++)
			len = len * K;

		int add = 2;
		if(K == 1 || C == 1)
			add = 1;
		for(int i=0; i < S; i++)
			printf("%d ", i + add);
		puts("");
	}
	return 0;
}