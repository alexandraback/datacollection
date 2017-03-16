#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	int t;
	input >> t;
	for (int i = 0; i < t; i++)
	{
		bool sleeps = false;
		long long n;
		input >> n;
		output << "Case #" << i+1 << ": ";
		bool has_seen [10] = {};
		for (int k = 1; k < 1001; k++)
		{
			for (long long numb = n*k; numb > 0; numb /= 10)
			{
				has_seen[numb % 10] = true;
			}
			sleeps = true;
			for (int j = 0; j < 10; j++)
			{
				if (has_seen[j] == false)
				{
					sleeps = false;
				}
			}
			if (sleeps)
			{
				output << n*k << endl;
				break;
			}
		}

		if (!sleeps)
		{
			output << "INSOMNIA" << endl;
		}
	}
}