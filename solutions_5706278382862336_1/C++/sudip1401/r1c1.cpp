#include <iostream>
#include <sstream>
#include <string>
using namespace std;

long long gcd(long long a, long long b)
{
	while(b)
	{
		long long t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main()
{
	long long t,tc;
	cin>>tc;
	for(long long t=1;t<=tc;t++)
	{
		string s;
		cin>>s;
		stringstream ss;
		ss << s;
		long long p,q;
		char c;
		ss >> p >> c >> q;
		ss.clear();
		//cout<<p<<" "<<q<<endl;

		long long g = gcd(p,q);
		p = p/g;
		q = q/g;

		long long no = 1;
		for(long long i=1;i<q;i=i*2)
			if(q == 2*i) { no = 0; break; }

		if(no == 0)
		{
			long long gen = 0;
			while(1)
			{
				long long q1 = q/2;
				long long p1 = p - q1;
				gen++;
				if(p1 < 0)
				{
					q = q1;
				}
				else break;	
			}
			cout<<"Case #"<<t<<": "<<gen<<endl;
		}
		else
			cout<<"Case #"<<t<<": impossible"<<endl;

	}
	return 0;
}