#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for (i=1;i<=t;i++)
	{

		int b, m;
		scanf("%d %d",&b, &m);



		printf("Case #%d: ",i);

		

		if (m>pow(2,b-2))
		{
			printf("IMPOSSIBLE\n");
		}

		else
		{
			printf("POSSIBLE\n");
			int a[7];
			int j,k, l;
			for (j=0;j<7;j++)
			{
				a[j]=0;
			}

			int mcopy=m-1;
			j=0;
			while(mcopy!=0)
			{
				a[j]=mcopy%2;
				mcopy=mcopy/2;
				j++;
			}

			int p=j;

			/*for (j=0;j<p;j++)
				printf("%d ",a[j]);

			printf("binary\n");*/

			int m[50][50];

			for (j=0;j<b;j++)
			{
				for (k=0;k<b;k++)
				{
					m[j][k]=0;
				}
			}

			for (l=1;l<b-1;l++)
			{
				for (j=l+1;j<b;j++)
				{
					m[l][j]=1;
				}                                   
			}

			m[0][b-1]=1;


			for (j=0;j<p;j++)
			{
				if (a[j]==1)
				{
					m[0][b-2-j]=1;
				}
			}


			for (j=0;j<b;j++)
			{
				for (k=0;k<b;k++)
				{
					printf("%d",m[j][k]);
				}
				printf("\n");
			}


			///////////////////////////////



		}
		













	}


	return 0;
}