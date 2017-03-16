#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int n,i,sc[1005],sum,t,cs;
	freopen("safety1.in","r",stdin);
	freopen("safety1.out","w",stdout);
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		int zero = 0;
		int nonzero_idx = -1;
		int swapped = 0;
		for(i=sum=0;i<n;i++)
		{
			scanf("%d",&sc[i]), sum += sc[i];
			if(sc[i]==0)
				zero++;
			else
				nonzero_idx = i;
		}
		
		if(sc[n-1]==0)
		{
			swap(sc[n-1],sc[nonzero_idx]);
			swapped = 1;
		}
		double ans[1005],v = 0;
		for(i=0;i<n-1;i++)
	//		if(sc[i])
				v += (sc[n-1] - sc[i]);
//		if(zero)
//			v += (sc[n-1]);
//		if(zero)
//			ans[n-1] = (sum - v)/((n-zero+1)*sum);
//		else
			ans[n-1] = (sum - v)/((n)*sum);
		printf("Case #%d:",cs+1);
		for(i=0;i<n-1;i++)
		{
			ans[i] = (sc[n-1] - sc[i] + 0.000)/sum + ans[n-1];
	//		if(!sc[i])
	//			ans[i] /= zero;
		}

		if(swapped)
			swap(ans[n-1],ans[nonzero_idx]);

		/*int got = 0;
		for(i=0;i<n;i++)
			if(!sc[i])
				ans[i] /= zero;*/
		/*	
		if(got)
			for(i=0;i<n;i++)
				if(!sc[i])
					ans[i] = 1.0/got;
				else
					ans[i] = 0.0; */

		for(i=0;i<n;i++)
			if(ans[i]<0)
				printf(" %.6lf",0.0);
			else
				printf(" %.6lf",ans[i]*100.0);
		printf("\n");
	}
	return 0;
}