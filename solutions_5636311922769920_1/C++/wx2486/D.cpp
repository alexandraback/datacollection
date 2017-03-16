#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int cn; cin >> cn;

	for (int cc = 1; cc <= cn; cc++)
	{
		int n, level, chance; cin >> n >> level >> chance;

		cout << "Case #" << cc << ":";
		
		if (chance * level < n)
			cout << " IMPOSSIBLE" << endl;
		else
		{
			for (int i = 0; i < chance && i * level < n; i++)
			{
				__int64 test = 0;

				for (int j = 0; j < level && i * level + j < n; j++)
				{
					test *= n;
					test += i * level + j;
				}

				cout << ' ' << test + 1;
			}
			cout << endl;
		}
	}

	return 0;
}