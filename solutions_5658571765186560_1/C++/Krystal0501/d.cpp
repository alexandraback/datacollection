#include <iostream>

using namespace std;

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int x, r, c;
		int result;
		cin >> x >> r >> c;

		if (r * c % x != 0)
		{
			result = 0; // Richard win
		}
		else
		{
			if (x == 1 || x == 2)
			{
				result = 1; // Gabriel win
			}
			else if (x >= 7)
			{
				result = 0;
			}
			else if (x == 3)
			{
				if (r == 1 || c == 1)
				{
					result = 0;
				}
				else
				{
					result = 1;
				}
			}
			else if (x == 4)
			{
				if (r == 1 || c == 1 || r == 2 || c == 2)
				{
					result = 0;
				}
				else 
				{
					result = 1;
				}
			}
			else if (x == 5)
			{
				if (r == 1 || c == 1 || r == 2 || c == 2)
				{
					result = 0;
				}
				else if ((r == 3 && c == 5) || (r == 5 && c == 3))
				{
					result = 0;
				}
				else 
				{
					result = 1;
				}
			}
			else if (x == 6)
			{
				if (r == 1 || c == 1 || r == 2 || c == 2)
				{
					result = 0;
				}
				else if (r == 3 || c == 3)
				{
					result = 0;
				}
				else
				{
					result = 1;
				}
			}
		}

		if (result == 0)
		{
			cout << "Case #" << i + 1 << ": RICHARD" << endl;
		}
		else
		{
			cout << "Case #" << i + 1 << ": GABRIEL" << endl;
		}

	}

	return 0;
}