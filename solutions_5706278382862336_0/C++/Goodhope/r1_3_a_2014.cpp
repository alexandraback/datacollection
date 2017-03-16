// gj.cpp
//

#include <assert.h>

#include <fstream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;

#define EPS (1E-10)
#define PI 3.1415926535897932384626433832795

uint64 gcd(uint64 a, uint64 b)
{
	if (a == 0)
		return b;

	return gcd(b % a, a);
}

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 cs = 1; cs <= cases; ++cs)
	{
		uint64 p, q;
		char c;
		cin >> p >> c >> q;

		uint64 g = gcd(p, q);
		p /= g;
		q /= g;

		if ((q & (q - 1))) // no power 2
			cout << "Case #" << cs << ": impossible\n";
		else
		{
			uint c = 0;
			while (p < q)
			{
				q >>= 1;
				++c;
			}
			cout << "Case #" << cs << ": " << c << "\n";
		}

	}

	return 0;
}
