#include<iostream>
#include<stdio.h>
int main()
{
int T,t;
bool f;
bool c[101][101];
int a[101][101];
int M,N;
int i,j,l,m;
scanf("%d",&T);
for(t=1;t<=T;t++)
	{
	f=0;
	scanf("%d %d",&N,&M);
	//N row
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			{scanf("%d",&a[i][j]);c[i][j]=false;}	
		/*
		if(t==11)
			{
	for(i=0;i<N;i++)
		{for(j=0;j<M;j++)
			{printf("%d",a[i][j]);}	
		printf("\n");
		}	
			}*/
	for(i=0;i<N;i++)
		{
		for(j=0;j<M;j++)
				{
				if(c[i][j]==true)
				continue;
				m=a[i][j];
				for(l=0;l<N;l++)
					{
					if(m<a[l][j])
					break;
					}
				if(l==N)
					{
					for(l=0;l<N;l++)
						{
						if(m==a[l][j])
							c[l][j]=true;
						}	
					}
				if(c[i][j]==true)
				continue;
				m=a[i][j];
				for(l=0;l<M;l++)
					{
					if(m<a[i][l])
					break;
					}
				if(l==M)
					{
					for(l=0;l<M;l++)
						{
						if(m==a[i][l])
							c[i][l]=true;
						}	
					}
				if(c[i][j]==false)
					{i=N;j=M;f=1;}
				}
		}
	printf("Case #%d: ",t);
	if(f==1)
		{
		printf("NO\n");	
		}
	else
		{
		printf("YES\n");	
		}
	}
return 0;
}
