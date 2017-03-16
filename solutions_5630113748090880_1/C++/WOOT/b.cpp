#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

int T=0;
int num=0;

void Gao()
{
	map<int ,int > mp;
	printf("Case #%d: ",++num);
	int n;
	int maxx=0;
	cin>>n;
		for (int i=0;i<2*n-1;i++)
		{
			for (int j=0;j<n;j++)
			{
				int x;
				cin>>x;
				if (x>maxx)
					maxx=x;
				if (mp.find(x)==mp.end())
				{
					mp[x]=1;
				 } 
				 else
				{
					mp[x]=mp[x]+1;
				}
			}
		}

	int tt=0;
	for (int i=0;i<=maxx;i++)
	{
		if (mp.find(i)!=mp.end())
		{
			if (mp[i]%2==1)
			{
				if (tt)
					cout<<" ";
				cout<<i;
				tt++; 
			}
		}
		if (tt==n)
			break;
	}
	cout<<endl;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	cin>>T;
	while (T--)
		Gao();
} 
