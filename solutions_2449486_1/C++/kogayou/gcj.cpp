#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int casenum,T;
int n,m;
int a[110][110];
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		cin>>n>>m;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				cin>>a[i][j];
		bool flag=true;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
			{
				if (!flag) break;
				bool flag1=true;
				bool flag2=true;
				for (int k=0;k<n;k++)
					if (a[i][j]<a[k][j])
					{
						flag1=false;
						break;
					}
				for (int k=0;k<m;k++)
					if (a[i][j]<a[i][k])
					{
						flag2=false;
						break;
					}
				if (!flag1&&!flag2) flag=false;
			}
		if (flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
