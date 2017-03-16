#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef int LL;

LL arr[103][103],R[103][103],C[103][103];
int main()
{
	LL t,cas=0,n,m,i,j,k,flag;
	freopen("bin.txt","r",stdin);
	freopen("bout.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++){scanf("%d",&arr[i][j]);}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				R[i][j]=arr[i][j];
				for(k=0;k<m;k++)
				{
					if(arr[i][k]>R[i][j])
					{
						R[i][j]=arr[i][k];
					}
				}
			}
		}
		for(j=0;j<m;j++)
		{
			for(i=0;i<n;i++)
			{
				C[i][j]=arr[i][j];
				for(k=0;k<n;k++)
				{
					if(arr[k][j]>C[i][j])
					{
						C[i][j]=arr[k][j];
					}
				}
			}
		}
		flag=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(R[i][j]==arr[i][j]||C[i][j]==arr[i][j]){continue;}
				flag=0;
				break;
			}
			if(flag==0){break;}
		}
		if(flag==1){printf("Case #%d: YES\n",++cas);}
		else{printf("Case #%d: NO\n",++cas);}
	}
	return 0;
}