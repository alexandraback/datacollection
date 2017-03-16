#include <iostream>
using namespace std;

int sh[31], nsh[31];

void init()
{
	for(int i=0; i<=10; ++i)
		for(int j=i; j<=i+2&&j<=10; ++j)
			for(int k=j; k<=i+2&&k<=10; ++k)
			{
				int s=i+j+k;
				if(j-i<=1&&k-i<=1)
				{
					nsh[s]=nsh[s]>k?nsh[s]:k;
				}
				else
				{
					sh[s]=sh[s]>k?sh[s]:k;
				}
			}
}

int main()
{
	init();
	int numOfCases, n, s, p, can, t, ans;
	cin>>numOfCases;
	for(int i=1; i<=numOfCases; ++i)
	{
		ans=can=0;
		cout<<"Case #"<<i<<": ";
		cin>>n>>s>>p;
		for(int j=1; j<=n; ++j)
		{
			cin>>t;
			if(nsh[t]>=p)
				++ans;
			else if(sh[t]>=p)
				++can;
		}
		if(can>s)
			can=s;
		cout<<ans+can<<endl;
	}
	return 0;
}

