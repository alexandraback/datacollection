#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t = 0;
	cin >> t; getchar();
	string s;
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		int x, y;
		cin >> x >> y;
		if (y > 0)
			for (int i = 0; i < y; ++i)
				cout << "SN";
		else
			for (int i = 0; i < -y; ++i)
				cout << "NS";
		if (x > 0)
			for (int i = 0; i < x; ++i)
				cout << "WE";
		else
			for (int i = 0; i < -x; ++i)
				cout << "EW";
		cout << endl;
	}
}