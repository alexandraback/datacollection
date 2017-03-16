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

uint64 ni[100];

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		uint64 a, n;
		cin >> a >> n;

		uint64 mn = n;

		for (uint64 j = 0; j < n; ++j)
			cin >> ni[j];

		if (a > 1)
		{
			sort(ni, ni + n);

			uint64 oa = 0,
				   od = n;

			for (uint64 j = 0; j < n; ++j)
			{
				if (mn > oa + od)
					mn = oa + od;

				while (a <= ni[j])
				{
					a += a - 1;
					++oa;
				}

				a += ni[j];
				--od;

				if (mn > oa + od)
					mn = oa + od;
			}
		}
	
		cout << "Case #" << i << ": " << mn << endl;
	}

	return 0;
}
