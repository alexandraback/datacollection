#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long LINT;

int tbl[1000][1000];

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int n,m;
		cin>>n;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				tbl[i][j]=0;

		for(int i=0; i<n; i++)
		{
			cin>>m;
			for(int j=0; j<m; j++)
			{
				int a;
				cin>>a;
				tbl[i][a-1]=1;
			}
		}

		bool cyc=false;
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if(tbl[i][k]==1 && tbl[k][j]==1)
					{
						if(tbl[i][j]==1)
							cyc=true;
						tbl[i][j]=1;
					}
				
		cout<<"Case #"<<ii+1<<": "<<(cyc ? "Yes" : "No")<<endl;
	}
}