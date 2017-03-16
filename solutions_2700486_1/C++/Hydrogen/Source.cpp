#include <stdio.h>

const int max=4000;

long double C[max][max];

void calculateC()
{
	C[0][0]=1;
	for(int i=1;i<max;i++)
	{
		C[i][0]=C[i][i]=C[i-1][0]/2;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])/2;
	}
}

int main()
{
	calculateC();
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int N,X,Y;
		scanf("%d%d%d",&N,&X,&Y);
		X=X>0?X:-X;
		int k;
		for(k=0;N>2*k*k+3*k+1;k++);
		long double ans=0;
		if(N==2*k*k+3*k+1)
			ans=(X+Y)/2<=k?1:0;
		else
		{
			if((X+Y)/2<k)
				ans=1;
			else if((X+Y)/2>k)
				ans=0;
			else
			{
				int m=N-(2*(k-1)*(k-1)+3*(k-1)+1);
				if(m<=2*k)
				{
					for(int i=Y+1;i<=m;i++)
						ans+=C[m][i];
				}
				else
				{
					if(Y+1<=m-2*k)
						ans=1;
					else
					{
						if(Y==k*2)
							ans=0;
						else
							for(int i=Y+1;i<=m;i++)
								ans+=C[m][i];
					}
				}
			}
		}
		printf("Case #%d: %.7Lf\n",t+1,ans);
	}
	return 0;
}