#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int arr[110][110];
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		int res[110][110];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				res[i][j]=100;
		for(int i=0;i<n;i++)
		{
			int mx=0;
			for(int j=0;j<m;j++)
				mx=max(arr[i][j],mx);
			for(int j=0;j<m;j++)
				res[i][j]=min(mx,res[i][j]);
		}
		for(int j=0;j<m;j++)
		{
			int mx=0;
			for(int i=0;i<n;i++)
				mx=max(arr[i][j],mx);
			for(int i=0;i<n;i++)
				res[i][j]=min(mx,res[i][j]);
		}
		bool flag=true;
		for(int i=0;i<n&&flag;i++)
			for(int j=0;j<m;j++)
				if(arr[i][j]!=res[i][j])
				{
					flag=false;
					break;
				}
		cout<<"Case #"<<t<<": ";
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
