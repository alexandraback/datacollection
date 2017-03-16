#include<stdio.h>
#include<math.h>
#define M 200
#define eps 1e-9

int fix(double x)
{
	if(fabs(x)<=eps) return 0;
	else if(x>eps) return 1;
	else return -1;
} 
double score[M+10];
double ans[M+10];

int main()
{
	freopen("E:\\A-small-attempt1.in","r",stdin);
	freopen("E:\\A-small-attempt1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cse=1;cse<=T;cse++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lf",&score[i]);
		
		double sum=0;
		for(int i=1;i<=n;i++) sum+=score[i];
		for(int i=1;i<=n;i++)
		{
			double low=0,high=1;
			while(fix(high-low)>0)
			{
				double mid=(low+high)/2;
				double bond=sum*mid+score[i];
				double need=0;
				for(int j=1;j<=n;j++)
					if(j!=i&&fix(bond-score[j])>0)
						need+=bond-score[j];
				if(fix((1-mid)*sum-need)>=0) low=mid;
				else high=mid;
			}
			ans[i]=100*(low+high)/2;
		}
		
		printf("Case #%d: ",cse);
		for(int i=1;i<=n;i++)
			if(i==n) printf("%.6f\n",ans[i]);
			else printf("%.6f ",ans[i]);
	}
	return 0;
}
