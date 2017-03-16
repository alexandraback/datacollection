#include<iostream>
#include<cstdio>
using namespace std;
long double P[100005] , dp[100005];
int main()
{
	int T, X = 1;
	int A , B;
	cin >> T;
	while( T-- )
	{
		cin >> A >> B;
		long double cum = 1;
		for(int i = 0; i < A; ++i)
		{
			cin >> P[i];
			cum *= P[i];
			dp[i] = cum;
		}
		long double res = B + 2 , p , q;
		for(int i = 0; i < A; ++i)
		{
			p = dp[i];
			q = 1 - p;
			int use = i + 1;
			res = min( res , (A - use + B - use + 1) * p + ( A - use + B - use + 1 + B + 1 ) * q ); 
			
		}
		printf( "Case  #%d: %.7lf\n", X++ , res );
	}
	return 0;
}
