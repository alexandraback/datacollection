#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rows, cols, mines, freeCells;

void printExpand(int w, int h, int eR, int eB)
{
	for(int y = 0; y < rows; y++)
	{
		for(int x = 0; x < cols; x++)
		{
			if(x == 0 && y == 0) cout << 'c';
			else if(x < w && y < h || (x == w && y < eR) || (y == h && x < eB)) cout << '.';
			else cout << '*';
		}

		cout << endl;
	}
}

void solve()
{
	cin >> rows >> cols >> mines;
	freeCells = rows * cols - mines;

	if(rows == 1)
	{
		cout << 'c';

		for(int i = 1; i < freeCells; i++)
			cout << '.';

		for(int i = 0; i < mines; i++)
			cout << '*';

		cout << endl;

		return;
	}

	if(cols == 1)
	{
		cout << 'c' << endl;

		for(int i = 1; i < freeCells; i++)
			cout << '.' << endl;

		for(int i = 0; i < mines; i++)
			cout << '*' << endl;

		return;
	}

	if(freeCells == 1)
	{
		for(int y = 0; y < rows; y++)
		{
			for(int x = 0; x < cols; x++)
			{
				if(x == 0 && y == 0) cout << 'c';
				else cout << '*';
			}

			cout << endl;
		}

		return;
	}

	for(int w = 2; w <= cols; w++)
	{
		for(int h = 2; h <= rows; h++)
		{
			int area = w * h;
			int needExpand = freeCells - area;

			if(needExpand < 0) continue;
			if(needExpand == 0)
			{
				printExpand(w, h, 0, 0);
				return;
			}

			if(needExpand >= 2 && needExpand < 4) // We can only use one side
			{
				if(w < cols && needExpand <= h) // Expand right
				{
					printExpand(w, h, needExpand, 0);
					return;
				}

				if(h < rows && needExpand <= w) // Expand below
				{
					printExpand(w, h, 0, needExpand);
					return;
				}
			}
			else if(needExpand >= 4) // Use both sides
			{
				int eR = min(needExpand - 2, h); // Expand right
				int eB = needExpand - eR; // Expand below

				if(w == cols) // We can only use bottom
				{
					eR = 0;
					eB = needExpand;
				}
				if(h == rows) // We can only use right
				{
					eB = 0;
					eR = needExpand;
				}

				if(eR <= h && eB <= w) // We can't expand too much right or below
				{
					printExpand(w, h, eR, eB);
					return;
				}
			}
		}
	}

	cout << "Impossible" << endl;
}

int main()
{
	int caseCount;
	cin >> caseCount;

	for(int i = 1; i <= caseCount; i++)
	{
		cout << "Case #" << i << ": " << endl;
		solve();
	}

	return 0;
}