#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int check(int i,int j,int k)
{
	int an=2*i+2*j-4;
	int a=1;
	int p=i*j-k;
	while (p>a*4)
	{
		an-=4;
		p-=a*4;
		a++;
	}
	an-=p/a;
	return an;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	for (int ii=0;ii<t;ii++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		if (m>n)
		{
			int t=n;
			n=m;
			m=t;
		}
		int ans=k;
		for (int i=2;i<=m;i++)
			for (int j=i;j<=n;j++)
			{
				if (i*j<k)
					continue;
				if ((j-i+1)*i>k)
					continue;
				ans=min(ans,check(i,j,k));
			}
		cout<<"Case #"<<ii+1<<": ";
		cout<<ans<<endl;
	}
}