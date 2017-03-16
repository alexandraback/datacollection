#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,j,k,n,p,u,T,m,s;
	int a[11][11][11];
	int a1[11][11],a2[11][11],a3[11][11];
	char c[1000000],e;
	scanf("%d",&t);
	for(T=1;T<=t;++T)
	{
		for(i=0;i<11;++i)
		{
			for(j=0;j<11;++j)
			{
				a1[i][j]=0;
				a2[i][j]=0;
				a3[i][j]=0;
				for(k=0;k<11;++k)
					a[i][j][k]=0;
			}
		}
		scanf("%d%d%d%d",&j,&p,&s,&k);
		m=0;
		printf("Case #%d: ",T);
		int i1,i2,i3;
		for(i1=1;i1<=j;++i1)
		{
			for(i2=1;i2<=p;++i2)
			{
				for(i3=1;i3<=s;++i3)
				{
					if(a1[i1][i2]<k && a2[i2][i3]<k && a3[i3][i1]<k)
					{
						a1[i1][i2]++;
						a2[i2][i3]++;
						a3[i3][i1]++;
						a[i1][i2][i3]=1;
						m++;
					}
				}
			}
		}
		printf("%d\n",m);
		for(i1=1;i1<=j;++i1)
		{
			for(i2=1;i2<=p;++i2)
			{
				for(i3=1;i3<=s;++i3)
				{
					if(a[i1][i2][i3])
						printf("%d %d %d\n",i1,i2,i3);
				}
			}
		}
	}
	return 0;
}
