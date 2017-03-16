#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,a[2000][2];
bool f[2000][2];
int main()
{
	//freopen("rush.in","r",stdin);
	//freopen("rush.out","w",stdout);
	int t;
	cin>>t;
	for (int tt=1;tt<=t;++tt)
		{
			cin>>n;
			for (int i=1;i<=n;++i)
				cin>>a[i][0]>>a[i][1];
			bool flag=0;
			int cpl=0,star=0,ans=0;
			memset(f,0,sizeof(f));
			while (cpl<n&&!flag)
				{
					int i=1;
					bool findstar=0;
					while (i<=n&&!findstar){
						if (star>=a[i][1]&&(!f[i][1])&&(!f[i][0]))
							{findstar=1;star+=2;f[i][1]=f[i][0]=1;++cpl;}
						++i;}
					i=1;
					if (!findstar)
						while (i<=n&&!findstar){
						if (star>=a[i][1]&&(!f[i][1])&&f[i][0])
							{findstar=1;++star;f[i][1]=1;++cpl;}
						++i;}
					i=1;
					/*if (!findstar)
						while (i<=n&&!findstar)
							if (star>=a[i][0]&&!f[i][0])
								{++star;f[i][0]=1;findstar=1;}
							else ++i;*/
					int po;
					if (!findstar)
						{
						for (i=1;i<=n;++i)
							if ((!f[i][0])&&a[i][0]<=star) {if (!findstar) {findstar=1;po=i;}else if (a[i][1]>a[po][1]) po=i;}
						if (findstar) {f[po][0]=1;++star;}
						}
					if (!findstar) flag=1;
					++ans;
				}
			cout<<"Case #"<<tt<<": ";
			if (cpl<n) cout<<"Too Bad"<<endl;
			else cout<<ans<<endl;
		}
}

