#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int T;



	ofstream outfile("D:\\codejam\\2015\\Alarge.txt");
	ifstream infile("D:\\codejam\\2015\\testcase.txt");

	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		int smax;
		int clapped = 0;
		int current_level = 0;
		int additional = 0;
		string s;
		vector<int> levels;

		infile >> smax >> s;
		for (int i = 0; i <= smax; i++)
		{
			levels.push_back(s[i] - '0');
		}


		while ((clapped >= current_level) && (clapped < smax))
		{
			clapped += levels[current_level];
			current_level++;
		}
		current_level--;

		while (clapped < smax)
		{

			while ((levels[current_level] == 0) && (current_level < smax))
			{
				current_level++; additional++;
			}

			clapped = current_level;
			while ((clapped >= current_level) && (clapped < smax))
			{
				clapped += levels[current_level];
				current_level++;
			}
			current_level--;
		}

		outfile << "Case #" << casenum << ": " << additional << endl;


	}

	infile.close();
	outfile.close();

	return 0;
}
