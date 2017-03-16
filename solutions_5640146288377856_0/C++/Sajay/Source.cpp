#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

bool ascending(int *i, int *j) { return (i[0]<j[0]); }

void main()
{
	ifstream input;
	input.open("A-small-attempt1.in");

	if (!input.is_open())
	{
		cout << "Error opening file\n";
		system("pause");
	}

	int tot_cases;
	input >> tot_cases;

	ofstream output;
	output.open("solution.out");

	for (int i = 1; i <= tot_cases; i++)
	{
		cout << i << '\n';
		output << "Case #" << i << ": ";

		int R, C, W;
		input >> R >> C >> W;

		int ans = ceil(float(C) / float(W)) + W - 1;
		
		output << ans << '\n';
	}

	output.close();
	input.close();
}