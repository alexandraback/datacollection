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

double c, f, x;

double sec()
{
	double s = c / 2,
		   pr = 0,
		   a = x / 2.;

	uint i = 1;
	do
	{
		pr = a;
		a = s + x / (2. + f * i);
		s += c / (2. + f * i);
		++i;
	} while (a < pr);

	return pr;
}

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		cin >> c >> f >> x;

		double res = sec();

		cout << "Case #" << i << ": " << fixed << setprecision(7) << res << endl;
	}

	return 0;
}
