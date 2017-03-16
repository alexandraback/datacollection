#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int b[1005][1005];
int main()
{
	int x;
	   int  ch=0;
	scanf("%d",&x);
	while(x--)
	{
		ch++;
		int y;
		scanf("%d",&y);
		int i,j,k;
		for(i=0;i<=y;i++)
		{
			for(j=0;j<=y;j++)
			{
				b[i][j]=0;
			}
		}
		int m,num;
		for(i=1;i<=y;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&num);
				b[i][num]++;
			}
		}
		for(k=1;k<=y;k++)
		{
			for(i=1;i<=y;i++)
			{
				for(j=1;j<=y;j++)
				{
					if(b[i][k]>0&&b[k][j]>0)
					{
						b[i][j]++;
					}
				}
			}
		}
		k=0;
		for(i=1;i<=y;i++)
		{
			for(j=1;j<=y;j++)
			{
				if(b[i][j]>=2)
           				{
						k=1;
						printf("Case #%d: Yes\n",ch);
								break;
								}
										}
							if(k==1)
								break;
								}
								if(!k)
								printf("Case #%d: No\n",ch);
									}
									return 0;
}
