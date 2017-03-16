#include <iostream>
using namespace std;

int a[1001], b[1001], level[1001], n, t, ans;

int main()
{
	cin>>t;
	for(int i=1; i<=t; ++i)
	{
		cin>>n;
		for(int j=1; j<=n; ++j) {cin>>a[j]>>b[j]; level[j]=0;}
		ans=0; int c=0;
		while(true)
		{
			bool can=false, can1=false;
			int max=0;
			for(int j=1; j<=n; ++j)
			{
				if(level[j]==0&&b[j]<=c)
				{
					level[j]=2;
					c+=2;
					can1=true;
					++ans;
				}
				else if(level[j]==1&&b[j]<=c)
				{
					level[j]=2;
					c+=1;
					can1=true;
					++ans;
				}
			}
			if(can1) continue;
			for(int j=1; j<=n; ++j)
			{
				if(level[j]==0&&a[j]<=c)
					if(max==0||b[max]<b[j])
						max=j;
			}
			if(max)
			{
				level[max]=1;
				c+=1;
				can=true;
				++ans;
			}
			if(!can) break;
		}
		cout<<"Case #"<<i<<": ";
		for(int j=1; j<=n; ++j)
		{
			if(level[j]!=2)
			{
				cout<<"Too Bad"<<endl;
				goto Done;
			}
		}
		cout<<ans<<endl;
Done:;
	}
	return 0;
}

