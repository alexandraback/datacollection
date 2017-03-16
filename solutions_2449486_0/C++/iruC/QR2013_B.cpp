// iruC curi.yun@gmail.com
#include <iostream>
#include <fstream>

// No sanity checking on parameters or input files...


bool checkContiguous( int height, int rows, int cols, int pattern[100][100] )
{
	int i, j;
	bool checkCols[100];
	int colCount;

	for( j = 0; j < cols; ++j ) checkCols[j] = false;

	for( i = 0; i < rows; ++i )
	{
		colCount = 0;
		for( j = 0; j < cols; ++j )
		{
			if( pattern[i][j] == height )
			{
				++colCount;
			}
		}
		if( colCount < cols )
		{
			// Go through and check the columns
			for( j = 0; j < cols; ++j )
			{
				if( pattern[i][j] == height )
				{
					checkCols[j] = true;
				}
			}
		}
	}

	for( j = 0; j < cols; ++j )
	{
		for( i = 0; checkCols[j] && (i < rows); ++i )
		{
			if( pattern[i][j] != height )
			{
				return false;
			}
		}
	}

	return true;
}

bool possible( int rows, int cols, int pattern[100][100] )
{
	int i, j;
	// Heights in pattern
	bool heights[101];

	for( i = 0; i < rows; ++i )
	{
		for( j = 0; j < cols; ++j )
		{
			heights[pattern[i][j]] = true;
		}
	}

	// Lowest number has to be continguous within
	// a row or a column from edge-to-edge
	bool foundLowest = false;
	for( int h = 0; h < 101; ++h )
	{
		if( !foundLowest && heights[h] )
		{
			foundLowest = true;
			// The lowest level should be contiguous in one of the directions
			if( !checkContiguous( h, rows, cols, pattern) )
			{
				return false;
			}
		}
		else if( foundLowest )
		{
			// Anything above the lowest shouldn't have valleys away from the edges
			// TODO for large set
		}
	}

	return true;

}

int main( int argc, char** argv )
{
	char dummy[10];
	int pattern[100][100];
	int testCases;
	int N, M;
	std::ifstream inFile(argv[1], std::ifstream::in);

	inFile >> testCases;
	inFile.getline(dummy, sizeof(dummy));

	for( int i = 0; i < testCases; ++i )
	{
		// Normally, I'd reset the pattern here...

		inFile >> N >> M;
		inFile.getline(dummy, sizeof(dummy));
		for( int row = 0; row < N; ++row )
		{
			for( int col = 0; col < M; ++col )
			{
				inFile >> pattern[row][col];
			}
			inFile.getline(dummy, sizeof(dummy));
		}

		std::cout << "Case #" << (i+1) << ": ";
		std::cout << (possible(N, M, pattern) ? "YES" : "NO") << std::endl;
	}

	inFile.close();
}
