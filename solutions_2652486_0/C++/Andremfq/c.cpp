#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int t;
int r,n,m,k;
int v[70][10];
int cont[70];
int cnt=0;

int main()
{
	scanf("%d",&t);
	scanf("%d %d %d %d",&r,&n,&m,&k);
	printf("Case #1:\n");
	for(int a1=2;a1<=5;a1++)
	{
		for(int a2=2;a2<=5;a2++)
		{
			for(int a3=2;a3<=5;a3++)
			{
				cnt++;
				v[cnt][0]=1;
				v[cnt][1]=a1;
				v[cnt][2]=a2;
				v[cnt][3]=a3;
				v[cnt][4]=a1*a2;
				v[cnt][5]=a1*a3;
				v[cnt][6]=a2*a3;
				v[cnt][7]=a1*a2*a3;
				v[cnt][8]=a1*100+a2*10+a3;
				//cnt++;
			}
		}
	}
	for(int w=1;w<=r;w++)
	{
		for(int i=1;i<=cnt;i++) cont[i]=0;
		for(int ha=1;ha<=k;ha++)
		{
			int aux;
			scanf("%d",&aux);
			for(int i=1;i<=cnt;i++)
			{
				int opa=0;
				for(int j=0;j<8;j++)
				{
					if(v[i][j]==aux) opa=1;
				}
				cont[i]+=opa;
			}	
		}
		int maior=-1;
		int ll=1;
		for(int i=1;i<=cnt;i++)
		{
			if(cont[i]>maior)
			{
				maior=cont[i];
				ll=i;
			}
		}	
		printf("%d\n",v[ll][8]);
	}
	return 0;
}
