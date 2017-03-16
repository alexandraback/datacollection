#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main(int argc, char const *argv[])
{
	ull T;
	cin >> T;	

	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t+1 << ": "; 

		string fraction;
		int P,Q;

		cin >> fraction;

		auto pos = fraction.find('/');
		P = atoll(fraction.substr(0,pos).c_str());
		Q = atoll(fraction.substr(pos+1).c_str());

		int divisor = gcd(P,Q);
		Q /= divisor;
		P /= divisor;

		if( (Q-1)&Q ) {
			cout << "impossible" << endl;
			continue;
		}

		bool possible = true;
		int i=0;
		while(P<Q){
			Q/=2;
			i++;
		}

		cout << i << endl;
	}

	return 0;
}