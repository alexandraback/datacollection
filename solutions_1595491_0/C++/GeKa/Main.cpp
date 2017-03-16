#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2100000
int mas[MAX];

int main()
{	
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{		
		int N, S, P;
		scanf("%d%d%d", &N, &S, &P);
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			int a;
			scanf("%d", &a);
			if (a % 3 == 0)
			{
				if (a / 3 >= P)
					res++;
				else if (S > 0 && a >= 3 && a / 3 + 1 >= P)
				{
					S--;
					res++;
				}
			}
			else if (a % 3 == 1)
			{
				if (a / 3 + 1 >= P)
					res++;
			}
			else
			{
				if (a / 3 + 1 >= P)
					res++;
				else if (S > 0 && a >= 2 && a / 3 + 2 >= P)
				{
					S--;
					res++;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, res);
	}

	return 0;
}