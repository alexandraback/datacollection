#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int c = 0; c < t; c++)
	{
		int n, s, p;
		cin >> n >> s >> p;
		int base[100];
		int special[100];

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			base[i] = (x + 2) / 3;

			if (x == 0) special[i] = 0;
			else if (x >= 29) special[i] = 10;
			else special[i] = (x+1)/3+1;
		}

		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (base[i] >= p)
			{
				count++;
			}
			else if (s > 0 && special[i] >= p)
			{
				count++;
				s--;
			}
		}

		cout << "Case #" << c + 1 << ": " << count << "\n";
	}
}
