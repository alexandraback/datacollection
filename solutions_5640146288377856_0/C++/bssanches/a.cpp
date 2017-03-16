#include <bits/stdc++.h>

using namespace std;

int t,r,c,w;
int mat[25][25];

int main(void)
{
	cin >> t;
	int cases = 0;
	while (t--)
	{
		cases++;
		cin >> r >> c >> w;
		int cont = 0;
		int id;
		for (int i = 0; i < r; ++i)
		{
			for (int j = w-1; j < c; j += w)
			{
				if (i == r - 1 && j + w >= c)
				{
					id = j;
					break;
				}
				cont++;
				if (j + w >= c)
				{
					break;
				}
			}
		}

		if (id + 1 == c)
			cout << "Case #" << cases << ": " << cont + w << "\n";
		else
			cout << "Case #" << cases << ": " << cont + w + 1 << "\n";
	}
	return 0;
}