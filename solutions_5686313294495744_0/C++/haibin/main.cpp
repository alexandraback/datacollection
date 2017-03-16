#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");
	int totoalcase;
	int count = 1;
	fin >> totoalcase;
	int num;
	while (fin >> num)
	{
		vector<string> firstword;
		vector<string> secondword;
		string s1, s2;
		for (int i = 0; i < num; i++)
		{
			fin >> s1 >> s2;
			firstword.push_back(s1);
			secondword.push_back(s2);
		}
		int sum = 0;
		for (size_t i = 0; i < firstword.size(); i++)
		{
			bool copyfirst = false;
			bool copyseconde = false;
			for (size_t j = 0; j < firstword.size(); j++)
			{
				if (i != j)
				{
					if (firstword[i] == firstword[j])
					{
						copyfirst = true;
					}
					if (secondword[i] == secondword[j])
					{
						copyseconde = true;
					}
				}
			}
			if (copyfirst && copyseconde)
			{
				sum++;
			}
		}

		fout << "Case #" << count << ": " << sum << endl;;
		count++;
	}
	return 0;
}