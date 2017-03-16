#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool f[1001][1001];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	cin>>t;
	for (int tt=1;tt<=t;++tt)
		{
			cout<<"Case #"<<tt<<": ";
			int n;
			cin>>n;
			int x,y;
			memset(f,0,sizeof(f));
			for (int i=1;i<=n;++i)
				{
					int k;
					cin>>k;
					for (int j=1;j<=k;++j)
						{
							cin>>y;
							f[i][y]=1;
						}
				}
			bool flag=0;
			for (int i=1;i<=n&&!flag;++i)
				for (int j=1;j<=n&&!flag;++j)
					if (j!=i)
					for (int k=1;k<=n;++k)
						if (k!=j&&k!=i)
							if (f[j][i]&&f[i][k])
								if (f[j][k]) {cout<<"Yes"<<endl;flag=1;break;}
								else f[j][k]=1;
			if (!flag) cout<<"No"<<endl;
		}
	return 0;
}
