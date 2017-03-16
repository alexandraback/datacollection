#include<cmath>
#include<fstream>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int main()
{
	ifstream fin("A-small-attempt.in");
	ofstream fout("A-small-attempt.out");

	int cases, oldMach, newMach, k, numWin = 0;

	fin >> cases;

	for(int caseN = 1; caseN <= cases; ++caseN) {
		fin >> oldMach >> newMach >> k;
		for(int i = 0; i < oldMach; ++i) {
			for(int j = 0; j < newMach; ++j) {
				if((i & j) < k)
					++numWin;
			}
		}

		fout << "Case #" << caseN << ": " << numWin << '\n';
		numWin = 0;
	}

	return 0;
}
