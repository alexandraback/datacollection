/* 2015.4.11 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <iostream>

int P[2000];
int Pp[3000];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int D;
		fscanf(fin, "%d", &D);
		for (int i = 0; i < D; i++)
			fscanf(fin, "%d", P + i);
		std::make_heap(P, P + D);

		int max = P[0];

		for (int th = max - 1; th > 1; th = std::min(th - 1, max - 1))
		{
			for (int i = 0; i < D; i++)
				Pp[i] = P[i];

			int Dp = D;
			bool success = false;
			int t = 0;
			while (true)
			{
				int k = Pp[0];
				if (k <= th)
				{
					success = true;
					break;
				}
				t++;
				if (t >= max)
					break;

				std::pop_heap(Pp, Pp + Dp);

				Pp[Dp - 1] = th;
				Pp[Dp] = k - th;
				std::push_heap(Pp, Pp + (Dp++));
				std::push_heap(Pp, Pp + Dp);
			}
			if (success)
				max = std::min(max, t + Pp[0]);
		}

		fprintf(fout, "Case #%d: %d\n", c_n, max);
		printf("Case #%d: %d\n", c_n, max);
	}
	return -0;
}
