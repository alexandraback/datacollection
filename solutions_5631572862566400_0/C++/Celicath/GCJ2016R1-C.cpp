/* 2016.4.16 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>

int bff[2000];
int pbff[2000];	// paired bff
bool checked[2000];
int d_pbff[2000];	// 최종 목적 pbff 위치
int n_pbff[2000];	// pbff까지 가는 거리
int pbff_begin[2000];

int max = 0;


int Go(int n)
{
	if (d_pbff[n] == 0)
	{
		if (pbff[n] != 0)
		{
			d_pbff[n] = n;
			n_pbff[n] = 0;
			pbff_begin[n] = n;
			return n;
		}
		else
		{
			d_pbff[n] = -1;
			d_pbff[n] = Go(bff[n]);
			n_pbff[n] = n_pbff[bff[n]] + 1;
			if (n_pbff[n] > n_pbff[pbff_begin[d_pbff[n]]])
				pbff_begin[d_pbff[n]] = n;
		}
	}
	return d_pbff[n];
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;
		fscanf(fin, "%d", &N);

		for (int i = 1; i <= N; i++)
		{
			bff[i] = pbff[i] = 0;
		}
		for (int i = 1; i <= N; i++)
		{
			fscanf(fin, "%d", &bff[i]);
			if (bff[bff[i]] == i)
			{
				pbff[i] = bff[i];
				pbff[bff[i]] = i;
			}
		}

		// step 1: check cycle
		max = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				checked[j] = false;

			checked[i] = true;
			int count = 1;
			for (int next = bff[i]; ; next = bff[next])
			{
				if (next == i)
				{
					max = std::max(max, count);
					break;
				}
				else if (checked[next])
					break;
				checked[next] = true;
				count++;
			}
		}

		// step 2: check whatever
		for (int i = 1; i <= N; i++)
		{
			d_pbff[i] = 0;
			pbff_begin[i] = 0;
		}

		for (int i = 1; i <= N; i++)
		{
			Go(i);
		}

		int score2 = 0;
		for (int i = 1; i <= N; i++)
			checked[i] = false;
		for (int i = 1; i <= N; i++)
		{
			if (pbff_begin[i] > 0)
			{
				for (int next = pbff_begin[i];; next = bff[next])
				{
					if (checked[next])
						break;
					checked[next] = true;
					score2++;
				}
			}
		}

		max = std::max(max, score2);

		fprintf(fout, "Case #%d: %d\n", c_n, max);
		printf("Case #%d: %d\n", c_n, max);

	}
	return -0;
}
