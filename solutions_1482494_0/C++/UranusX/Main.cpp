#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <utility>

using namespace std;

int N;
int A[1024], B[1024];
int Status[1024];
int Star, Ans;

void Work()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i ++)
		scanf("%d%d", &A[i], &B[i]);
	Star = 0;
	Ans = 0;
	memset(Status, 0, sizeof(Status));
	while (Star < 2 * N)
	{
		int Changed;
		do
		{
			Changed = 0;
			for (int i = 0; i < N; i ++)
			{
				if (Status[i] == 2)
					continue;
				else if (Status[i] == 1)
				{
					if (B[i] <= Star)
					{
						Star ++;
						Ans ++;
						Changed = 1;
						Status[i] = 2;
					}
				}
				else
				{
					if (B[i] <= Star)
					{
						Star += 2;
						Ans ++;
						Changed = 1;
						Status[i] = 2;
					}
				}
			}
		}
		while (Changed);

		int P = -1;
		for (int i = 0; i < N; i ++)
			if (Status[i] == 0 && A[i] <= Star)
				if (P == -1 || B[i] > B[P])
					P = i;

		if (P == -1)
			break;

		Star ++;
		Ans ++;
		Status[P] = 1;
	}

	if (Star == 2 * N)
		printf("%d\n", Ans);
	else
		printf("Too Bad\n");
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: ", Case);
		Work();
	}
	return 0;
}