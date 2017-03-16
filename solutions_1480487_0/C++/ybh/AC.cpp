#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXN 210

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		int n,sum=0,a[MAXN];
		bool b[MAXN];
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			b[i]=false;
		}
		double sum0=sum;
		sum*=2;
		double x=double(sum)/double(n);
		int m=n;
		
		bool flag=true;
		while (flag)
		{
			flag=false;
			for (int i=1;i<=n;i++)
			{
				if (b[i]==false && a[i]>=x)
				{
					b[i]=true;
					sum-=a[i];
					m--;
					flag=true;
				}
			}
			x=double(sum)/double(m);
		}
		
		cout<<"Case #"<<T<<": ";
		for (int i=1;i<=n;i++)
		{
			if (b[i]) cout<<"0.000000"<<' ';
			else
			{
				double ans=(x-a[i])/sum0*100;
				cout<<setiosflags(ios::fixed)<<setprecision(6)<<ans<<' ';
			}
		}
		cout<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
