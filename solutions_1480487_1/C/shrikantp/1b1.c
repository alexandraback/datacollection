#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,i,j,sum,max,k,n,r,weight[201],tw,maxi,smax,count;
int points[201],len[51];
double score[51][201];
double fraction;
r=scanf("%d",&t);
for(k=0;k<t;k++)
{
	r=scanf("%d",&n);
	len[k]=n;
	
	sum=0;
	fraction=1;
	
	smax=32767;
	for(i=0;i<n;i++)
	{
		r=scanf("%d",&points[i]);
		sum=sum+points[i];
	}
	tw=sum+1;
	while(tw>sum)
	{
		tw=0;
		max=-1;
		count=0;
		for(i=0;i<n;i++)
		{

			if(points[i]<smax)
			{
				if(points[i]>max )
				{
					max=points[i];	
					maxi=i;
				}	
				count++;
			}	
				
		}
		for(i=0;i<n;i++)
		{
			weight[i]=max-points[i];
			if(weight[i]<0)
				weight[i]=0;
			tw=tw+weight[i];
		}
		smax=max;
	}

	for(i=0;i<n;i++)
	{
		score[k][i]=(max-points[i])/(double)sum;
		if(score[k][i]<0)
			score[k][i]=0;
		fraction=fraction-score[k][i];
	}
	//printf("c %d\n",count);
	for(i=0;i<n;i++)
	{
		if(points[i]<=max)
		score[k][i]=score[k][i]+fraction/count;
	}	
	
}
for(k=0;k<t;k++)
{
	printf("Case #%d:",k+1);
	for(i=0;i<len[k];i++)
	{
		printf(" %lf",score[k][i]*100);;
	}
	printf("\n");
}
return 0;
}
