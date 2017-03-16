#include<stdio.h>
#include<stdlib.h>
int main()
{
	int test,t,n,*s,i,sum,newsum,*check,count;
	float *x,*total;

	scanf("%d",&test);
	for(t=0;t<test;t++)
	{
		sum=0;
		scanf("%d",&n);
		s=(int *)malloc(n*sizeof(int));
			
		check=(int *)malloc(n*sizeof(int));	

		count=0;
		for(i=0;i<n;i++)
		{
			check[i]=0;
			scanf("%d",&s[i]);
			sum=sum+s[i];
		}
		x=(float *)malloc(n*sizeof(float));
		total=(float *)malloc(n*sizeof(float));
		printf("Case #%d: ",t+1);
		newsum=sum;
		for(i=0;i<n;i++)
                {
                        x[i]= ((sum*2.0/n  -s[i])/sum)*100;
                        if(x[i]<0)
                        {
			 	newsum=newsum-s[i];
                		check[i]=1;
				count++;
			}	
		}
	
		if (newsum!=sum)
		{
			for(i=0;i<n;i++)
                	{
                 	       if(check[i]==0)
				{
					x[i]=( ((sum+newsum)*1.0/(n-count)  -s[i])/sum)*100;
				}
			}
		}	

	
		for(i=0;i<n;i++)
		{
			if(x[i]<=0)
				printf("0.00000 ");
			else 
				printf("%0.5f ",x[i]);
		}
		printf("\n");
	}
	return 0;
}

