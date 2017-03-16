#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void find(int *c,int s,int e,int n,char con[1000][1000])
{
	if(*c>=2)
		return;
	if(s==e)
	{
		(*c)++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(i!=s)
			if(con[s][i]==1)
				find(c,i,e,n,con);
	}
}
int main()
{
	int t,i,n,cn;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(cn=1;cn<=t;cn++)
	{
		char con[1000][1000]={0};
		int m,j;
		printf("Case #%d: ",cn);
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&m);
	
			for(int k=0;k<m;k++)
			{
				int l;
				scanf("%d",&l);
				con[j][l-1]=1;
			}
		}
		int count=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				count=0;
				if(i==j)
					continue;
				find(&count,i,j,n,con);
				if(count >=2)
					break;
			}
			if(count >=2)
				break;
		}
		if(count>=2)
		{
			printf("Yes");
		}
		else
			printf("No");
		printf("\n");
	}
	return 0;
}