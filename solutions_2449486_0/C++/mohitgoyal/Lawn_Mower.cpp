#include<cstdio>
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int t,n,m,j,k,l;
	int a[101][101];
	int b[101][101];
	int r[101][101];
	int c[101][101];
	int rr[101];
	int cc[101];
	scanf("%d",&t);
	int i=0;
	while(i<t)
	{
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		scanf("%d %d",&n,&m);
		j=0;
		while(j<n)
		{
			rr[j]=0;
			k=0;
			while(k<m)
			{
				b[j][k]=100;
				cc[k]=0;
				scanf("%d",&a[j][k]);
				r[j][a[j][k]]++;
				c[k][a[j][k]]++;
				k++;
			}
			j++;
		}
		j=100;
		while(j>0)
		{
			k=0;
			while(k<n)
			{
				if((r[k][j]==0)&&(rr[k]==0))
				{
					l=0;
					while(l<m)
					{
						b[k][l]=j-1;
						l++;
					}
				}
				else
					rr[k]=1;
				k++;
			}
			k=0;
			while(k<m)
			{
				if((c[k][j]==0)&&(cc[k]==0))
				{
					l=0;
					while(l<n)
					{
						b[l][k]=j-1;
						l++;
					}
				}
				else
					cc[k]=1;
				k++;
			}
			j--;
		}
		/*j=0;
		while(j<n)
		{
			k=0;
			while(k<m)
				cout<<b[j][k++]<<" ";
			cout<<endl;
			j++;
		}*/
		int ff=0;
		j=0;
		while(j<n)
		{
			k=0;
			while(k<m)
			{
				//cout<<b[j][k]<<" ";
				if(b[j][k]!=a[j][k])
				{
						ff=1;
						break;
				}
				k++;
			}
			//cout<<endl;
			if(ff==1)
				break;
			j++;
		}
		if(ff!=1)
		printf("Case #%d: YES\n",i+1);
		else
			printf("Case #%d: NO\n",i+1);
		i++;
	}
	return 0;
}