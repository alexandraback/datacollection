#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		cerr << "i = " << i << endl;
		cout << "Case #" << i << ": ";
		int x, y;
		cin >> x >> y;
		if(x > 0)
		{
			while(x != 0)
			{
				cout << "WE";
				--x;
			}
		}
		else
		{
			while(x != 0)
			{
				cout << "EW";
				++x;
			}
		}
		
		if(y > 0)
		{
			while(y != 0)
			{
				cout << "SN";
				--y;
			}
		}
		else
		{
			while(y != 0)
			{
				cout << "NS";
				++y;
			}
		}		
		
		cout << endl;
	}

	return 0;
}
