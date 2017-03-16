#include<iostream>
#include<algorithm>
#include<memory.h>
#include<stack>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int nc;
	cin>>nc;
	int lawn[100][100];
	bool cut[100][100];
	int n,m,cutcount,maxh;
	for(int tc=1;tc<=nc;tc++)
	{
		cin>>n>>m;
		memset(cut,0,sizeof(cut));
		cutcount=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>lawn[i][j];
		for(int i=0;i<n;i++)
		{
			maxh=0;
			for(int j=0;j<m;j++)
				if(lawn[i][j]>maxh)
					maxh=lawn[i][j];
			for(int j=0;j<m;j++)
				if(lawn[i][j]==maxh)
				{
					cut[i][j]=1;
					cutcount++;
				}
		}
		for(int j=0;j<m;j++)
		{
			maxh=0;
			for(int i=0;i<n;i++)
				if(lawn[i][j]>maxh)
					maxh=lawn[i][j];
			for(int i=0;i<n;i++)
				if(lawn[i][j]==maxh)
				{
					if(cut[i][j]==0)
						cutcount++;
					cut[i][j]=1;
				}
		}
		cout<<"Case #"<<tc<<": ";
		if(cutcount==n*m)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
    return 0;
}                                 