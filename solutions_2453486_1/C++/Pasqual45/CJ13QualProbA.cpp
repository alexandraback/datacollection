#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

//int main13QA()
int main()
{
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	vector<string> base(4), b;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		bool finished = true;
		for (int i=0; i<4; ++i)
		{
			fin >> base[i];
			if (base[i].find('.') != string::npos)
				finished = false;
		}

		char cc[2] = {'X', 'O'};
		bool win[2] = {false, false};
		for (int z=0; z<2; ++z)
		{
			char c = cc[z];
			string target(4, c);

			b = base;
			for (int i=0; i<4; ++i)
				for (int j=0; j<4; ++j)
					if (b[i][j] == 'T')
						b[i][j] = c;

			b.push_back(b[0].substr(0, 1) + b[1][1] + b[2][2] + b[3][3]);
			b.push_back(b[0].substr(3, 1) + b[1][2] + b[2][1] + b[3][0]);

			for (int i=0; i<4; ++i)
				b.push_back(b[0].substr(i, 1) + b[1][i] + b[2][i] + b[3][i]);

			if (find(b.begin(), b.end(), target) != b.end())
				win[z] = true;
		}

		string result;
		if (win[0])
			result = "X won";
		else if (win[1])
			result = "O won";
		else if (finished)
			result = "Draw";
		else
			result = "Game has not completed";

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}