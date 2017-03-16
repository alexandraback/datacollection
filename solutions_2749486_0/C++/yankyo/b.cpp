
#include <iostream>
#include <string>

using namespace std;

string jumpto(int x, int y)
{
	string res = "";

	string sx = (x > 0) ? "WE" : "EW";
	string sy = (y > 0) ? "SN" : "NS";

	if (x < 0) x = -x;
	if (y < 0) y = -y;

	for (int i = 0; i < x; i++) res += sx;
	for (int i = 0; i < y; i++) res += sy;
	return res;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int x, y;
		cin >> x >> y;

		cout << "Case #" << t << ": " << jumpto(x, y) << endl;
	}

	return 0;
}

