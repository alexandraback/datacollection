#include<iostream>
#define N 101
#define M 101
using namespace std;
int a[N][M],m,n;
int row(int,int);
int col(int,int);
int main()
{	int i=1,t,j,k,valid;
	cin>>t;
	while(i<=t)
	{	cin>>n>>m;
		for(j=0;j<n;j++)
			for(k=0;k<m;k++)
				cin>>a[j][k];
		valid=1;
		for(j=0;j<n;j++)
		{	for(k=0;k<m;k++)
			{	if(!row(j,k) && !col(j,k))
				{	valid=0;
					break;
				}
			}
			if(!valid)
				break;
		}
		cout<<"Case #"<<i<<": "<<(valid?"YES":"NO")<<endl;
		i++;
	}
	return 0;
}
int row(int p,int q)
{	int i;
	// Left
	for(i=q-1;i>=0;i--)
	{	if(a[p][i]>a[p][q])
			return 0;
	}
	// Right
	for(i=q+1;i<m;i++)
	{	if(a[p][i]>a[p][q])
			return 0;
	}
	return 1;
}
int col(int p,int q)
{	int i;
	// Top
	for(i=p-1;i>=0;i--)
	{	if(a[i][q]>a[p][q])
			return 0;	
	}
	// Bottom
	for(i=p+1;i<n;i++)
	{	if(a[i][q]>a[p][q])
			return 0;
	}
	return 1;
}