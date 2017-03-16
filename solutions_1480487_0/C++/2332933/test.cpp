#include <iostream>
#include<string>
#include<stdio.h>

using namespace std;

int score[210];
double ans[210];

int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	int i,j;
	int n,srest,crest;
	int sum;
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		sum=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&score[i]);
			sum+=score[i];
			ans[i]=-1;
		}

		srest=sum,crest=n;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (ans[i]<0 && score[i]>=(srest+sum)/crest)
				{
					srest-=score[i];
					crest--;
					ans[i]=0;
				}
			}
		}
		for (i=0;i<n;i++)
		{
			if (ans[i]<0)
			{
				ans[i]=1.0*(srest+sum)/sum/crest-1.0*score[i]/sum;
			}
		}
		printf("Case #%d:",t);
		for (i=0;i<n;i++)
			printf(" %f",ans[i]*100);
		printf("\n");
	}
	return 0;
}