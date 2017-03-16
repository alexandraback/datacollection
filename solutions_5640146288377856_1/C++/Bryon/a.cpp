#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>
#include <fstream>

typedef long long ll;

using namespace std;

int main()
{
	int casses;
	ll r,c,w;
	ll sum;
	
	cin >> casses;
	for( ll i = 1; i <= casses; i++ )
	{
				sum = 0;
				cin >> r >> c >> w;
				sum += c / w;
				sum *= r;
				if( c % w != 0 )
					sum++;
				sum += w - 1;
				cout << "Case #" << i << ": " << sum << endl;
	}
	return 0;
}
