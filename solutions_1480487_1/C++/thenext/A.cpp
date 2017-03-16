#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define maxn 200
#define INF 32767

int main()
{
	FILE *fp = fopen("C:\\Users\\Jeffrey\\Desktop\\A-small-attempt0.in", "r");
	FILE *fp1 = fopen("C:\\Users\\Jeffrey\\Desktop\\output.txt", "w");

	int T = 0;
	int t = 0;
	//scanf("%d", &T);
	fscanf(fp, "%d", &T);
	while(t++ < T)
	{
		int N = 0, N_= 0;
		int i = 0, j = 0;
		double value[maxn];
		double sum = 0;
		double Sum = 0;
		double p = 0;
		//scanf("%d", &N);
		fscanf(fp, "%d", &N);
		for(i = 0; i < N; i++)
		{
			//scanf("%lf", &value[i]);
			fscanf(fp, "%lf", &value[i]);
			sum += value[i];
		}

		//sum *= 2;
		Sum = sum*2;
		p = Sum/N;
		N_ = N;
		
		for(i = 0; i < N; i++)
			if(value[i] >= p)
			{
				Sum -= value[i];
				value[i] = INF;
				N_--;
			}
		printf("Case #%d:", t);
		fprintf(fp1, "Case #%d:", t);
		for(i = 0; i < N; i++)
		{
			if(value[i] == INF)
				printf(" 0.000000");
			else
				printf(" %.6lf", ((Sum/N_-value[i])/sum)*100);
			if(value[i] == INF)
				fprintf(fp1, " 0.000000");
			else
				fprintf(fp1, " %.6lf", ((Sum/N_-value[i])/sum)*100);
		}
		printf("\n");
		fprintf(fp1, "\n");
	}


	fclose(fp);
	fclose(fp1);
	return 0;
}

