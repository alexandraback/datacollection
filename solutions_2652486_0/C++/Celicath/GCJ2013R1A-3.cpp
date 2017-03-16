/* 2013.4.27 Yoshi-TS4 */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

int n[100];
int k[100];
bool s[100];

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
			for(int i = 0; i < K; i++)
				fscanf(fin, "%d", k + i);

			for(;;)
			{
				for(int i = 0; i < N; i++)
					n[i] = rand() % (M - 1) + 2;
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
