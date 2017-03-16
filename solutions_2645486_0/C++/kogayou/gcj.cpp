#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;
int casenum,T;

int v[11];
int f[11][6];
int e,r,n,ans;
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);

	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		cin>>e>>r>>n;
		r=min(r,e);
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
			cin>>v[i];
		ans=0;
		for (int i=1;i<=n;i++)
			for (int j=r;j<=e;j++)
				for (int k=j-r;k<=e;k++)
				{
					f[i][j]=max(f[i][j],f[i-1][k]+v[i]*(k-(j-r)));
					ans=max(ans,f[i][j]);
				}
		cout<<ans<<endl;
	}
	return 0;
}
