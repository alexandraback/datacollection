#include<stdio.h>

int main()
{
	int tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	int taa[20];
	int T;

	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt","w");

	fscanf(fin, "%d", &T);

	int A,B,d;

	for(int i = 1; i <= T; i++)
	{
		fscanf(fin, "%d%d", &A, &B);

		d = 0;
		int tmp = A;
		while(tmp > 0)
		{
			d++;
			tmp /= 10;
		}

		int result = 0;

		for(int i = A; i <= B; i++)
		{
			for(int j = 0; j < d; j++)
			{
				int k = i / tens[j] + (i % tens[j]) * tens[d-j];
				taa[j] = k;
				int l = 0;
				for(; l < j; l++)
					if(k == taa[l]) break;
				if(k > i && k <= B && l == j) result++;
			}
		}
		fprintf(fout,"Case #%d: %d\n", i, result);
	}

	return 0;
}