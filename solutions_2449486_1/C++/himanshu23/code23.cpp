#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
//	freopen("BB1.in","r",stdin);
//	freopen("outputb1.in","w",stdout);
	int t;
	cin>>t;
	int q=0;
	while(t--)
	{
		q++;
		int r,c;
		cin>>r>>c;
		int a[r][c];
		int mr[r];
		int mc[c];
		for(int i=0;i<r;i++)
		{
			mr[i]=0;
			for(int j=0;j<c;j++)
			{
			cin>>a[i][j];
			mr[i]=max(mr[i],a[i][j]);
			}
		}
		
		for(int j=0;j<c;j++)
		{
			mc[j]=0;
			for(int i=0;i<r;i++)
			{
			
			mc[j]=max(mc[j],a[i][j]);
			}
		}
		int flag=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(a[i][j]==mr[i]||a[i][j]==mc[j])
				continue;
				else
				{
					flag=1;
					break;
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
		
