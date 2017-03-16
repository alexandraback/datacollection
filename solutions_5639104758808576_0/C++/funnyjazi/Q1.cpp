#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int t = 0;
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	if (fin.good())
	{
		fin >> t;
		for (size_t i = 0; i < t; i++)
		{
			int fr = 0;
			int count = 0;
			int smax = 0;
			string s = "";
			fin >> smax;
			fin >> s;

			for (size_t j = 0;  j < smax+1;  j++)
			{
				if (s[j] != '0')
				{
					if (count < j)
					{
						fr += j - count;
						count += (s[j] - '0') + (j - count);
					}
					else
						count += s[j] - '0';
					
				}
			}

			fout << "Case #" << i + 1 << ": " << fr << endl;

		}
		fin.close();
		fout.close();
	}

	return 0;
}