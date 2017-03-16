#include <cstdio>

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		int n;
		double data[200];
		scanf("%d", &n);
		double sum=0;
		for(int i=0;i<n;i++) 
		{
			scanf("%lf", data+i);
			sum+=data[i];
		}

		printf("Case #%d:", caseN);
		for(int i=0;i<n;i++)
		{
			double s=0, e=1, mid;
			for(int j=0;j<50;j++)
			{
				mid = (s+e)/2;
				double curVote = data[i] + sum*mid;
				double left = 1 - mid;
				for(int k=0;k<n;k++)
				{
					if(i==k) continue;
					if(data[k] < curVote) left -= (curVote - data[k])/sum;
				}

				if(left > 0) s=mid;
				else e=mid;
			}

			printf(" %lf", s * 100);
		}

		printf("\n");
	}

	return 0;
}
