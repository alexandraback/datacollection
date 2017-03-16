#include <iostream>
#include <vector>
using namespace std;
int val[1003];
int cnt=0;
vector <int> map[1003];

int isLoop(int node)
{
	int k;
	int que[1003];
	int mark[1003];
	for(k=0;k<cnt;k++)
		mark[k]=0;
	int s=0,t=0;
	que[t++]=node;
	while(s<t)
	{
		int now = que[s];
		s++;
		for(k=0;k<map[now].size();k++)
		{
			que[t++]=map[now][k];
			if(mark[map[now][k]]==100)
				return 1;
			mark[map[now][k]]=100;
		}
	}
	return 0;
}

int main()
{
	int n;
	int i,j,k,mid;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<cnt;j++)
			map[j+1].clear();
		cin>>cnt;
		for(j=0;j<cnt;j++)
		{
			cin>>k;
			for(;k>0;k--)
			{
				cin >>mid;
				map[j+1].push_back(mid);
			}
		}
		cout<<"Case #"<<i<<": ";
		for(j=0;j<cnt;j++)
		{
			if(isLoop(j+1)==1)
			{
				cout<<"Yes"<<endl;
				break;
			}
		}
		if(j==cnt)
		{
			cout<<"No"<<endl;
		}
	}
	return 1;
}