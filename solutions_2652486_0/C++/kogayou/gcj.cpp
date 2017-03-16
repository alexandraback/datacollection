#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;
int casenum,T;

int r,n,m,k;
int f[10];
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);

	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<":"<<endl;
		cin>>r>>n>>m>>k;
		for (int i=1;i<=r;i++)
		{
			for (int j=1;j<=k;j++)
				cin>>f[j];
			for (int a1=5;a1>=2;a1--)
				for (int a2=a1;a2>=2;a2--)
					for (int a3=a2;a3>=2;a3--)
					{
						bool flag=true;
						for (int j=1;j<=k;j++)
							if (f[j]!=1&&f[j]!=a1&&f[j]!=a2&&f[j]!=a3&&f[j]!=a1*a2&&f[j]!=a1*a3&&f[j]!=a2*a3&&f[j]!=a1*a2*a3)
							{
								flag=false;
								break;
							}
						if (flag)
						{
							cout<<a1<<a2<<a3;
							goto next;
						}
					}
			cout<<222;
			next:cout<<endl;
		}
	}
	return 0;
}
