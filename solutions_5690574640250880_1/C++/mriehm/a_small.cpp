#include <cstdio>
#include <algorithm>

using namespace std;

void impossible();

void impossible()
{
	printf("Impossible\n");
}

int main(void)
{
	unsigned int number_of_tests;
	scanf("%u\n", &number_of_tests);
	for (unsigned int test = 0; test < number_of_tests; ++test)
	{
		printf("Case #%u:\n", test + 1);

		unsigned int rows;
		unsigned int columns;
		unsigned int mines;
		scanf("%u %u %u\n", &rows, &columns, &mines);

		unsigned int virtual_cols = columns;
		unsigned int virtual_rows = rows;
		unsigned int virtual_mines = mines;

		int keep_going = 1;
		while (keep_going)
		{
			keep_going = 0;
			if (virtual_cols > virtual_rows)
			{
				if (virtual_mines >= virtual_rows)
				{
					--virtual_cols;
					virtual_mines -= virtual_rows;
					keep_going = 1;
				}
			}
			else
			{
				if (virtual_mines >= virtual_cols)
				{
					--virtual_rows;
					virtual_mines -= virtual_cols;
					keep_going = 1;
				}
			}
		}
		int real_rows = virtual_rows == rows;
		int real_cols = virtual_cols == columns;

		//printf("cols: %u, rows: %u", virtual_rows, virtual_cols);

		//1 for long rows and short cols, 0 for long cols and short rows
		int rows_are_long = virtual_cols > virtual_rows;

		//1 for long rows and short cols, 0 for long cols and short rows
		int long_dim_length = max(virtual_cols, virtual_rows);
		int short_dim_length = min(virtual_cols, virtual_rows);

		//If it was reduced to a 2 x 1
		if ((virtual_rows == 1 && virtual_cols == 2 && !real_rows) || (virtual_cols == 1 && virtual_rows == 2 && !real_cols))
		{
			impossible();
			continue;
		}

		//One mine when short side is of length 2
		if (short_dim_length == 2 && virtual_mines == 1)
		{
			impossible();
			continue;
		}

		//Two mines on 3 x 3
		if (long_dim_length == 3 && short_dim_length == 3 && virtual_mines == 2)
		{
			impossible();
			continue;
		}

		//Print first row
		printf("c");
		for (unsigned int col = 1; col < columns; ++col)
		{
			if (col < virtual_cols)
			{
				printf(".");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");

		//Print remaining rows
		for (unsigned int row = 1; row < rows; ++row)
		{
			for (unsigned int col = 0; col < columns; ++col)
			{
				if (col < virtual_cols && row < virtual_rows)
				{
							//If in last column and there is a mine to print (don't print overflow)
					if ((rows_are_long &&
							//If in last column and there is a mine to print (don't print overflow)
							 ((col == virtual_cols - 1 && virtual_rows - virtual_mines <= row && (row > 1 || virtual_mines < virtual_rows - 1)) ||
							//If in second to last row and there is an overflow mine to print
							  (col == virtual_cols - 2 && row == virtual_rows - 1 && virtual_mines == virtual_rows - 1 && virtual_mines > 1))) ||
							(!rows_are_long &&
							//If in last row and there is a mine to print (don't print overflow)
							 ((row == virtual_rows - 1 && virtual_cols - virtual_mines <= col && (col > 1 || virtual_mines < virtual_cols - 1)) ||
							//If in second to last row and there is an overflow mine to print
							  (row == virtual_rows - 2 && col == virtual_cols - 1 && virtual_mines == virtual_cols - 1 && virtual_mines > 1))))
					{
						printf("*");
					}
					else
					{
						printf(".");
					}
				}
				else
				{
					printf("*");
				}
			}
			printf("\n");
		}
	}
}
