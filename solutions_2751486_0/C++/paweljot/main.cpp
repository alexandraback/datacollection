/* Problem A */
#include<iostream>
#include<string>

using namespace std;

typedef unsigned long long ull;

ull countN( string s, ull n )
{
	for( ull i = 0; i<n; i++ )
	{
		if( 
			s[i] == 'a' ||
			s[i] == 'e' ||
			s[i] == 'i' ||
			s[i] == 'o' ||
			s[i] == 'u')
			return 0;
	}

	return 1;
}

ull nvalue( string sub, ull n )
{
	if( sub.size() < n ) return 0;
	ull val = 0;
	for( int i =0; i <= sub.size() - n; i++ )
	{
		//cout << sub.substr(i, n) << endl;
		val += countN( sub.substr(i,n), n );

	}
	return (val > 0 ) ? 1 : 0;
}

unsigned long long testcase( const string &s, ull n )
{
	//cout << "s: " << s << endl;
	ull ret = 0;
	for( ull i=0; i< s.size(); i++ )
	{
		int npos = s.size() - i;
		while(npos--)
		{
			//cout << s.substr(i,npos+1);
			ret+=nvalue(s.substr(i,npos+1), n );
			//cout << " " << ret << endl;
		}
	}
	return ret;
}

int main()
{
	int T;
	scanf_s("%d",&T);

	for(int i=1; i<=T;i++)
	{
		string s;
		ull n;
		cin >> s;
		cin >> n;

		printf("Case #%d: %llu\n",i,testcase(s,n));
	}

	return 0;
}