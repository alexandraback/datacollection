/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int t, n;
	string input1, input2;
	unordered_map<string, int> first, second;
	vector<string> in1, in2;
	int result;	

	cin >> t;

	for(int i = 1; i <= t; i++)
	{
		in1.clear();
		in2.clear();
		first.clear();
		second.clear();
		result = 0;

		cin >> n;

		for(int j = 0; j < n; j++)
		{
			cin >> input1 >> input2;

			in1.push_back(input1);
			in2.push_back(input2);

			if(first.find(input1) != first.end())
				first[input1]++;
			else
				first[input1] = 0;

			if(second.find(input2) != second.end())
				second[input2]++;
			else
				second[input2] = 0;
		}

		for(int j = 0; j < n; j++)
		{
			input1 = in1[j];
			input2 = in2[j];

			if(first[input1] > 0 && second[input2] > 0)
			{
				result++;
				first[input1]--;
				second[input2]--;
			}	
		}

		cout << "Case #" << i << ": " << result << endl;
	}

	return 0;
}