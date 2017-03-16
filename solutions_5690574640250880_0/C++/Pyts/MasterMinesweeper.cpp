#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	ifstream input ("input3.in");
	ofstream output ("answers3.txt");
	int t;
	input >> t;
	bool** free = new bool*[50];
	for( int i = 0; i < 50; ++i )
	{
		free[i] = new bool[50];
	}

	for( int k = 1; k <= t; ++k )
	{
		int rows, columns, mines;
		bool possible = false, done = false;
		input >> rows >> columns >> mines;

		for( int i = 0; i < rows; ++i )
		{
			for( int j = 0; j < columns; ++j )
			{
				free[i][j] = true;
			}
		}
		if( mines == 0 )
			possible = done = true;

// one row case
		if( !done && rows == 1 )
		{
			for( int j = columns-1; j >= 1 && mines > 0; --j )
			{
				free[0][j] = false;
				--mines;
			}
			possible = done = true;
		}
// one column case
		if( !done && columns == 1 )
		{
			for( int i = 0; i < rows-1 && mines > 0; ++i )
			{
				free[i][0] = false;
				--mines;
			}
			possible = done = true;
		}
// simple case
		if( (rows == 2 || columns == 2) && mines % 2 && mines != rows*columns - 1)
		{
			possible = false;
			done = true;
		}
// two rows case
		if( !done && rows == 2 )
		{
			int j;
			for( j = columns-1; j >= 1 && mines > 1; --j )
			{
				free[0][j] = free[1][j] = false;
				mines -= 2;
			}
			if( mines % 2 )
			{
				free[0][0] = false;
				--mines;
				possible = true;
			}
			else
			{
				possible = ( j > 1 || ( j == 1 && free[0][1] && free[1][1] ) );
			}
			done = true;
		}
// two columns case
		if( !done && columns == 2 )
		{
			int i;
			for( i = 0; i < rows-1 && mines > 1; ++i )
			{
				free[i][0] = free[i][1] = false;
				mines -= 2;
			}
			if( mines % 2 )
			{
				free[rows-1][1] = false;
				--mines;
				possible = true;
			}
			else
			{
				possible = ( i < rows-2 || ( i == rows-2 && free[rows-2][0] && free[rows-2][1] ) );
			}
			done = true;
		}
// the rest of the cases (rows & columns are both no less than 3)
		for( int r = 0; !done && r < rows - 2; ++r )
		{
			for( int j = columns-1; j > 1 && mines > 0; --j )
			{
				free[r][j] = false;
				--mines;
			}
			if( mines == 0 )
			{
				possible = done = true;
			}
		}
		int lower_limit = rows - 2;
		int left_limit = 1;
		if( !done )
		{
			if( mines % 2 )
			{
				free[rows-3][2] = true;
				++mines;
				--lower_limit;
				++left_limit;
			}
			for( int s = 0; s < lower_limit && mines > 1; ++s )
			{
				free[s][0] = free[s][1] = false;
				mines -= 2;
			}
			for( int s1 = columns - 1; s1 > left_limit && mines > 1; --s1 )
			{
				free[rows-1][s1] = free[rows-2][s1] = false;
				mines -= 2;
			}
			if( mines == 0 )
			{
				possible = true;
			}
			else
			{
				if( mines == 8 )
				{
					free[rows-3][0] = free[rows-3][1] = free[rows-3][2] = false;
					free[rows-2][0] = free[rows-2][1] = free[rows-2][2] = false;
					free[rows-1][1] = free[rows-1][2] = false;
					mines -= 8;
					possible = true;
				}
				else
					possible = false;
			}
			done = true;
		}

		output << "Case #" << k << ":\n";
		if( done && possible )
		{
			for( int i = 0; i < rows - 1; ++i )
			{
				for( int j = 0; j < columns; ++j )
				{
					if( free[i][j] )
						output << '.';
					else
						output << '*';
				}
				output << endl;
			}
			output << 'c';
			for( int j = 1; j < columns; ++j )
			{
				if( free[rows - 1][j] )
					output << '.';
				else
					output << '*';
			}
		}
		else
			output << "Impossible";
		output << endl;
	}
	input.close();
	output.close();
}
