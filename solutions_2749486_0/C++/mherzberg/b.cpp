#include <iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	
	for (int i = 1; i <= cases; ++i)
	{
		int x, y;
		cin >> x >> y;
		
		cout << "Case #" << i << ": ";
		
		if (x > 0)
		{
			for (int j = 0; j < x; ++j)
			{
				cout << "WE";
			}
		}
		
		if (x < 0)
		{
			for (int j = 0; j > x; --j)
			{
				cout << "EW";
			}
		}
		
		if (y > 0)
		{
			for (int j = 0; j < y; ++j)
			{
				cout << "SN";
			}
		}
		
		if (y < 0)
		{
			for (int j = 0; j > y; --j)
			{
				cout << "NS";
			}
		}
		
		cout << endl;
	}
	return 0;
}
	
