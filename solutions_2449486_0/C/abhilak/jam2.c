#include<stdio.h>

int main()
{
	int t,n,m,i,j,flag1,flag2;
	int a[100][100],maxr[100],maxc[100],test;

	scanf("%d",&t);test=0;
	while(t--)
	{test++;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			maxr[i]=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]>maxr[i])maxr[i]=a[i][j];
			}
		}
		for(i=0;i<m;i++)
		{
			maxc[i]=0;
			for(j=0;j<n;j++)
			{
				if(a[j][i]>maxc[i])maxc[i]=a[j][i];
			}
		}
		flag1=1;
		for(i=0;(i<n)&&flag1;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]<maxr[i])
				{
					if(a[i][j]!=maxc[j]){flag1=0;break;}
				}
			}
		}
		flag2=1;
		for(i=0;(i<m)&&flag2;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][i]<maxc[i])
				{
					if(a[j][i]!=maxr[j]){flag2=0;break;}
				}
			}
		}
		
		if(flag1&&flag2)printf("Case #%d: YES\n",test);
		else printf("Case #%d: NO\n",test);
}
return 0;
}















		


