#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<pair<int ,int > >v[105];
int a[105],b[105],y=0,c[105];
int dfs(int x)
{
	c[x]=1;
	b[y++]=x;
	int i;
	for(i=0;i<v[x].size();i++)
	{
		if(c[v[x][i].second]==0)
		{
			dfs(v[x][i].second);
		}
	}
}
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int t,n,i,j,k,l,m;
	cin>>t;
	for(l=1;l<=t;l++)
	{
		y=0;
		for(i=0;i<60;i++)
		v[i].clear();
		for(i=0;i<100;i++)
			c[i]=0;
		cout<<"Case #"<<l<<": ";
		cin>>n>>m;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<m;i++)
		{
			cin>>j>>k;
			v[j-1].push_back(make_pair(a[k-1],k-1));
			v[k-1].push_back(make_pair(a[j-1],j-1));
		}
		for(i=0;i<n;i++)
			sort(v[i].begin(),v[i].end());
		
		int min=0;
		for(i=0;i<n;i++)
		{
			if(a[i]<a[min])
				min=i;
		}
		dfs(min);
		for(i=0;i<y;i++)
		{
			cout<<a[b[i]];
		}
		cout<<endl;
	}
	return 0;
}