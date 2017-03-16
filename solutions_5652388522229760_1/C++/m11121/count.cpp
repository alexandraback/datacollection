#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int ic=1;
	while(t--)
	{
		long long n;
		cin>>n;
		cout<<"Case #"<<ic++<<": ";
		char mp[10]{};
		int i,num=10;
		long long u,t;
		for( i=1;num&&i<1000000;++i)
		{
			t= u = i*n;
			while(u)
			{
				if(mp[u%10]==0)
				{
					mp[u%10]=1;
					--num;
				}
				u/=10;
			}

		}
		if(num==0) cout<<t<<endl;
		else cout<<"INSOMNIA"<<endl;
	}
	return 0;
}
