#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>

using namespace std;

bool is_palindrome(uint64_t value)
{
	int pos_values[30] = {0};
	int pos = 0;

	while (value != 0)
	{
		pos_values[pos] = value % 10;
		value /= 10;
		pos++;
	}

	bool palin = true;

	for (int i = 0; i < pos-i-1; i++)
	{
		if (pos_values[i] != pos_values[pos-i-1])
		{
			palin = false;
			break;
		}
	}

	return palin;
}

int main()
{
	vector<uint64_t> fair_sqr;

	for (uint64_t i = 1; i <= 10000000; i++)
	{
		if (is_palindrome(i))
		{
			uint64_t temp = i*i;
			if (is_palindrome(temp))
			{
				fair_sqr.push_back(temp);
			}
		}
	}

	ifstream fin;
	ofstream fout;

	fin.open("C-large-1.in");
	fout.open("output.txt");
	int cases;

	fin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int output = 0;
		uint64_t A, B;

		fin >> A >> B;
		for (vector<uint64_t>::iterator it = fair_sqr.begin(); it != fair_sqr.end(); it++)
		{
			if (A <= *it && B >= *it)
			{
				output++;
			}
		}

		fout << "Case #" << i + 1 << ": " << output << endl;
	}

	fin.close();
	fout.close();

	return 0;
}