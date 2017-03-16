#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

struct ground
{
	vector < vector <int> > heights;

	int nRows()
	{
		return heights.empty() ? 0 : (int)heights[0].size();
	}

	int nColumns()
	{
		return (int)heights.size();
	}

	int singleColorRow (int y)
	{
		assert (nRows() && nColumns() && y < nRows());
		int prev = -1;
		for (unsigned x = 0; x < heights.size(); x++)
		{
			if (prev != -1 && heights[x][y] != prev)
				return -1;
			prev = heights[x][y];
		}
		return heights[0][y];
	}

	void cutRow (int y)
	{
		assert (nRows() && nColumns() && y < nRows() && singleColorRow (y) != -1);
		for (unsigned x = 0; x < heights.size(); x++)
			heights[x].erase (heights[x].begin() + y);
	}

	int singleColorColumn (int x)
	{
		assert (nRows() && nColumns() && x < nColumns());
		for (unsigned y = 0; y < heights[x].size(); y++)
			if (heights[x][y] != heights[x][0])
				return -1;
		return heights[x][0];
	}

	void cutColumn (int x)
	{
		assert (nRows() && nColumns() && x < nColumns() && singleColorColumn (x) != -1);
		heights.erase (heights.begin() + x);
	}

	void dump()
	{
		if (heights.empty() || heights[0].empty())
		{
			printf ("(the board is empty)\n");
			return;
		}

		printf ("--- ");
		for (int x = 0; x < nColumns(); x++)
			printf ("%3i ", singleColorColumn (x));
		printf ("\n");

		for (int y = 0; y < nRows(); y++)
		{
			printf ("%3i ", singleColorRow (y));
			for (int x = 0; x < nColumns(); x++)
				printf ("%3i ", heights[x][y]);
			printf ("\n");
		}
	}

	void read()
	{
		int numRows, numColumns;
		scanf ("%i %i", &numRows, &numColumns);

		heights.resize (numColumns);
		for (int i = 0; i < numColumns; i++)
			heights[i].resize (numRows);

		for (int y = 0; y < numRows; y++)
			for (int x = 0; x < numColumns; x++)
				scanf ("%i", &heights[x][y]);
	}
};

bool solve (ground theGround)
{
	//theGround.dump();

	for (int color = 1; color <= 100; color++)
	{
		bool relaxed = true;

		while (relaxed)
		{
			relaxed = false;

			for (int x = 0; x < theGround.nColumns(); x++)
				if (theGround.singleColorColumn (x) == color)
				{
					theGround.cutColumn (x);
					x--;
					relaxed = true;
				}

			for (int y = 0; y < theGround.nRows(); y++)
				if (theGround.singleColorRow (y) == color)
				{
					theGround.cutRow (y);
					y--;
					relaxed = true;
				}
		}
	}

	return theGround.nRows() == 0 && theGround.nColumns() == 0;
}

int main()
{
	int nTests;
	scanf ("%i", &nTests);

	int nYes = 0;
	for (int i = 0; i < nTests; i++)
	{
		ground g;
		g.read();

		bool answer = solve (g);
		printf ("Case #%i: %s\n", i + 1, answer ? "YES" : "NO");
		//printf ("\n");
		fprintf (stderr, "test case #%i of %i solved (%s)\n", i + 1, nTests, answer ? "YES" : "NO");
		if (answer) nYes++;
	}
	fprintf (stderr, "Yes answers: %i, No answers: %i\n", nYes, nTests - nYes);

	return 0;
}