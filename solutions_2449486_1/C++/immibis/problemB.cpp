#include <stdio.h>
#include <assert.h>

#define IN_FILENAME "Blarge.txt"

int *ar;
int w;
int h;

int get(int x, int y)
{
	assert(x >= 0 && y >= 0 && x < w && y < h);
	return ar[x + y*w];
}

bool checkRowNoHigherThan(int row, int height)
{
	for(int x = 0; x < w; x++)
		if(get(x, row) > height)
			return false;
	return true;
}

bool checkColNoHigherThan(int col, int height)
{
	for(int y = 0; y < h; y++)
		if(get(col, y) > height)
			return false;
	return true;
}

bool isPossible()
{
	/*
	For each square, there must be a row or a column passing through that square where all the grass is no higher than that square.
	*/

	for(int x = 0; x < w; x++)
		for(int y = 0; y < h; y++)
			if(!checkRowNoHigherThan(y, get(x, y)) && !checkColNoHigherThan(x, get(x, y)))
			{
				// No row or column the mower could have come through to get this square.
				return false;
			}
	return true;
}

int main(int argc, char **argv)
{
	freopen(IN_FILENAME, "r", stdin);
	freopen("output.txt", "w", stdout);

	int numCases;
	scanf("%i ", &numCases);
	for(int c = 1; c <= numCases; c++)
	{
		scanf("%i %i ", &h, &w);

		ar = new int[w * h];
		for(int y = 0; y < h; y++)
			for(int x = 0; x < w; x++)
				scanf("%i ", &ar[x + y*w]);

		printf("Case #%i: %s\n", c, isPossible() ? "YES" : "NO");

		delete [] ar;
	}

	return 0;
}
