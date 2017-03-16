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
	const string FILE = "C:/Users/Huynh/Source/Repos/GoogleCodeJam/3B/Debug/C-small-attempt0.in";
	const int MAX_VALUE = 31;

	// variables
	ifstream input_file(FILE);				// input file stream
	ofstream output_file(FILE + "out.txt");	// output file stream
	int test_cases;							// number of test cases
	int C, D, V;
	int ans;
	int denomination;
	bool dp[MAX_VALUE];

	// initialization
	ios::sync_with_stdio(false);

	/****************************************************/

	if (input_file.fail())
		cout << "FAILURE\n";
	input_file >> test_cases;	// get test cases

	// run all test cases
	for (int tc = 1; tc <= test_cases; tc++)
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = true;

		input_file >> C >> D >> V;

		for (int i = 0; i < D; i++)
		{
			input_file >> denomination;
			for (int j = V; j > 0; j--)
			{
				if (dp[j] && (j + denomination < MAX_VALUE))
				{
					dp[j + denomination] = true;
				}
			}
			dp[denomination] = true;
		}
		
		int ans = 0;
		int next_fill = -2;
		while (next_fill != -1)
		{
			next_fill = -1;
			for (int i = 0; i <= V; i++)
			{
				if (!dp[i])
				{
					if (next_fill == -1)
					{
						//cout << "Next Fill: " << i << endl;
						next_fill = i;
						ans++;
					}
						
				}
			}

			if (next_fill != -1)
			{
				for (int j = V; j > 0; j--)
				{
					if (dp[j] && (j + next_fill < MAX_VALUE))
					{
						dp[j + next_fill] = true;
					}
				}
				dp[next_fill] = true;
			}
		} 

		output_file << "Case #" << tc << ": " << ans << endl;
	}

}