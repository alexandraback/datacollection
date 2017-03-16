#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <assert.h>
#include <functional>
using namespace std;

// 1 0; i 1; j 2; k 3.
int rule[4][4] = 
{
	{ 0, 1, 2, 3 },
	{ 1, 0, 3, 2 },
	{ 2, 3, 0, 1 },
	{ 3, 2, 1, 0 }
};

int sign[4][4] = 
{
	{ 1, 1, 1, 1 },
	{ 1, -1, 1, -1 },
	{ 1, -1, -1, 1 },
	{ 1, 1, -1, -1 }
};

bool check(string &vals)
{
	int size = vals.size();
	if (size <= 1)
		return false;

	char t = vals[0];
	for (int i = 1; i < size; ++i)
	{
		if (vals[i] != t)
			return true;
	}
	return false;
}

static long long first_i_left = 0;
static long long first_k_right = 0;

bool checkLeft(string &inputvals, long long int repeat)
{
	int loop = repeat > 4 ? 4 : repeat;
	string vals;
	for (int i = 0; i < loop; ++i)
		vals += inputvals;

	int size = vals.size();
	int midResult = vals[0];
	int flag = 1;
	if (flag == 1 && midResult == 1)
	{
		first_i_left = 0;
		return true;
	}
		
	for (int j = 1; j < size; ++j)
	{
		flag *= sign[midResult][vals[j]];
		midResult = rule[midResult][vals[j]];
		if (flag == 1 && midResult == 1)
		{
			first_i_left = j;
			return true;
		}
	}
	return false;
}

bool checkRight(string &inputvals, long long int repeat)
{
	int loop = repeat > 4 ? 4 : repeat;
	string vals;
	for (int i = 0; i < loop; ++i)
		vals += inputvals;

	int size = vals.size();
	int midResult = vals[size - 1];
	int flag = 1;
	if (flag == 1 && midResult == 3)
	{
		first_k_right = repeat * (long long)inputvals.size() - (long long)1;
		return true;
	}
		
	for (int j = size - 2; j >= 0; --j)
	{
		flag *= sign[vals[j]][midResult];
		midResult = rule[vals[j]][midResult];
		if (flag == 1 && midResult == 3)
		{
			first_k_right = repeat * (long long)inputvals.size() - (long long)(size - j);
			return true;
		}
	}
	return false;
}

inline void changeValue(string &vals)
{
	int reduce = 'i' - 1;
	size_t size = vals.size();
	for (int i = 0; i < size; ++i)
	{
		vals[i] -= reduce;
	}
}

int main()
{
	ifstream file;
	ofstream output;
	file.open("data.in");
	output.open("data.out");
	int T;
	file >> T;
	for (int i = 1; i <= T; ++i)
	{
		int size;
		long long int repeat;
		file >> size >> repeat;

		string str;
		str.reserve(size);
		file >> str;
		changeValue(str);

		int midResult = str[0];
		int flag = 1;
		for (int j = 1; j < size; ++j)
		{
			flag *= sign[midResult][str[j]];
			midResult = rule[midResult][str[j]];
		}
		
		int usefulRepeat = (int)(repeat & 3);

		bool result = true;
		if (usefulRepeat == 0)
			result = false;
		else
		{
			int final = 0;
			int finalFlag = 1;
			for (int j = 0; j < usefulRepeat; ++j)
			{
				finalFlag *= flag;
				finalFlag *= sign[final][midResult];
				final = rule[final][midResult];
			}
			if (final != 0 || finalFlag != -1)
				result = false;
		}

		if (result)
		{
			if (!check(str))
				result = false;
			else if (!checkLeft(str, repeat))
				result = false;
			else if (!checkRight(str, repeat))
				result = false;
			else if (first_i_left >= first_k_right - 1)
				result = false;
		}

		string outputStr = result ? "YES" : "NO";
		output << "Case #" << i << ": " << outputStr;
		if (i != T)
			output << endl;
	}
	file.close();
	output.close();
	return 0;
}