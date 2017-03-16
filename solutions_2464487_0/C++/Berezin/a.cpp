#include <iostream>
#include <fstream>

using namespace std;

long long rr, tt, T, l, r, s, x, t;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cout << "Case #" << test << ": ";
		cin >> r >> t;int x = 0;
		s = 0;
		for (x = 1; x<= 1000; x++)
		{
			s += (r + 1) * (r + 1) - r * r;
			if (t < s)
				break;
			r += 2;
		}
		cout << x - 1 << endl;
	}

}