#include <cstdio>
#include <algorithm>

using namespace std;

int mine_sweep(bool ** mines, int x, int y, int rem, int dim_x, int dim_y)
{
	if (rem == 0)
		return 0;
	int xrem = dim_x - x;
	int yrem = dim_y - y;
	if (max(xrem, yrem) < 3) // base case: reduced to 2x2 or 1x2, impossible
		return -1;
	int min_rem = min(xrem, yrem);
	if (rem <= min_rem) // base case, finish in this case
	{
		if (rem <= min_rem - 2 || rem == min_rem) // with 2+ space or full, rem > 0
		{
			if (min_rem == xrem) // equal or x shorter
			{
				for (int i = 0; i < rem; i++)
					mines[x + i][y] = true;
				return 0;
			}
			else // y shorter
			{
				for (int i = 0; i < rem; i++)
					mines[x][y + i] = true;
				return 0;
			}
		}
		else // have to accomodate longer edge
		{
			if (min_rem == xrem) // x edge shorter or equal
			{
				if (xrem == 2 || yrem <= 3) // cannot satisfy
					return -1;
				for (int i = 0; i < rem - 1; i++)
					mines[x + i][y] = true;
				mines[x][y + 1] = true;
				return 0;
			}
			else // y edge shorter
			{
				if (yrem == 2 || xrem <= 3) // impossible
					return -1;
				for (int i = 0; i < rem - 1; i++)
					mines[x][y + i] = true;
				mines[x + 1][y] = true;
				return 0;
			}
		}
	}
	// recursive case, fill in shorter edge
	if (min_rem == xrem) // equal or x edge shorter
	{
		for (int i = 0; i < xrem; i++)
			mines[x + i][y] = true;
		return mine_sweep(mines, x, y + 1, rem - xrem, dim_x, dim_y);
	}
	else // y shorter
	{
		for (int i = 0; i < yrem; i++)
			mines[x][y + i] = true;
		return mine_sweep(mines, x + 1, y, rem - yrem, dim_x, dim_y);
	}
}

int main (int argc, const char * argv[])
{
	freopen(argv[1], "r", stdin);
	if (argc == 3)
		freopen(argv[2], "w", stdout);

	int num_tc;
	scanf("%d\n", &num_tc);
	for (int i = 0; i < num_tc; i++)
	{
		int x, y, num_mine;
		scanf("%d %d %d\n", &x, &y, &num_mine);
		if (num_mine == x * y - 1) // the only corner case
		{
			printf("Case #%d:\n", i + 1);
			for (int j = 0; j < x - 1; j++)
			{
				for (int k = 0; k < y; k++)
					printf("*");
				printf("\n");
			}
			for (int j = 0; j < y - 1; j++)
				printf("*");
			printf("%s\n", "c");
		}
		else
		{
			bool ** mines;
			mines = new bool *[x];
			for (int j = 0; j < x; j++)
			{
				mines[j] = new bool[y];
				for (int k = 0; k < y; k++)
					mines[j][k] = false;
			}
			int result = mine_sweep(mines, 0, 0, num_mine, x, y);
			printf("Case #%d:\n", i + 1);
			if (result == -1)
				printf("Impossible\n");
			else
			{
				for (int j = 0; j < x - 1; j++)
				{
					for (int k = 0; k < y; k++)
						if (mines[j][k])
							printf("*");
						else
							printf(".");
					printf("\n");
				}
				for (int j = 0; j < y - 1; j++)
					if (mines[x - 1][j])
						printf("*");
					else
						printf(".");
				printf("c\n");
			}

			for (int j = 0; j < x; j++)
				delete[] mines[j];
			delete[] mines;
		}
	}

	fclose(stdin);
	if (argc == 3)
		fclose(stdout);
	return 0;
}
