#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int len( int n )
{
	int ans = 0 ;
	if( n == 0 )
		return 1;
	while(n>0)
	{
		n/=10;
		ans++;
	}
	return ans ;
}

string str( int n )
{
	string res = "";
	if(n==0) return "0";
	while(n)
	{
		res += (char)( n%10 + 48 );
		n /= 10 ;
	}
	reverse( res.begin(), res.end() );
	return res;
}

int  INT( string &st )
{
	cout << "\n\n\tINT(" << st << ") = ";
	int res = 0 ;
	for( auto &x: st )
		res = res*10 + x-48 ;
	cout << res << "\n" ;
	return res ;
}

int main()
{
	freopen( "in", "r", stdin );
	freopen( "out", "w", stdout );

	int tt;
	cin >> tt ;
	for( int t=1; t<=tt; t++ )
	{
		string  A, B, a, b, mnA, mnB ;
		cin >> A >> B ;

		int  i, j ;
		bool  found1 = 0,  found2 = 0, flag1=0, flag2=0 ;

		for(auto &x: A)
			if( x == '?' )
			{ found1=1; break; }

		for(auto &x: B)
			if( x == '?' )
			{ found2=1; break; }

		if( !found1 && !found2 )
		{
			cout << "Case #" << t << ": " << A << ' ' << B << endl ;
			continue;
		}

		int mn = pow( 10, A.size() );

		if( ! found1 )
		{
			i = INT(A);
			for( j=pow(10,B.size())-1; j>=0; j-- )
			{
				a = A ;
				b = string(B.size() - len(j), '0') + str(j) ;
				flag1=1;
				flag2=1;
				for( int L=0; L<B.size(); L++ )
					if( B[L] != '?' )
						if( B[L] != b[L] )
						{  flag2=0; break; }
				if(flag1&&flag2)
				if( mn >= abs(i-j))
				{
					mn = abs(i-j) ;
					mnA = a ;
					mnB = b ;
				}
			}
			cout << "Case #" << t << ": " << mnA << ' '<< mnB << endl ;
			continue;
		}

		if( ! found2 )
		{
			j = INT(B);
			for( i=pow(10,A.size())-1; i>=0; i-- )
			{
				a = string(A.size() - len(i), '0') + str(i) ;
				b = B ;
				flag1=1;
				flag2=1;
				for( int L=0; L<A.size(); L++ )
					if( A[L] != '?' )
						if( A[L] != a[L] )
						{  flag1=0; break; }
				if(flag1&&flag2)
				if( mn >= abs(i-j))
				{
					mn = abs(i-j) ;
					mnA = a ;
					mnB = b ;
				}
			}
			cout << "Case #" << t << ": " << mnA << ' '<< mnB << endl ;
			continue;
		}

                for( i=0; i<pow(10,A.size()); i++ )
                {
			for( j=max(0,i-mn); j<min( (int)pow(10,B.size()), i+mn ); j++ )
			{
				a = string(A.size() - len(i), '0') + str(i) ;
				b = string(B.size() - len(j), '0') + str(j) ;

				flag1 = 1 ;
				for( int L=0; L<A.size(); L++ )
					if( A[L] != '?' )
						if( A[L] != a[L] )
						{  flag1=0; break; }
				flag2 = 1 ;
				for( int L=0; L<B.size(); L++ )
					if( B[L] != '?' )
						if( B[L] != b[L] )
						{  flag2=0; break; }

				if(flag1&&flag2)
				if( mn > abs(i-j))
				{
					mn = abs(i-j) ;
					mnA = a ;
					mnB = b ;
				}
			}
		}
		cout << "Case #" << t << ": " << mnA << ' '<< mnB << endl ;

	}

	return 0;
}
