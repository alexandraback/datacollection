// gj.cpp
//

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

bool u[1000001];

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 0; i < cases; ++i)
	{
		uint64 a, b;
		cin >> a >> b;
		
		uint r = 0;
		uint64 t = a,
			   mp = 1;
		while (t)
		{
			t /= 10;
			++r;
			mp *= 10;
		}
		--r;

		uint64 res = 0;
		t = a;
		while (t <= b)
		{
			if (!u[t - a])
			{
				uint64 p = 10,
					   np = 0;
				for (uint j = 0; j < r; ++j)
				{
					uint64 v = t / p + (t % p) * (mp / p);
					if (v != t && v >= a && v <= b && !u[v - a])
					{
						u[v - a] = true;
						++res;
						++np;
					}
					p *= 10;
				}

				res += np * (np - 1) / 2;
			}

			++t;
		}

		fill(u, u + b - a + 1, false);

		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}
