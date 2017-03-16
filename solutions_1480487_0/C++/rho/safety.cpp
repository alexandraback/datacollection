#include<stdio.h>
#include<string.h>
FILE* fin;
FILE* fout;

int main(void)
{
	fin=fopen("safety.in", "r");
	fout=fopen("safety.out", "w");
	int T;
	fscanf(fin, "%d", &T);
	for(int tnum=1; tnum<=T; tnum++)
	{
		int N;
		fscanf(fin, "%d", &N);
		int points[N];
		int S=0;
		for(int i=0; i<N; i++)
		{
			fscanf(fin, "%d", &points[i]);
			S+=points[i];
		}
		fprintf(fout, "Case #%d:", tnum);
		for(int i=0; i<N; i++)
		{
			double H=1.0, L=0.0;
			while(H-L>1e-9)
			{
				double M = (H+L)/2;
				double left = 1.0-M;
				for(int j=0; j<N; j++)
					if(j!=i && points[j]<points[i]+S*M)
						left-=(points[i]+S*M-points[j])/S;
				if(left>0)
					L=M;
				else
					H=M;
			}
			fprintf(fout, " %lf", H*100);
		}
		fprintf(fout, "\n");
		//getchar();
	}
	return 0;
}
