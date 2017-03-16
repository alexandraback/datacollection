#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

int main()
{
	int nc = 0;
	cin >> nc;

	for (int c = 0; c < nc; ++c)
	{
		string s;
		cin >> s;

		int div = s.find_first_of('/');
		__int64 p = _atoi64(s.substr(0, div).c_str());
		__int64	q = _atoi64(s.substr(div + 1, s.length() - 1).c_str());

		int g = 1, res = -1;
		for (; g < 41; ++g)
		{
			if (q % 2 == 0)
				q /= 2;
			else
				p *= 2;
			if (p > q) {
				if (res == -1)
					res = g;
				p -= q;
				
			}
			if (p == q) {
				if (res == -1)
					res = g;
				break;
			}
		}

		cout << "Case #" << c + 1 << ": ";

		if (res == -1 || g > 40)
			cout << "impossible" << endl;
		else 
			cout << res << endl;
	}

	return 0;
}
