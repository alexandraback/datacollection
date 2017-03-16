#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100000000
int n[100];
unsigned int num[100][100];
long long int checklist[MAX];
int main()
{
	int t;
	freopen("C-small-attempt2.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&t);
	for(int x=0;x<t;x++)
	{
		memset(checklist,0,sizeof(long long)*MAX);
		scanf("%d",&n[x]);
		for(int y=0;y< n[x]; y++)
			scanf("%d",&num[x][y]);
		printf("\nCase #%d:\n ",x+1);
		for(int a=0;a<pow(2,n[x]);a=a+1)
    	{
		    int sum=0;
		    for(int i=0;i<n[x];i++)
		    {
		        if((a&(int)pow(2,i))!=0)
		        {
		           
		            sum=sum+num[x][i];
		        }
		       
		    }
		    if(checklist[sum])
		    {
		    	int b =checklist[sum];
		    	for(int i=0;i<n[x];i++)
		    	{
		        	if((b&(int)pow(2,i))!=0)
		        	{
		           		printf("%d ",num[x][i]);
		        	}
		        }
		        printf("\n");
		        for(int i=0;i<n[x];i++)
		    	{
		        	if((a&(int)pow(2,i))!=0)
		        	{
		           		printf("%d ",num[x][i]);
		        	}
		        }
		        break;
		        
		    }
		    checklist[sum]=a;
    	}
	}
	
	return 0;
}
