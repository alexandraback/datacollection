#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000],f[1000],t,sum1,sum2;
void dfs(int d)
	{
		if (d>n) return;
		for (int i=0;i<3;++i)
			{
				f[d]=i;
				if (i==1) sum1+=a[d];
				if (i==2) sum2+=a[d];
				if (sum1==sum2&&sum1>0) return;
				dfs(d+1);
				if (sum1==sum2&&sum1>0) return;
				if (i==1) sum1-=a[d];
				if (i==2) sum2-=a[d];
			}
	}
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
			sum1=sum2=0;
			dfs(1);
			if (sum1==0) cout<<"Impossible"<<endl;
			else
			{
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
		}
		}
}
