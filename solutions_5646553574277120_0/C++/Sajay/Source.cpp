#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <math.h>

using namespace std;

bool ascending(int *i, int *j) { return (i[0]<j[0]); }

void main()
{
	ifstream input;
	input.open("C-small-attempt2.in");

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

		int c, d, v;
		input >> c >> d >> v;

		vector<int> den;
		vector<int> need;

		for (int k = 0; k < d; k++)
		{
			int temp;
			input >> temp;
			den.push_back(temp);
		}

		int dec = 0;

		if (v>10 && v<=20)
		{
			dec=1;
			v = 10;
		}

		if (v>20 && v<30)
		{
			dec=2;
			v = 10;
		}

		int x = 1;
		while (1)
		{
			need.push_back(x);
			int sum = std::accumulate(need.begin(), need.end(), 0);
			if (sum >= v)
				break;
			x++;
		}

		if (dec >= 1)
			need.push_back(10);
		if (dec >= 2)
			need.push_back(20);

		int count = 0;
		for (int i = 0; i < need.size(); i++)
		{
			for (int j = 0; j < den.size(); j++)
			{
				if (need[i] == den[j])
				{
					count++;
					break;
				}
			}
		}
		
		int ans = need.size() - count;
		output << ans << '\n';
	}

	output.close();
	input.close();
}