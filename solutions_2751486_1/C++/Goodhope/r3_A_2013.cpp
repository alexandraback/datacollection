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

char vw[] = "aeiou",
	 s[1000001];

bool isC(char c)
{
	return strchr(vw, c) == NULL;
}

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		uint64 n;
		cin >> s >> n;

		char* p = s;

		vector<uint64> v;
		uint c = 0;
		while (*p)
		{
			if (isC(*p))
			{
				++c;
				if (c == n)
				{
					--c;
					v.push_back(p - s + 1 - n);
				}
			}
			else
				c = 0;

			++p;
		}

		uint64 res = 0;
		uint64 st = 0,
			   l = p - s;

		for (vector<uint64>::iterator it = v.begin(); it != v.end(); ++it)
		{
			++res;

			// beg
			res += *it - st;

			//tail
			res += l - *it - n;

			res += (*it - st) * (l - *it - n);

			st = *it + 1;
		}


		cout << "Case #" << i << ": " << res << endl;
	}

	return 0;
}
