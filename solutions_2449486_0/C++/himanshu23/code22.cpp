#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
//freopen("b.in","r",stdin);
//	freopen("outputb.in","w",stdout);
	int t;
	cin>>t;
	int q=0;
	while(t--)
	{
		q++;
		int r,c;
		cin>>r>>c;
		int a[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>a[i][j];
			}
		}
		int flag=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(a[i][j]==1)
				{
					int c1=0;
					for(int k=0;k<c;k++)
					{
						if(a[i][k]==1)
						c1++;
					}
					int c2=0;
					for(int k=0;k<r;k++)
					{
						if(a[k][j]==1)
						c2++;
					}
					if(c1==c||c2==r)
					continue;
					else
					{
					flag=1;
					break;	
					}
				}
			}
			if(flag==1)
			break;
		}
		if(flag==1)
		cout<<"Case #"<<q<<": NO"<<endl;
		else
		cout<<"Case #"<<q<<": YES"<<endl;
	
	}
}
