#include<stdio.h>


int main()
{
	int test,t,i,j,k, n,m, a[100][100],max,flag;
	scanf("%d",&test);
	for(t=1;t<=test; t++)
	{
		scanf("%d%d",&n,&m);
		max=0; flag=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		}

		for(i=0;i<n;i++)
		{	max=0;
			for(j=0;j<m;j++)
			{ if(a[i][j]>max) max= a[i][j];

			}
			for(j=0;j<m;j++)
			{
				if(a[i][j]!=max)
				{
					for(k=0;k<n;k++)
					{
						if(a[k][j]>a[i][j])
							{flag=0; goto A;}
					}

				}
			}
		}

		for(j=0;j<m;j++)
		{	max=0;
			for(i=0;i<n;i++)
			{ if(a[i][j]>max) max= a[i][j];

			}
			for(i=0;i<n;i++)
			{
				if(a[i][j]!=max)
				{
					for(k=0;k<m;k++)
					{
						if(a[i][k]>a[i][j])
							{flag=0; goto A;}
					}

				}
			}
		}




		A:
		if(flag==0)printf("Case #%d: NO\n",t);
		else printf("Case #%d: YES\n",t );
	}

	return 0;
}


