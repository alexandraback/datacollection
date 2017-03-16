#include <stdio.h>

const int MAXN = 10000;

int T, N, a[MAXN], b[MAXN];

void Solve ()
{
	scanf ("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf ("%d%d", a + i, b + i);

	int answer = 0;
	int needed = N;
	int have = 0;

	while (needed)
	{
		int flag = 0;
		answer ++;
		for (int i = 0; i < N; ++i)
			if (b[i] >= 0 && have >= b[i])
			{
				if (a[i] < 0)
					have += 1;
				else
					have += 2;

				needed --;
				b[i] = -1;
				a[i] = -1;
				flag = 1;
				break;
			}
		if (flag) continue;

		int index = -1;
		for (int i = 0; i < N; ++i)
			if (a[i] >= 0 && have >= a[i])
			{
				if (index == -1 || b[i] > b[index])
					index = i;
			}
		
		if (index >= 0)
		{
			have += 1;
			a[index] = -1;
			continue;
		}


		printf ("Too Bad\n");
		return;
	}

	printf ("%d\n", answer);
}

int main(int argc, char *argv[])
{
	freopen ("B-large.in", "r", stdin);
	freopen ("B-large.out", "w", stdout);

	scanf ("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		printf ("Case #%d: ", i);
		Solve ();
	}
	
	return 0;
}
