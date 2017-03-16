#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
static int dp[2000005];
int main()
{
	int T , A , B;
	cin >> T;
	for(int i = 1; i <= T; ++i)
	{
		cin >> A >> B;
		int res = 0;
		int X = A;
		set < pair < int , int > > s;
		for(; A <= B; A++)
		{
		int k = A , t = A , f, z;
		int M = 1;
		while( k )
		{
			k /= 10;
			M *= 10;
			t = A % M;
			f = A / M;
			z = 1;
			while( f )
			{
				z *= 10;
				f /= 10;
			}
			t = t * z + A / M;
			if( t > A && t <= B){
				s.insert( make_pair( A ,  t) );
				 }
		}
		}
		cout <<"Case #"<<i<<": " << s.size() << "\n";
	}
	return 0;
}
