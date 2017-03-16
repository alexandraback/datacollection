//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef unsigned long long ull;

ull gcd( ull a, ull b)
{
	if( a < b ) return gcd(b,a);

	while( b )
	{
		ull tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

void GetInterPrime( ull& P, ull& Q)
{

	while(1)
	{
		ull d = gcd( P, Q);

		if( d == 1 ) break;

		P /= d;
		Q /= d;
	}
}

void solve()
{
	unsigned long long P,Q;
	char c;

	cin >> P >> c >> Q;

	GetInterPrime( P, Q );

	if( (Q & Q-1) != 0 ) cout << "impossible" << endl;
	else
	{
		int generation = 0;
		int i = 1;
		for(; i <= 40; ++i)
		{
			P *= 2;
			generation++;
			if( P >= Q ) break;
		}

		if( i > 40 ) cout << "impossible" << endl;
		else 
		{
			if( P != Q )
			{
				ull x = P - Q;
				ull w = Q;

				GetInterPrime( x, w );

				ull v = (ull)(1) << (40 - generation);
				if( w > v ) 
				{
					cout << "impossible" << endl;
					return;
				}
			}

			cout << generation << endl;
		}
	}
}

int main(int argc, char* argv[])
{	
	FILE* fp;
	freopen_s(&fp, "A-large.in", "r", stdin );
	freopen_s(&fp, "A-large.out", "w", stdout );

	int n;

	cin >> n;
	
	for(int caseN = 1; caseN <= n; ++caseN)
	{
		printf_s("Case #%d: ", caseN);

		solve();
	}
}
