#include <cstdio>

using namespace std;

int main()
{
	long long int t;
	scanf("%lld",&t);
	long long int i;
	for (i=1;i<=t;i++)
	{

		long long int b, m;
		scanf("%lld %lld",&b, &m);



		printf("Case #%lld: ",i);

		long long int var1, var2=1;


		for (var1=0;var1<b-2;var1++)
		{
			var2=var2*2;
		}

		if (m>var2)
		{
			printf("IMPOSSIBLE\n");
		}

		else
		{
			printf("POSSIBLE\n");
			long long int a[8];
			long long int j,k, l;
			for (j=0;j<7;j++)
			{
				a[j]=0;
			}

			long long int mcopy=m-1;
			j=0;
			while(mcopy!=0)
			{
				a[j]=mcopy%2;
				mcopy=mcopy/2;
				j++;
			}

			long long int p=j;

			/*for (j=0;j<p;j++)
				printf("%d ",a[j]);

			printf("binary\n");*/

			long long int m[50][50];

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
					printf("%lld",m[j][k]);
				}
				printf("\n");
			}


			///////////////////////////////



		}
		













	}


	return 0;
}