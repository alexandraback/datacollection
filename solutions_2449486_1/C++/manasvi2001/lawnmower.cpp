#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > v;
int hor(int n,int m)
{
	int i,len=v[0].size();
	for(i=0;i<len;i++)
	{
		if(v[n][i]>v[n][m])
			return 0;
	}
	return 1;
}
int ver(int n,int m)
{
	int i,len=v.size();
	for(i=0;i<len;i++)
	{
		if(v[i][m]>v[n][m])
			return 0;
	}
	return 1;
}
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		v.clear();
		int n,m,i,j;
		cin>>n>>m;
		v.resize(n);
		for(i=0;i<n;i++)
		{
			v[i].resize(m);
			for(j=0;j<m;j++)
			{
				cin>>v[i][j];
			}
		}
		int flag=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(!(hor(i,j)||ver(i,j)))
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			cout<<"Case #"<<u-t<<": YES\n";
		else
			cout<<"Case #"<<u-t<<": NO\n";
	}
	return 0;
}