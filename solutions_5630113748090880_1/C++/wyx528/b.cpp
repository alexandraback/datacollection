#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int a[2501];

void work()
{
	int n;
	cin>>n;
	for (int i=1;i<=2500;i++) a[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=2*n-1;j++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
	for (int i=1;i<=2500;i++)
		if (a[i]%2==1) cout<<' '<<i;
	cout<<endl;
}

int main()
{
	freopen ("big.in","r",stdin);
	freopen ("big.out","w",stdout);
	int T;
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<":";
		work();
	}
	return 0;
}