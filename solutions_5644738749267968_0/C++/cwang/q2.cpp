#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <assert.h>
#include <time.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <bitset>
#include <exception>
#include <memory>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <iterator>
#include <random>
#include <unordered_map>
#include <unordered_set>

#include <cctype>
#include <cstddef>
#include <cstring>
#include <ctime>

#define	SAFE_DELETE(ptr) if(ptr){delete ptr; ptr=NULL;}
#define	SAFE_DELETE_ARRAY(ptr) if(ptr){delete [] ptr; ptr=NULL;}

using namespace std;

int main() 
{
	vector<double> ken_woods;
	vector<double> naomi_woods;

	ifstream fin("datain.txt");
	if (!fin.is_open()) {
		cerr << "Input file not found.\n";
		exit(1);
	}

	ofstream fout("dataout.txt");
	if (!fout.is_open()) {
		cerr << "Output file not found.\n";
		exit(1);
	}

	int T, N, p, war_score, dwar_score;
	double w;
	fin >> T;
	for (int i = 1; i <= T; ++i) {
		fin >> N;
		ken_woods.clear();
		naomi_woods.clear();

		for (int j = 0; j != N; ++j) {
			fin >> w;
			naomi_woods.push_back(w);
		}

		for (int j = 0; j != N; ++j) {
			fin >> w;
			ken_woods.push_back(w);
		}

		sort(ken_woods.begin(), ken_woods.end());
		sort(naomi_woods.begin(), naomi_woods.end());

		war_score = N;
		dwar_score = 0;

		p = 0;
		for (int j = 0; j != N && p <= N; ++j, ++p) {
			while (p != N && naomi_woods[p] < ken_woods[j]) ++p;
			if (p != N) {
				++dwar_score;
			}
		}

		p = 0;
		for (int j = 0; j != N && p <= N; ++j, ++p) {
			while (p != N && ken_woods[p] < naomi_woods[j]) ++p;
			if (p != N) {
				--war_score;
			}
		}

		fout << "Case #" << i << ": " << dwar_score << " " << war_score << endl;
	}

	fin.close();

	return 0;
}