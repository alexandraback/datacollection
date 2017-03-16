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

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		__int64 x, y;
		cin >> x >> y;

		map<pair<__int64, __int64>, string> v,
											q;

		map<pair<__int64, __int64>, string>* a = &v,
										   * b = &q;

		v.insert(make_pair(make_pair(0, 0), ""));

		string res;

		uint j = 0;
		while (res.empty())
		{
			++j;
			for (map<pair<__int64, __int64>, string>::iterator it = a->begin(); it != a->end(); ++it)
			{
				pair<pair<__int64, __int64>, string> xy = *it;

				if (xy.first.first + j == x && xy.first.second == y)
				{
					res = xy.second + 'E';
					break;
				}
				else
					b->insert(make_pair(make_pair(xy.first.first + j, xy.first.second), xy.second + 'E'));

				if (xy.first.first - j == x && xy.first.second == y)
				{
					res = xy.second + 'W';
					break;
				}
				else
					b->insert(make_pair(make_pair(xy.first.first - j, xy.first.second), xy.second + 'W'));
	
				if (xy.first.first == x && xy.first.second + j == y)
				{
					res = xy.second + 'N';
					break;
				}
				else
					b->insert(make_pair(make_pair(xy.first.first, xy.first.second + j), xy.second + 'N'));

				if (xy.first.first == x && xy.first.second - j == y)
				{
					res = xy.second + 'S';
					break;
				}
				else
					b->insert(make_pair(make_pair(xy.first.first, xy.first.second - j), xy.second + 'S'));
			}

			a->clear();
			swap(a, b);
		}

		cout << "Case #" << i << ": " << res << endl;
	}

	return 0;
}
