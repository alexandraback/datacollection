#include <bits/stdc++.h>

using namespace std;
int t,k,c,s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int p=1;p<=t;++p)
	{
		cin>>k>>c>>s;
		int l = (k-1)/c + 1;
		if(l>s)
		{
			cout<<"Case #"<<p<<": IMPOSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<p<<":";
			for(int i=1;i<=l;++i)
			{
				int a = (i-1)*c+1;
				long long sum = 0;
				long long t=1;
				for(int j=1;j<c;++j)
					t = t*k;
				for(int j=a;j<a+c;++j)
				{
					if(j<=k)
						sum = sum + t*(j-1); 
					t/=k;
				}
				sum++;
				cout<<" "<<sum;
			}
			cout<<endl;
		}


	}


	return 0;
}