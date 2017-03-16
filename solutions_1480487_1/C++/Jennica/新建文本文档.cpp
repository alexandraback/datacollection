#include<iostream>
#include<cstdio>
#include<cstdio>
using namespace std;
double a[210];
double sum,ave,sum2,ave2,temp=0.0;
int main()
{
	int T,t,N,i,count;
	//freopen("A-large.in","r",stdin);
	//freopen("ProblemA.out","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;++t)
	{
		count=0;
		printf("Case #%d:",t);
		sum=0;
		scanf("%d",&N);
		for(i=0;i<N;++i)
		{
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		ave=sum*2/N;	

		sum2=0;
		for(i=0;i<N;++i)
		{
			if(a[i]<ave)
			{sum2+=a[i];
			++count;
			}
		}
		ave2=(sum+sum2)/count;
		for(i=0;i<N;++i)
		{
			if(a[i]<ave)
			    printf(" %f",100*(ave2-a[i])/sum);
			else
			{
				printf(" %f",temp);
			}
		}
		printf("\n");
	}
	return 0;
}