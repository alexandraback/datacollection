#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define maxn 500

bool x[maxn];
bool y[maxn];
long long value[maxn];

bool Backtrack(int i, int N, long long sumx, long long sumy)
{
	
	int j = 0;
	if(sumx == sumy && sumx != 0)
	{
		
		return true;
	}
	if(i == N) return false;
			
	x[i] = 1;
	y[i] = 0;
	if(Backtrack(i+1, N, sumx+value[i], sumy)) return true;

	x[i] = 0;
	y[i] = 0;
	if(Backtrack(i+1, N, sumx, sumy)) return true;

	x[i] = 0;
	y[i] = 1;
	if(Backtrack(i+1, N, sumx, sumy+value[i])) return true;

	return false;
}

int main()
{
	FILE *fp = fopen("C:\\Users\\Jeffrey\\Desktop\\A-large.in", "r");
	FILE *fp1 = fopen("C:\\Users\\Jeffrey\\Desktop\\output.txt", "w");

	int T = 0;
	int t = 0;
	//scanf("%d", &T);
	fscanf(fp, "%d", &T);
	while(t++ < T)
	{
		int N = 0;
		int i = 0, j = 0;

		//scanf("%d", &N);
		fscanf(fp, "%d", &N);
		for(i = 0; i < N; i++)
		{
			//scanf("%lld", &value[i]);
			fscanf(fp, "%lld", &value[i]);
		}

		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));

		printf("Case #%d:\n", t);
		fprintf(fp1, "Case #%d:\n", t);
		if(Backtrack(0, N, 0, 0))
		{
			for(j = 0; j < N; j++)
				if(x[j]) { printf("%d", value[j]); fprintf(fp1, "%d", value[j]); break; }
			for(j++; j < N; j++)
				if(x[j])
				{
					printf(" %d", value[j]);
					fprintf(fp1, " %d", value[j]);
				}
			printf("\n");
			fprintf(fp1, "\n");

			for(j = 0; j < N; j++)
				if(y[j]) { printf("%d", value[j]); fprintf(fp1, "%d", value[j]); break; }
			for(j++; j < N; j++)
				if(y[j])
				{
					printf(" %d", value[j]);
					fprintf(fp1, " %d", value[j]);
				}
			printf("\n");
			fprintf(fp1, "\n");
		}
		else
		{
			printf(" Impossible\n");
			fprintf(fp1, " Impossible\n");
		}
	}

	fclose(fp);
	fclose(fp1);
	return 0;
}

