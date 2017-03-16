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

void populateInput(string& input, vector<string>& in, int i, string& temp)
{
	if(i == input.length())
	{
		in.push_back(temp);
		return;
	}

	if(input[i] != '?')
	{
		temp[i] = input[i];
		populateInput(input, in, i+1, temp);
		return;
	}

	for(char c = '0'; c <= '9'; c++)
	{
		temp[i] = c;
		populateInput(input, in, i+1, temp);
	}

	return;
}

void findResult(vector<string>& in1, vector<string>& in2, string& result1, string& result2, int diff)
{
	for(string s1: in1)
	{
		for(string s2: in2)
		{
			if(abs(stoi(s1) - stoi(s2)) < diff)
			{
				result1 = s1;
				result2 = s2;
				diff = abs(stoi(s1) - stoi(s2));
			}
		}
	}
}

int main(void)
{
	int t;
	string input1, input2;
	string temp;
	vector<string> in1, in2;
	string result1, result2;
	int diff;

	cin >> t;

	for(int i = 1; i <= t; i++)
	{
		in1.clear();
		in2.clear();

		cin >> input1 >> input2;

		temp = input1;
		populateInput(input1, in1, 0, temp);

		temp = input2;
		populateInput(input2, in2, 0, temp);

		result1 = in1[0];
		result2 = in2[0];

		diff = abs(stoi(result1) - stoi(result2));

		findResult(in1, in2, result1, result2, diff);

		cout << "Case #" << i << ": " << result1 << " " << result2 << endl;
	}

	return 0;
}