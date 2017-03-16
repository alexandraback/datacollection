#include <iostream>
using namespace std;

int main()
{
	freopen("small2.in","r", stdin);
	freopen("output.txt","w", stdout);
	int test;
	cin >> test;
	for(int t=1;t<=test;t++)
	{
		int ans=0;
		int a,b,k;
		cin>>a>>b>>k;

		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if((i & j) < k)
				{
					ans++;
				}
			}
		}

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}