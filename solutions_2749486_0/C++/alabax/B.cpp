#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int x, y;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;

	for (int i=0; i<t; ++i)
	{
		cin >> x >> y;

		string res;

		for (int i=0; i<abs(x); ++i)
		{
			if (x > 0)
				res += "WE";
			else
				res += "EW";
		}
		for (int i=0; i<abs(y); ++i)
		{
			if (y > 0)
				res += "SN";
			else
				res += "NS";
		}

		cout << "Case #" << i+1 << ": " << res << endl;
	}

	return 0;
}