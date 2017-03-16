#include<stdio.h>
int main()
{
	long long int count,Test,N,s[205],order[205],index[205],i,j,x=0,t,temp,min,mini,pre,nex,prevsum;
	scanf("%lld",&Test);
	double sum,sa;
	for(t=1;t<Test+1;t++)
	{
		x=0;
		scanf("%lld",&N);
		for(i=0;i<N;i++)
		{
			scanf("%lld",&s[i]);
			order[i]=s[i];
			x+=s[i];
			index[i]=-1;
		}
		sum=x;
		for(i=0;i<N;i++)
		{
			min=order[i];
			mini=i;
			for(j=i+1;j<N;j++)
			{
				if(order[j]<min)
				{
					min=order[j];
					mini=j;
				}
			}
			temp=order[i];
			order[i]=min;
			order[mini]=temp;
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(order[i]==s[j] && index[j]==-1)
				{
					index[j]=i;
					break;
				}
			}
		}
		printf("Case #%lld:",t);
		for(i=0;i<N;i++)
		{
			order[N]=45678909;
			sum=x;
			for(j=0;j<index[i];j++)
			{
				sum-=order[index[i]]-order[j];
			}
			count=index[i]+1;
			if(sum<=0)
			{
				printf(" %lf",0.0);
				sum=x;
				continue;
			}
			pre=count-1;
			nex=count;
			while(sum>0)
			{
				prevsum=sum;
				sum-=count*(order[nex]-order[pre]);
				if(sum<=0)
				{
					printf(" %lf",(((prevsum*1.0)/(count)+(order[pre]-order[index[i]]))/x)*100);
					sum=x;
					break;
				}
				pre=nex;
				nex++;
				count++;
			}
		}
		printf("\n");
	}
	return 0;
}
