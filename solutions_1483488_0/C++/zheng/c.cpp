#include <iostream>
#include <set>
using namespace std;

inline int digit(int t)
{
	int c=0;
	while(t)
	{
		++c;
		t/=10;
	}
	return c;
}

inline int power(int d)
{
	int s=1;
	--d;
	while(d--)
		s*=10;
	return s;
}

int main()
{
	set<int> s;
	int numOfCases, a, b;
	long long ans=0;
	cin>>numOfCases;
	for(int i=1; i<=numOfCases; ++i)
	{
		cin>>a>>b;
		ans=0;
		
		int d=digit(a);
		int p=power(d);

		for(int j=a; j<=b; ++j)
		{
			int t=j;
			s.clear();
			for(int k=1; k<d; ++k)
			{
				int tt=(t%10)*p+t/10;
				if(tt>j && tt<=b && s.count(tt)==0)
				{
					s.insert(tt);
					++ans;
				}
				t=tt;
			}
		}

		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}

