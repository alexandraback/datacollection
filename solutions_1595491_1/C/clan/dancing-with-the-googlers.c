#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

struct cases
{
	int surprising, non_surprising;
};

int 
cmp_surprising(const void *a, const void *b)
{
	return ( (*(struct cases *)a).surprising - (*(struct cases *)b).surprising );
}

int 
cmp_non_surprising(const void *a, const void *b)
{
	return ( (*(struct cases *)a).non_surprising - (*(struct cases *)b).non_surprising );
}

int
main(void)
{
	freopen("input", "r", stdin);
	freopen("output","w", stdout);

	int test_num, googler_num, surprising_num, p;
	struct cases point[100];
	scanf("%d", &test_num);

	int i;
	for (i = 0; i < test_num; ++i)
	{
		scanf("%d%d%d", &googler_num, &surprising_num, &p);
		int j, score_sum;
		for (j = 0; j < googler_num; ++j)
		{
			scanf("%d", &score_sum);
			if (score_sum == 0)
			{
				point[j].surprising = -1;
				point[j].non_surprising = 0;
			}
			else if (score_sum == 1)
			{
				point[j].surprising = -1;
				point[j].non_surprising = 1;
			}
			else 
			{
				switch (score_sum % 3)
				{
					case 0:
					point[j].surprising = score_sum / 3 + 1;
					point[j].non_surprising = score_sum / 3;
					break;
					case 1:
					point[j].surprising = point[j].non_surprising = score_sum / 3 + 1;
					break;
					case 2:
					point[j].surprising = score_sum / 3 + 2;
					point[j].non_surprising = score_sum / 3 + 1;
					break;
					default:
					break;
				}
			}
		}
		qsort(point, googler_num, sizeof(struct cases), cmp_non_surprising);
		int counter = 0;
		while (counter < googler_num && point[googler_num - 1 - counter].non_surprising >= p)
		{
			++counter;
		}
		qsort(point, googler_num - counter, sizeof(struct cases), cmp_surprising);
		while (surprising_num && counter < googler_num && point[googler_num - 1 - counter].surprising >= p)
		{
			--surprising_num;
			++counter;
		}
		printf("Case #%d: %d\n", i+1, counter);
	}
}