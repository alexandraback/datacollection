#include "stdafx.h"
#include <algorithm>

using namespace std;

int main()
{
	int t, n;
	FILE* f = fopen("A-large.in", "r");
	FILE* out = fopen("a.out.txt", "w");
	fscanf(f, "%d", &t);
	for (int it = 0; it < t; it++)
	{
		int a, n;
		int sizes[200];

		fscanf(f, "%d %d", &a, &n);
		for (int i = 0; i < n; i++)
		{
			fscanf(f, "%d", &sizes[i]);
		}

		sort(sizes, sizes + n);

		if (a == 1)
		{
			fprintf(out, "Case #%d: %d\n", it + 1, n);
			continue;
		}

		int minOp = n;
		for (int i = n; i >= 1; i--)
		{
			int op = n - i;

			int ca = a;
			for (int j = 0; j < i; j++)
			{
				if (ca > sizes[j])
					ca += sizes[j];
				else
				{
					while (ca <= sizes[j])
					{
						ca += ca - 1;
						op++;
					}
					ca += sizes[j];
				}
			}
			if (op < minOp) minOp = op;
		}

		fprintf(out, "Case #%d: %d\n", it + 1, minOp);
	}
}