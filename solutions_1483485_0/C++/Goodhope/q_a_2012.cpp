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

char a[101],
	 r[101],
	 c[] = "yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;
	cin.getline(a, sizeof(a));

	for (uint64 i = 0; i < cases; ++i)
	{
		cin.getline(a, sizeof(a));
		char* p = a,
			* pb = r;
		while (*p)
		{
			if (' ' != *p)
				*pb = c[*p - 'a'];
			else
				*pb = ' ';

			++p;
			++pb;
		}
		*pb = 0;

		cout << "Case #" << i + 1 << ": " << r << endl;
	}

	return 0;
}
