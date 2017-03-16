// gj.cpp
//

#include <assert.h>

#include <fstream>
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

double wa[1000],
	   wb[1000];

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		uint n;
		cin >> n;

		for (uint j = 0; j < n; ++j)
			cin >> wa[j];
		for (uint j = 0; j < n; ++j)
			cin >> wb[j];

		sort(wa, wa + n);
		sort(wb, wb + n);

		uint dw = 0,
			 bi = 0;
		for (uint j = 0; j < n; ++j)
		{
			if (wa[j] > wb[bi])
			{
				++dw;
				++bi;
			}
		}

		uint ww = 0;
		bi = n - 1;
		for (uint j = n - 1; j != -1; --j)
		{
			if (wa[j] > wb[bi])
				++ww;
			else
				--bi;
		}

		cout << "Case #" << i << ": " << dw << ' ' << ww << endl;
	}

	return 0;
}
