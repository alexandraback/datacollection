#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
	int counts = 0;

	freopen("D:\\1.in","r",stdin);
	freopen("D:\\1.out","w",stdout);
	scanf("%d\n",&counts);

	for(int j = 0; j < counts; j++)
	{
		int players = 0;
		int* scores;
		int belowavg[200];
		int sum = 0;
		scanf("%d",&players);
		scores = new int[players];
		for (int i = 0; i < players; i++)
		{
			scanf("%d",&scores[i]);
			sum+=scores[i];
		}
		double avg = double(sum*2.0f/players);
		int* p = belowavg;
		int lowcount = 0;
		int lowsum = 0;
		for (int i = 0; i < players; i++)
		{
			if (scores[i] < avg)
			{
				lowsum+=scores[i];
				lowcount++;
			}
		}
		double lowavg = (sum+lowsum)/(double)lowcount;
		printf("Case #%d:",j+1);

		for (int i = 0; i < players; i++)
		{
			if (avg <= scores[i])
			{
				printf(" 0.0000000");
				continue;
			}
			double result = 0;
			if (lowsum==0)
			{
				lowsum = 1;
			}
			result = ((lowavg-scores[i])/double(sum))*100;
			printf(" %6f",result);
		}
		printf("\n");

	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}