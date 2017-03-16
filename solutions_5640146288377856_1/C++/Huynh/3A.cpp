#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
//hn667
int main()
{
	// constants
	const string FILE = "C:/Users/Huynh/Source/Repos/GoogleCodeJam/3A/Debug/A-large.in";

	// variables
	ifstream input_file(FILE);				// input file stream
	ofstream output_file(FILE + "out.txt");	// output file stream
	int test_cases;							// number of test cases
	int R, C, W;
	int ans;

	// initialization
	ios::sync_with_stdio(false);

	/****************************************************/

	if (input_file.fail())
		cout << "FAILURE\n";
	input_file >> test_cases;	// get test cases

	// run all test cases
	for (int tc = 1; tc <= test_cases; tc++)
	{
		input_file >> R >> C >> W;

		if (C == W)
			ans = R  + W - 1;
		else if (W == 1)
			ans = (R * C);
		else
		{
			if (C % W == 0)
				ans = (R * (C / W)) + (W - 1);
			else
				ans = (R * (C / W)) + (W - 1) + 1;
		}

		output_file << "Case #" << tc << ": "  << ans << endl;
	}

}