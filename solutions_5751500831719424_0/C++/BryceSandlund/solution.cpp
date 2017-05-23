//============================================================================
// Name        :
// Author      : Bryce Sandlund
// Version     :
// Copyright   :
// Description : Google Code Jam Code
//============================================================================

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <list>
#include <map>
#include <fstream>
#include <string>
#include <time.h>
#include <queue>
#include <tuple>
#include <functional>
//#include <unordered_set>
//#include <unordered_map>
//#include <ctgmath>

#define INF 1000000000000000000LL

using namespace std;

typedef pair<int, pair<int, int> > iii;

int main() {
	ofstream out;
	ifstream in("in.in");
	out.open("out.out");
	int T;
	in >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		int N;
		in >> N;
		vector<vector<pair<char, int> > > words(N, vector<pair<char, int> >());

		bool failed = false;
		for (int i = 0; i < N; ++i)
		{
			string s;
			in >> s;
			for (int j = 0; j < s.size(); ++j)
			{
				char c = s[j];
				if (j > 0 && c == words[i][words[i].size()-1].first)
				{
					++words[i][words[i].size()-1].second;
				}
				else
				{
					words[i].push_back(make_pair(c, 1));
				}
			}
		}

		int size = words[0].size();
		for (int i = 1; i < N; ++i)
		{
			if (words[i].size() != size)
			{
				failed = true;
			}
			else
			{
				for (int j = 0; j < size; ++j)
				{
					if (words[i][j].first != words[0][j].first)
					{
						failed = true;
					}
				}
			}
		}

		if (failed)
		{
			out << "Case #" << caseNum << ": Fegla Won" << endl;
		}
		else
		{
			long long cost = 0;
			for (int i = 0; i < words[0].size(); ++i)
			{
				vector<int> counts(N);

				for (int j = 0; j < N; ++j)
				{
					counts[j] = words[j][i].second;
				}

				sort(counts.begin(), counts.end());

				int med = counts[N/2];

				for (int j = 0; j < N; ++j)
				{
					cost += abs(med - counts[j]);
				}
			}

			out << "Case #" << caseNum << ": " << cost << endl;
		}
	}
	out.close();
	return 0;
}
