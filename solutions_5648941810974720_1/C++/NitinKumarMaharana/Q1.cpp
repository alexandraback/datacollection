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

void findSingleDigit(string& input, string& result)
{
	size_t index;

	index = input.find('Z');

	while(index != string::npos)
	{
		result += '0';

		input.erase(index, 1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('R');
		input.erase(index,1);

		index = input.find('O');
		input.erase(index,1);

		index = input.find('Z');
	}

	index = input.find('W');

	while(index != string::npos)
	{
		result += '2';

		input.erase(index, 1);

		index = input.find('T');
		input.erase(index,1);

		index = input.find('O');
		input.erase(index,1);

		index = input.find('W');
	}

	index = input.find('X');

	while(index != string::npos)
	{
		result += '6';

		input.erase(index, 1);

		index = input.find('S');
		input.erase(index,1);

		index = input.find('I');
		input.erase(index,1);

		index = input.find('X');
	}

	index = input.find('U');

	while(index != string::npos)
	{
		result += '4';

		input.erase(index, 1);

		index = input.find('F');
		input.erase(index,1);

		index = input.find('O');
		input.erase(index,1);

		index = input.find('R');
		input.erase(index,1);

		index = input.find('U');
	}

	index = input.find('G');

	while(index != string::npos)
	{
		result += '8';

		input.erase(index, 1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('I');
		input.erase(index,1);

		index = input.find('H');
		input.erase(index,1);

		index = input.find('T');
		input.erase(index,1);

		index = input.find('G');
	}

	index = input.find('O');

	while(index != string::npos)
	{
		result += '1';

		input.erase(index, 1);
		
		index = input.find('N');
		input.erase(index,1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('O');
	}

	index = input.find('T');

	while(index != string::npos)
	{
		result += '3';

		input.erase(index, 1);

		index = input.find('H');
		input.erase(index,1);

		index = input.find('R');
		input.erase(index,1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('T');
	}

	index = input.find('F');

	while(index != string::npos)
	{
		result += '5';

		input.erase(index, 1);

		index = input.find('I');
		input.erase(index,1);

		index = input.find('V');
		input.erase(index,1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('F');
	}

	index = input.find('V');

	while(index != string::npos)
	{
		result += '7';

		input.erase(index, 1);

		index = input.find('S');
		input.erase(index,1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('N');
		input.erase(index,1);

		index = input.find('V');
	}

	index = input.find('N');

	while(index != string::npos)
	{
		result += '9';

		input.erase(index, 1);

		index = input.find('I');
		input.erase(index,1);

		index = input.find('E');
		input.erase(index,1);

		index = input.find('N');
		input.erase(index,1);

		index = input.find('N');
	}
}

int main(void)
{
	int t;
	string input, result;

	cin >> t;

	for(int i = 1; i <= t; i++)
	{
		result = "";

		cin >> input;

		findSingleDigit(input, result);

		sort(result.begin(), result.end());

		cout << "Case #" << i << ": " << result << endl;
	}

	return 0;
}