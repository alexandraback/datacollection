#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;	cin >> tc;
	for (int T = 1; T <= tc; T++)
	{

		int x, y;	cin >> x >> y;
		cout << "Case #" << T << ": ";
		if (x < 0)
		{
			for (int i = 0; i < -x; i++)
				cout << "EW";
		}
		else if(x > 0)
		{
			for (int i = 0; i < x; i++)
				cout << "WE";
		}
		if (y < 0)
			for (int i = 0; i < -y; i++)
				cout << "NS";
		else if (y > 0)
			for (int i = 0; i < y; i++)
				cout << "SN";

		cout << endl;
	}

}
