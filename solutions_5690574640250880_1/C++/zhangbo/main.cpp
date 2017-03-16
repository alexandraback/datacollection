#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>

using namespace std;

void calc()
{
	static int caseno = 0;
	caseno++;

	int r, c, m;
	cin >> r >> c >> m;
	vector<vector<char>> v(r, vector<char>(c, '*'));

	bool impossible = true;
	if (r*c > m)
	{
		int empty = r*c - m;
		if (empty == 1 || r == 1 || c == 1)
		{
			impossible = false;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (empty>0)
					{
						v[i][j] = '.';
						empty--;
					}
				}
			}
			v[0][0] = 'c';
		}
		else
		{
			for (int rf = 2; rf <= r; rf++)
			{
				int cf = empty / rf;
				if (empty % rf) cf++;
				if (cf > c) continue;
				if (cf < 2) break;

				int fill = rf*cf - empty;
				int fmax = (rf - 2) * (cf - 2);
				if (fill > fmax) continue;

				impossible = false;
				for (int i = 0; i < rf; i++)
				{
					for (int j = 0; j < cf; j++)
					{
						v[i][j] = '.';
					}
				}
				v[0][0] = 'c';
				for (int i = rf - 1; i >= 2; i--)
				{
					for (int j = cf - 1; j >= 2; j--)
					{
						if (fill > 0)
						{
							v[i][j] = '*';
							fill--;
						}
					}
				}
				break;
			}
		}
	}

	cout << "Case #" << caseno << ":" << endl;
	if (impossible)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << v[i][j];
			}
			cout << endl;
		}
	}
}

int main()
{
	int k = 1;
	cin >> k;
	while (k-- > 0)
	{
		calc();
	}

	return 0;
}

