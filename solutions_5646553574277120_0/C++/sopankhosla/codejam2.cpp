#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		int c,d,v,sum=0,sum1=0,sum2=0,sum3=0,sum4=0;	
		scanf("%d %d %d",&c,&d,&v);
		int den[d];
		for(int i=0;i<d;i++)
			scanf("%d",&den[i]);
		int arr[v+1],arr2[v+1];
		for(int i=0;i<=v;i++)
			arr[i]=0,arr2[i]=0;
		for(int i=0;i<d;i++)
		{
			
			sum+=den[i];
			for(int j=i+1;j<d;j++)
			{
				sum1+=den[j] + sum;
				for(int k=j+1;k<d;k++)
				{
					sum2+=den[k] + sum1;
					for(int l=k+1;l<d;l++)
					{
						sum3+=den[l] + sum2;
						for(int y=l+1;y<d;y++)
						{
							sum4+=den[y] + sum3;
							if(sum4 <= v)
								arr[sum4]=1;
							sum4=0;
						}
						if(sum3 <= v)
								arr[sum3]=1;
						sum3=0;
					}
					if(sum2 <= v)
								arr[sum2]=1;
					sum2=0;
				}
				if(sum1 <= v)
								arr[sum1]=1;
				sum1=0;
			}
			if(sum <= v)
				arr[sum]=1;
			sum=0;
		} 
		
		int count = 0;
		
		for(int i=1;i<=v;i++)
		arr2[i] = arr[i];
		for(int i=1;i<=v;i++)
		{
			if(arr[i]==0)
			{
				arr[i]=1;
				for(int j=1;j<=v-i;j++)
				{
					if(arr[j]==1 && j!=i)
					{
						arr2[j+i] = 1;
						
					}
				}
				count++;
			}
			for(int i=1;i<=v;i++)
		arr[i] = arr2[i];
		}
		
		printf("Case #%d: %d\n",++cas,count);		
	}
	return 0;
}
