#include <stdio.h>
#include <algorithm>
using namespace std;

int l1[10000], l2[10000];

bool d1[10000], d2[10000];

int main()
{
	int tt;
	scanf("%d",&tt);
	for (int TT = 1; TT <= tt; TT++)
	{
		printf("Case #%d: ", TT);

		int N;
		scanf("%d",&N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d",&l1[i], &l2[i]);
			d1[i] = d2[i] = false;
		}

		int total = 0;
		int star = 0;

		for (int i = 0; i < 2 * N; i++)
		{
			int choose = 0;
			l2[0] = -1;
			for (int j = 1; j <= N; j++)
			{
				if (d1[j] == false && d2[j] == false && l2[j] <= star && l2[choose] < l2[j])
				{
					choose = j;
				}
			}
			if (choose)
			{
				d1[choose] = d2[choose] = true;
				star += 2;
				total++;
				if (star == N * 2) break;
				else continue;
			}

			for (int j = 1; j <= N; j++)
			{
				if (d1[j] == true && d2[j] == false && l2[j] <= star && l2[choose] < l2[j])
				{
					choose = j;
				}
			}
			if (choose)
			{
				d2[choose] = true;
				star++;
				total++;
				if (star == N * 2) break;
				else continue;
			}

			for (int j = 1; j <= N; j++)
			{
				if (d1[j] == false && l1[j] <= star && (l1[choose] < l1[j] || l1[choose] == l1[j] && l2[choose] < l2[j]))
				{
					choose = j;
				}
			}
			if (choose)
			{
				d1[choose] = true;
				star++;
				total++;
				continue;
			}
			else break;
		}
		printf(star == N * 2 ? "%d\n" : "Too Bad\n", total);
	}
	return 0;
}