#include <stdio.h>
#include <stdlib.h>


int main()
{
	int N;
	char t;
	int Pdata[9];
	scanf_s("%d", &N);
	FILE *fp;
	fopen_s(&fp, "out2.out", "wt+");
	for (int Case = 1; Case <= N; Case++)
	{
		int D, P;
		for (int i = 0; i < 9; i++)
			Pdata[i] = 0;
		scanf_s("%d", &D);
		int pmax = 0;
		for (int i = 0; i < D; i++)
		{
			scanf_s("%d", &P);
			if (pmax < P)
				pmax = P;
			for (int j = 0; j < P; j++)
			{
				Pdata[j]++;
			}
		}
		unsigned char res;
		int timemin = 100;
		for (res = 0; res < (1<<(pmax-1))-1; res++)
		{
			int time = 0;
			int gapmax = 0;
			int gapstart = 0;
			for (int j = 0; j < pmax; j++)
			{
				if ((res >> j) & 1==1)
				{
					time += Pdata[j+1];
					if (gapmax < j + 1 - gapstart)
					{
						gapmax = j + 1 - gapstart;
						
					}
					gapstart = j + 1;
				}
			}
			if (gapmax < pmax - gapstart)
			{
				gapmax = pmax - gapstart;
			}
			time = time + gapmax;
			if (timemin > time)
				timemin = time;
		}
		if (pmax == 1)
			timemin = 1;
			fprintf(fp, "Case #%d: %d\n", Case,timemin);
			printf("Case #%d: %d\n", Case,timemin);

	}
	fclose(fp);
	N = getchar();
	system("Pause");
	return 0;
}