#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,f[1000],t,sum1,sum2;
long long a[1000];
int main()
{
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	cin>>t;
	for (int tt=1;tt<=t;++tt)
		{
			cout<<"Case #"<<tt<<": "<<endl;
			cin>>n;
			for (int i=1;i<=n;++i)
				cin>>a[i];
			bool flag=0;
			for (int t1=1;t1<=1000;++t1)
				{
					sum1=sum2=0;
					for (int i=1;i<=n;++i)
						{
						 f[i]=rand()%3;
						 if (f[i]==1) sum1+=a[i];
						 if (f[i]==2) sum2+=a[i];
						}
					if (sum1==sum2&&sum1!=0) break;
					for (int t2=1;t2<=50000;++t2)
						{
							int r=rand()%n+1;
							if (f[r]==0) {int p=rand()%2;f[r]=p+1;if (p==0) sum1+=a[r];else sum2+=a[r];}
						 else if (f[r]==1) {sum1-=a[r];f[r]=0;}
						 else {sum2-=a[r];f[r]=0;}
						 if (sum1==sum2&&sum1!=0) break;
						}
					if (sum1==sum2&&sum1!=0)
					{
						flag=1;
						int p=1,sum=0;
						while (f[p]!=1) ++p;
						sum=a[p];
						cout<<a[p];
						while (sum<sum1)
							{
								++p;
								if (f[p]==1){
								sum+=a[p];
								cout<<" "<<a[p];}
							}
						cout<<endl;
						p=1;sum=0;
						while (f[p]!=2) ++p;
						sum=a[p];
						cout<<a[p];
						while (sum<sum2)
							{
								++p;
								if (f[p]==2){
								sum+=a[p];
								cout<<" "<<a[p];}
							}
						cout<<endl;
						break;
					}
				if (flag) break;
				}
			if (!flag) cout<<"Impossible"<<endl;
		}
}
