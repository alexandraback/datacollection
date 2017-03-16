#include <stdio.h>

int REQ[1024][2];
int STATUS[1024];
int stars;
int plays;
int ok;


int main(void)
{
	int T, N;
	int now, i;

	scanf("%d", &T);

	now = T;
	while (now--)
	{
		scanf("%d", &N);

		for (i = 0; i < N; i++)
		{
			scanf("%d%d", &REQ[i][0], &REQ[i][1]);
			STATUS[i] = 0;
		}

		stars = 0;
		plays = 0;
		while (1)
		{
			if (stars == N*2)
				break;

			for (i = 0; i < N; i++)
			{
				ok = 0;
				if (STATUS[i] == 0 && REQ[i][1] <= stars)
				{
					stars += 2;
					STATUS[i] = 2;
					plays++;
					ok = 1;
					break;
				}
			}
			if (ok) continue;

			for (i = 0; i < N; i++)
			{
				ok = 0;
				if (STATUS[i] == 1 && REQ[i][1] <= stars)
				{
					stars += 1;
					STATUS[i] = 2;
					plays++;
					ok = 1;
					break;
				}
				if (STATUS[i] == 0 && REQ[i][0] <= stars)
				{
					stars += 1;
					STATUS[i] = 1;
					plays++;
					ok = 1;
					break;
				}
			}
			if (ok) continue;

			break;
		}

		
		printf("Case #%d: ", T - now);
		if (stars == N*2)
			printf("%d\n", plays);
		else
			printf("Too bad\n");
	}

	return 0;
}
