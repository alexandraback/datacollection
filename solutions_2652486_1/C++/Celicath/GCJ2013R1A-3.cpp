/* 2013.4.27 Yoshi-TS4 */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

int n[100];
int k[100];
bool s[100];
int min[100];

int main()
{
	srand(unsigned(time(NULL)));
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;
	int R, N, M, K;

	fscanf(fin, "%d", &T);

	for(int a = 1; a <= T; a++)
	{
		fscanf(fin, "%d%d%d%d", &R, &N, &M, &K);

		fprintf(fout, "Case #%d:\n", a);

		while(R --> 0)
		{
			for(int i = 2; i < 8; i++)
			{
				min[i] = -1;
			}
			for(int i = 0; i < K; i++)
			{
				fscanf(fin, "%d", k + i);
				int tmp = k[i];
				int tmp2 = 0;
				while(tmp % 2 == 0)
				{
					tmp /= 2;
					tmp2++;
				}
				if(tmp2 > min[2]) min[2] = tmp2;

				tmp = k[i];
				tmp2 = 0;
				while(tmp % 3 == 0)
				{
					tmp /= 3;
					tmp2++;
				}
				if(tmp2 > min[3]) min[3] = tmp2;

				tmp = k[i];
				tmp2 = 0;
				while(tmp % 5 == 0)
				{
					tmp /= 5;
					tmp2++;
				}
				if(tmp2 > min[5]) min[5] = tmp2;

				tmp = k[i];
				tmp2 = 0;
				while(tmp % 7 == 0)
				{
					tmp /= 7;
					tmp2++;
				}
				if(tmp2 > min[7]) min[7] = tmp2;
			}

			int index = N;
			for(int i = 0; i < min[7]; i++)
				n[--index] = 7;
			for(int i = 0; i < min[5]; i++)
				n[--index] = 5;
			for(int i = 0; i < min[3]; i++)
				n[--index] = 3;

			for(int tested = 0; tested < 100; tested++)
			{
				for(int i = 0; i < index; i++)
					n[i] = 1 << (rand() % 3 + 1);
				for(int i = 0; i < K; i++)
				{
					for(int j = 0; j < N; j++)
						s[j] = false;
					for(;;)
					{
						int p = 1;
						for(int j = 0; j < N; j++)
							if(s[j]) p *= n[j];
						if(p == k[i]) break;

						int j = N - 1;
						for(; j >= 0; j--)
						{
							s[j] = !s[j];
							if(s[j]) break;
						}
						if(j < 0) goto mang;
					}
				}
				goto hell;
				mang:;
			}
			hell:

			for(int i = 0; i < N; i++)
				fprintf(fout, "%d", n[i]);
			fprintf(fout, "\n");
		}
	}

	return -0;
}
