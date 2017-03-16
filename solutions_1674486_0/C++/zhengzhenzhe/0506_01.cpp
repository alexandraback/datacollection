
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

int T,n,m,nodenum;

int matrix[1010][1010];
int num[1010];
void DFS(int now)
{
	for(int i=1;i<=n;i++)	
		if(matrix[now][i]!=0)
		{
			num[i]++;
			DFS(i);
		}
}
int main()
{
	freopen("in.in","r",stdin);
	freopen("out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(matrix,0,sizeof(matrix));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>m;
			for(int j=1;j<=m;j++)
			{
				cin>>nodenum;
				matrix[i][nodenum]=1;
			}
		}
		bool isok=false;
		for(int i=1;i<=n;i++)
		{
			memset(num,0,sizeof(num));
			DFS(i);
		//	cout<<num[3]<<endll;
			for(int j=1;j<=n;j++)
				if(num[j]>=2)
				{
					isok=true;
					break;
				}
			if(isok)
				break;
		}
		cout<<"Case #"<<t<<": ";
		if(isok)
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
	}
	return 0;
}
