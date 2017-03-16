#include <stdio.h>
#include <queue>

using namespace std;

#define maxn (1024)

int T;
int N;
int A[maxn];
int B[maxn];

int played[maxn]; // 0,1,2

int main()
{
	int tt;
	scanf("%d", &T);

	for(tt = 1; tt <= T; ++tt)
	{
		int i, j;

		scanf("%d", &N);
		for(i = 0; i < N; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			A[i] = a;
			B[i] = b;

			played[i] = 0;
		}

		int s = 0;
		int n2 = (N << 1);
		int sol = 0;
		
		while(s < n2)
		{
			int ic = 0;

			for(i = 0; i < N; ++i)
			{
				if(B[i] <= s && played[i] != 2)
				{
					++ic;
					++sol;
					s += 2 - played[i];
					played[i] = 2;
				}
			}

			if(ic == 0) // 2 not exist
			{
				int max2i = -1;
				int max2 = -1;

				for(i = 0; i < N; ++i)
				{
					if(A[i] <= s && played[i] == 0 && max2 < B[i])
					{
						max2 = B[i];
						max2i = i;
					}
				}

				if(max2i != -1)
				{
					++s;
					++sol;
					played[max2i] = 1;
				}
				else
				{
					sol = -1;
					break;
				}
			}
		}

		if(sol >= 0)
			printf("Case #%d: %d\n", tt, sol);
		else
			printf("Case #%d: Too Bad\n", tt);
	}

	return 0;
}
