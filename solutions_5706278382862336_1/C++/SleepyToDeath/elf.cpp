#include<iostream>
#include<sstream>
using namespace std;


long long gcd(long long a , long long b)
{
	if (a<b) return gcd(b,a);
	if (b==0) return a;
	return gcd(b,a%b);
}

bool check( long long a )
{
	while (a%2==0)
		a=a/2;
	return a==1;
}

void work( int t )
{
	string s;
	getline(cin,s);
	long long a,b;
	size_t pos0 = s.find('/');
	stringstream sio;
	sio<<s.substr( 0 , pos0 );
	sio>>a;
	sio.clear();
	sio<<s.substr( pos0+1 , s.length() - pos0-1 );
	sio>>b;
	long long c=gcd(a,b);
	a=a/c;
	b=b/c;
	if (!check(b))
		cout<<"Case #"<<t<<": impossible\n";
	else
	{
		long long c1=0,c2=0;
		while (a>1)
		{
			a/=2;
			c1++;
		}
		while (b>1)
		{
			b/=2;
			c2++;
		}
		cout<<"Case #"<<t<<": "<<c2-c1<<endl;
	}

}

int main()
{
	int t;
	cin>>t;
	string s;
	getline(cin,s);
	for (int i=1;i<=t;i++)
		work( i );
}

