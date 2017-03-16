#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> database;
vector<int> checkCount(string s)
{
	vector<int> letterCount(26, 0);
	int totalCount = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		letterCount[s[i] - 'A']++;
		totalCount++;
	}
	vector<int> checkCount(10, 0);
	while (totalCount > 0)
	{
		while (letterCount['Z'- 'A'] > 0)
		{
			for (size_t j = 0; j < database[0].size(); j++)
			{
				letterCount[database[0][j] - 'A'] --;
				totalCount--;
			}
			checkCount[0] ++;
		}
		while (letterCount['W' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[2].size(); j++)
			{
				letterCount[database[2][j] - 'A'] --;
				totalCount--;
			}
			checkCount[2]++;
		}
		while (letterCount['X' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[6].size(); j++)
			{
				letterCount[database[6][j] - 'A'] --;
				totalCount--;
			}
			checkCount[6]++;
		}
		while (letterCount['G' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[8].size(); j++)
			{
				letterCount[database[8][j] - 'A'] --;
				totalCount--;
			}
			checkCount[8]++;
		}
		while (letterCount['S' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[7].size(); j++)
			{
				letterCount[database[7][j] - 'A'] --;
				totalCount--;
			}
			checkCount[7]++;
		}
		while (letterCount['V' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[5].size(); j++)
			{
				letterCount[database[5][j] - 'A'] --;
				totalCount--;
			}
			checkCount[5]++;
		}
		while (letterCount['F' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[4].size(); j++)
			{
				letterCount[database[4][j] - 'A'] --;
				totalCount--;
			}
			checkCount[4]++;
		}
		while (letterCount['T' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[3].size(); j++)
			{
				letterCount[database[3][j] - 'A'] --;
				totalCount--;
			}
			checkCount[3]++;
		}
		while (letterCount['O' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[1].size(); j++)
			{
				letterCount[database[1][j] - 'A'] --;
				totalCount--;
			}
			checkCount[1]++;
		}
		while (letterCount['I' - 'A'] > 0)
		{
			for (size_t j = 0; j < database[9].size(); j++)
			{
				letterCount[database[9][j] - 'A'] --;
				totalCount--;
			}
			checkCount[9]++;
		}
	
	}
	return checkCount;
}


int main()
{
	database.push_back("ZERO");
	database.push_back("ONE");
	database.push_back("TWO");
	database.push_back("THREE");
	database.push_back("FOUR");
	database.push_back("FIVE");
	database.push_back("SIX");
	database.push_back("SEVEN");
	database.push_back("EIGHT");
	database.push_back("NINE");
	ifstream fin("A-small-attempt1.in");
	ofstream fout("A-small-attempt1.out");
	int digit;
	int count = 1;
	fin >> digit;
	string s;
	while (fin >> s)
	{
		vector<int> res = checkCount(s);

		fout << "Case #" << count << ": ";
		for (size_t i = 0; i < res.size(); i++)
		{
			//cout << i << " " << res[i] << endl;
			for (size_t j = 0; j < res[i]; j++)
			{
				fout << i;
			}
		}
		fout << endl;
		count++;
	}

	return 0;
}