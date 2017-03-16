
#include <iostream>
#include <fstream>
#include "lawnmower.h"

using namespace std;

void SolveLawnMower()
{
	// Set up an input and output file
	ifstream file_in;
	file_in.open("C:\\Users\\John\\Desktop\\CodeJam\\lawnmower.in");
	ofstream file_out;
	file_out.open("C:\\Users\\John\\Desktop\\CodeJam\\lawnmower.out");

	// Load the number of test cases
	int test_cases;
	file_in >> test_cases;
	cout << test_cases << " cases" << endl;

	// Each test case needs an N, M and a couple of arrays
	int N;
	int M;
	int target_lawn[100][100];
	int current_lawn[100][100];
	int max_height;
	bool possible;

	// Loop over the cases:
	for (int n = 0; n < test_cases; n++)
	{
		// Load the data and initialise the current lawn
		file_in >> N >> M;
		cout << "number of rows: " << N << endl;
		cout << "number of columns: " << M << endl;
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				file_in >> target_lawn[n][m];
				current_lawn[n][m] = 100;
			}
		}

		// Now go through the rows and find the maximum in each row
		for (int n = 0; n < N; n++)
		{
			max_height = 0;
			for (int m = 0; m < M; m++)
			{
				max_height = Max(max_height, target_lawn[n][m]);
			}

			// Now that we've found the max height, mow along that row with that
			// maximum height
			for (int m = 0; m < M; m++)
			{
				current_lawn[n][m] = Min(current_lawn[n][m], max_height);
			}
		}

		// Do the same for the columns
		for (int m = 0; m < M; m++)
		{
			max_height = 0;
			for (int n = 0; n < N; n++)
			{
				max_height = Max(max_height, target_lawn[n][m]);
			}
			
			for (int n = 0; n < N; n++)
			{
				current_lawn[n][m] = Min(current_lawn[n][m], max_height);
			}
		}

		// Now we check to see whether or not they match up
		possible = true;
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (current_lawn[n][m] != target_lawn[n][m]) possible = false;
			}
		}

		// And now output the result
		cout << "Case " << (n + 1) << ": ";
		file_out << "Case #" << (n + 1) << ": ";
		if (possible)
		{
			cout << "YES" << endl;
			file_out << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
			file_out << "NO" << endl;
		}
			
	}

	// Close the files
	file_in.close();
	file_out.close();
	return;
}

int Max(int a, int b)
{
	return (a > b) ? a : b;
}

int Min(int a, int b)
{
	return (a > b) ? b : a;
}