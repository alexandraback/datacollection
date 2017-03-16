#include<stdio.h>
#include<stdlib.h>

int count,w[505],d,x[505];
int c1[500],c2[500],n1,n2;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void subset(int cs,int k,int r)
{
	int i;
	x[k]=1;
	if(cs+w[k]==d)
	{ 
		if(count == 1)
			n2 = 0;
		else if(count == 0)
			n1 = 0;
		count++;
		for(i=0; i<=k; i++)
		{
			if(x[i]==1)
			{
				if(count == 1)
					c1[n1++]=w[i];
				else if(count == 2)
					c2[n2++]=w[i];
				
			}
		}
	}
	else if(cs+w[k]+w[k+1] <=d)
		subset(cs+w[k],k+1,r-w[k]);
	if((cs+r-w[k]>=d)&&(cs+w[k+1])<=d)
	{               
		x[k]=0;
		subset(cs,k+1,r-w[k]);
	}
}

int main()
{
	int t,y=0;
	scanf("%d",&t);
	while(y<t)
	{
		int sum=0,i,n;
		scanf("%d",&n);
		for(i=0; i<n; i++){
			scanf("%d",&w[i]);
			sum+=w[i];
		}
		qsort (w, n, sizeof(int), compare);
		int flag = 0;
		for(i=w[0];i<sum+1;i++)
		{
			d=i;
			count =0;
			subset(0,0,sum);
			if(count == 2){
				printf("Case #%d:\n",y+1);
				int j;
				for(j=0;j<n1;j++)
					printf("%d ",c1[j]);
				printf("\n");
				for(j=0;j<n2;j++)
					printf("%d ",c2[j]);
				printf("\n");
				flag = 1;	
				break;
			}
			
		}
		if(flag == 0)
			printf("Impossible\n");
		y++;
	}
	return 0;
}
