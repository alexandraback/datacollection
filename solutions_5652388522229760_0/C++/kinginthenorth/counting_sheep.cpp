#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		int n;
		cin>>n;
		if(!n)
			cout<<"Case #"<<cno<<": INSOMNIA"<<endl;
		else
		{
			int a[10]={0},sum=0;
			int ans,m=0,m1,d;
			while(sum<45||a[0]==0)
			{
				m+=n;
				m1=m;
				while(m1)
				{
					d=m1%10;
					if(!a[d])
					{
						a[d]++;
						sum+=d;
					}
					m1/=10;
				}
				ans=m;
			}
			cout<<"Case #"<<cno<<": "<<ans<<endl;
		}
	}
	return 0;
}
