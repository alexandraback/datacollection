#include <stdio.h>
#include <stdlib.h>
int res[1000][3];
int Pdata[1000];
int reslength;
int pmax;

int cal()
{
	int time = 0;
	int gapstart = 0;
	int gapmax = 0;
	for (int i = 0; i < reslength; i++)
	{
		if (gapmax < res[i][0] - gapstart)
			gapmax = res[i][0] - gapstart;
		gapstart = res[i][0];
		time += Pdata[res[i][0]];
	}
	if (gapmax < pmax - gapstart)
	{
		gapmax = pmax - gapstart;
	}
	time += gapmax;
	return time;
}

int main()
{
	int N;
	char t;
	FILE *fp;
	FILE *fpread;
	fopen_s(&fp, "out02.out", "wt+");
	fopen_s(&fpread, "in.in", "r");

	fscanf_s(fpread,"%d", &N);

	
	for (int Case = 1; Case <= N; Case++)
	{
		int D, P,buffer[1000];
		for (int i = 0; i < 9; i++)
			Pdata[i] = 0;
		fscanf_s(fpread,"%d", &D);
		pmax = 0;
		for (int i = 0; i < D; i++)
		{
			fscanf_s(fpread,"%d", &P);
			buffer[i] = P;
			if (pmax < P)
				pmax = P;
			for (int j = 0; j < P; j++)
			{
				Pdata[j]++;
			}
		}
		int timemin = 1000;
		
		timemin = pmax;
		reslength = 1;
		res[0][0] = 1;
		while (res[0][0]<pmax)
		{
			if (res[reslength - 1][0] >= pmax)
			{
				reslength--;
				res[reslength - 1][0]++;
				continue;
			}
			int temptime = cal();
			if (temptime < timemin)//update timemin and resform
			{
				timemin = temptime;
				reslength++;
				res[reslength - 1][0] = res[reslength - 2][0]+1;
			}
			else//updateresform
			{
				res[reslength - 1][0]++;
			}
		}
		if (pmax == 1)
			timemin = 1;
		fprintf(fp, "Case #%d: %d\n", Case, timemin);
		printf("Case #%d: %d\n", Case, timemin);

	}
	fclose(fp);
	N = getchar();
	system("Pause");
	return 0;
}