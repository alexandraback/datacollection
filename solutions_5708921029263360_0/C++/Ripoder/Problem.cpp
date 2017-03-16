//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

pair<int, string> greedyAlg(vector<vector<int> > JP, vector<vector<int> > JS, vector<vector<int> > PS,
		int J, int P, int S, int K)
		{
			int count = 0;
			string answer;

			for(int j = 0; j < J; ++j)
				for (int p = 0; p < P; ++p)
					for (int s = 0; s < S; ++s)
					{
						if (JP[j][p]<K&&JS[j][s]<K&&PS[p][s]<K)
						{
							++count;
							++JP[j][p];
							++JS[j][s];
							++PS[p][s];
							answer+='\n';
							answer+=(char)('0'+j+1);
							answer+=' ';
							answer+=(char)('0'+p+1);
							answer+=' ';
							answer+=(char)('0'+s+1);
						}
					}
			return std::make_pair(count, answer);
		}

pair<int, string> block(vector<vector<int> > & JP, vector<vector<int> > & JS, vector<vector<int> > & PS,
		int J, int P, int S, int K)
		{
			pair<int, string> ans;ans.first = 0;
			vector<vector<int> > tJP = JP;
			vector<vector<int> > tJS = JP;
			vector<vector<int> > tPS = PS;

			bool hit = false;

			for (int j = 0; j < J && !hit; ++j)
				for (int p = 0; p < P && !hit; ++p)
					if(JP[j][p] == 0)
					{
						vector<vector<int> > mJP = JP;
						mJP[j][p] = K;
						pair<int, string> tans = greedyAlg(mJP,JS,PS,J,P,S,K);
						if (tans.first > ans.first)
							ans = tans, tJP = mJP,
							tJS = JS, tPS = PS;

						hit = true;
					}

			for (int j = 0; j < J && !hit; ++j)
							for (int s = 0; s < S && !hit; ++s)
								if(JS[j][s] == 0)
								{
									vector<vector<int> > mJS = JS;
									mJS[j][s] = K;
									pair<int, string> tans = greedyAlg(JP,mJS,PS,J,P,S,K);
									if (tans.first > ans.first)
										ans = tans, tJS = mJS,
										tJP = JP, tPS = PS;

									hit = true;
								}

			for (int p = 0; p < P && !hit; ++p)
							for (int s = 0; s < S && !hit; ++s)
								if(PS[p][s] == 0)
								{
									vector<vector<int> > mPS = PS;
									mPS[p][s] = K;
									pair<int, string> tans = greedyAlg(JP,JS,mPS,J,P,S,K);
									if (tans.first > ans.first)
										ans = tans, tPS = mPS,
										tJP = JP, tJS = JS;

									hit = true;
								}

			return ans;
		}

int main()
{
	// open a file in read mode.
	ifstream infile;
//	infile.open("src/in");
	infile.open("src/C-small-attempt1.in");
//	infile.open("src/A-large.in");

	// open a file in write mode.
	ofstream outfile;
	outfile.open("src/out");

	int T;
	infile>>T;
	for (int i = 1; i <= T; ++i)
	{
		size_t J,P,S,K;
		infile>>J>>P>>S>>K;
		outfile<<"Case #"<<i<<": ";


		//set<int[3]> usedOutfits;

		vector<vector<int> > bestJP(J, vector<int>(P, 0));
		vector<vector<int> > bestJS(J, vector<int>(S, 0));
		vector<vector<int> > bestPS(P, vector<int>(S, 0));

		pair<int, string> ans = greedyAlg(bestJP, bestJS, bestPS, J, P, S, K);
		pair<int, string> tans;
		int bestCount = 0;

		for (tans = block(bestJP, bestJS, bestPS, J, P, S, K);ans.first < tans.first;)
			ans = tans,
			tans = block(bestJP, bestJS, bestPS, J, P, S, K);

		outfile<<ans.first<<ans.second<<endl;
	}
	outfile.close();
	return 0;
}
