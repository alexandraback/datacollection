#include <iostream>
#include <vector>
using namespace std;
int count=0;
vector <int> data[1003];
int search(int node)
{
	int k;
	int que[1003];
	int use[1003];
	for(k=0;k<count;k++)
		use[k]=0;
	int s=0,t=0;
	que[t++]=node;
	while(s<t)
	{
		int now = que[s];
		s++;
		for(k=0;k<data[now].size();k++)
		{
			que[t++]=data[now][k];
			if(use[data[now][k]]==100)
				return 1;
			use[data[now][k]]=100;
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
		for(j=0;j<count;j++)
			data[j+1].clear();
		cin>>count;
		for(j=0;j<count;j++)
		{
			cin>>k;
			for(;k>0;k--)
			{
				cin >>mid;
				data[j+1].push_back(mid);
			}
		}
		cout<<"Case #"<<i<<": ";
		for(j=0;j<count;j++)
		{
			if(search(j+1)==1)
			{
				cout<<"Yes"<<endl;
				break;
			}
		}
		if(j==count)
		{
			cout<<"No"<<endl;
		}
	}
	return 1;
}