#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


int num(string &s, int i)
{
	int t = i + 1;
	while (t < s.size())
	{
		if (s[i] == s[t])
			++t;
		else
			break;
	}
	return t - i;
}

int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");

	int cases;
	fin >> cases;
	fin.ignore(1);

	for (int cas = 1; cas <= cases; cas++)
	{
		int N;
		fin >> N;
		vector<string> s;
		s.resize(N);
		for (int i = 0; i < N; i++)
			fin >> s[i];

		int succeed = 0;
		int cal = 0;
		int i1 = 0;
		int i2 = 0;
		while (true)
		{
			if (s[0][i1] == s[1][i2])
			{
				int c1 = num(s[0], i1);
				int c2 = num(s[1], i2);
				if (c1 - c2 > 0)
					cal += (c1 - c2);
				else
					cal += (c2 - c1);
				i1 += c1;
				i2 += c2;
				if (i1 == s[0].size())
				{
					if (i2 == s[1].size())
						succeed = 1;
					break;
				}
				if (i2 == s[1].size())
				{
					if (i1 == s[0].size())
						succeed = 1;
					break;
				}
			}
			else
				break;
		}

		fout << "Case #" << cas << ": ";
		if (succeed == 1)
			fout << cal;
		else
			fout << "Fegla Won";
		fout << "\n";
	}
	return 0;
}