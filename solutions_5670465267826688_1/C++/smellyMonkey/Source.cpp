#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <cstdlib>
#include <set>
#include <stdio.h>
using namespace std;



int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("data.in");
	outFile.open("data.out");

	int dict[5][5];
	dict[1][1] = 1;
	dict[1][2] = 2;
	dict[1][3] = 3;
	dict[1][4] = 4;

	dict[2][1] = 2;
	dict[2][2] = -1;
	dict[2][3] = 4;
	dict[2][4] = -3;

	dict[3][1] = 3;
	dict[3][2] = -4;
	dict[3][3] = -1;
	dict[3][4] = 2;

	dict[4][1] = 4;
	dict[4][2] = 3;
	dict[4][3] = -2;
	dict[4][4] = -1;

	int T;
	inFile >> T;

	for (int ca = 1; ca <= T; ++ca)
	{
		long long int l, x;
		inFile >> l >> x;

		string s;
		inFile >> s;

		vector<int> pattern(s.length(), 0);
		for (int i = 0; i < s.length(); ++i)
		{
			pattern[i] = s[i] - 'i' + 2;
		}

		x = x <= 4 ? x : 4 + x % 4;

		vector<int> f(x * l, 0);

		f[0] = pattern[0];

		for (int i = 1; i < f.size(); ++i)
		{
			int last = f[i - 1];
			int sign = 1;
			if (last < 0)
			{
				sign = -1;
				last *= -1;
			}
			f[i] = sign * dict[last][pattern[i%l]];
		}

		bool good = true;

		if (f[f.size() - 1] == -1)
		{
			int target = 2;

			for (int i = 0; i < f.size() - 1; ++i)
			{
				if (target > 4)
					break;

				if (f[i] == target)
				{
					target+= 2;
				}
			}

			if (target <= 4)
				good = false;
		}
		else
		{
			good = false;
		}

		if (good)
			outFile << "Case #" << ca << ": " << "YES" << endl;
		else
			outFile << "Case #" << ca << ": " << "NO" << endl;

	}


	inFile.close();
	outFile.close();

	return 0;
}
