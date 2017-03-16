// gj.cpp
//

#include <assert.h>

#include <fstream>
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

uint64 a, b,
	   p[100];

uint64 flip(uint64 v)
{
	uint64 rs = 0;
	while (v)
	{
		uint64 t = v % 10;
		v /= 10;
		rs *= 10;
		rs += t;
	}

	return rs;
}

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	uint64 np = 0;
	for (uint64 q = 1, s = 1; s <= 100000000000000U; ++q, s = q * q)
	{
		if (q == flip(q) && s == flip(s))
			p[np++] = s;
	}

	for (uint64 i = 1; i <= cases; ++i)
	{
		cin >> a >> b;

		uint64* lp = lower_bound(p, p + np, a),
			  * rp = lower_bound(p, p + np, b);

		uint64 r = rp - lp;
		if (*rp == b)
			++r;

		cout << "Case #" << i << ": " << r << endl;
	}

	return 0;
}
