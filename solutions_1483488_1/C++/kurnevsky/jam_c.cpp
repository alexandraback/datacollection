#include <iostream>
#include <algorithm>

using namespace std;

bool used[2000002];

inline int get_size(int x)
{
	int result = 0;
	while (x)
	{
		x /= 10;
		result++;
	}
	return result;
}

inline void shift(int& x, int size)
{
	int c = x % 10;
	for (int i = 0; i < size; i++)
		c *= 10;
	x = x / 10 + c;
}

int main()
{
	int t, a, b;
	int size, ans, temp;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		fill(&used[a], &used[b + 1], false);
		size = get_size(a) - 1;
		ans = 0;
		for (int j = a; j <= b; j++)
			if (!used[j])
			{
				used[j] = true;
				int x = j;
				temp = 0;
				for (int k = 0; k < size; k++)
				{
					shift(x, size);
					if (x >= a && x <= b && !used[x])
					{
						temp++;
						used[x] = true;
					}
				}
				ans += (temp * (temp + 1)) / 2;
			}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}
