#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T; cin >> T;
	for (int TT = 1; TT <= T; ++TT)
	{
		int vis[3000] = {0};
		printf("Case #%d:", TT);
		int N; cin >> N;
		for (int i = 0; i < N * 2 - 1; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int tmp; scanf("%d", &tmp);
				vis[tmp]++;
			}
		}
		for (int i = 0; i <= 2500; i++)
		{
			if(vis[i] % 2)
			{
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}