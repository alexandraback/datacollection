#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>    // std::sort

using namespace std;

int main () {
	int numTestCases;
	cin >> numTestCases;
	for (int testCase=0; testCase<numTestCases; ++testCase) {
		int C, D, V, largestCurrency;
		largestCurrency = 0;
		cin >> C >> D >> V;
		vector<int> currencies;
		for (int j=0; j<D; ++j) {
			int temp;
			cin >> temp;
			currencies.push_back(temp);
			largestCurrency = max(largestCurrency, temp);

		}
		vector< vector< vector<int> > > dp(V+1, vector< vector<int> >(0, vector<int>(D, 0)));
		for (int i=1; i<=V; ++i) {
			// can we make a purchase of value V.
			//cout << "i" << i << endl;
			int found = -1;
			if (i <= largestCurrency) {
				// maybe we can build it directly:				
				for (int j=0; j<currencies.size(); ++j) {
					if (i == currencies[j]) {
						// found it.
						found = j;
						break;
					}
				}
			}
			if (found >= 0) {
				dp[i].push_back(vector<int>(currencies.size(), 0));
				dp[i][dp[i].size() - 1][found]++;
			} else {
				// could not build it directly try to build it with some other currency:
				for (int j=0; j<currencies.size(); ++j) {
					//cout << "j" << j << endl;
					int position = i - currencies[j];
					if (position < 0) {
						break;
					}
					// which of the vectors would be valid to copy over?

					for (int k = 0; k< dp[position].size(); ++ k) {
						if (dp[position][k].size() < j || dp[position][k][j] < C) {
							found = 0;
							// valid. copy:	
							//cout << "k" << k << endl;
							dp[i].push_back(vector<int>(currencies.size(), 0));
							//cout << "k" << k << endl;
							//cout << "k" << k << endl;
							//cout << "dp[i]" << dp[i].size() << endl;
							//cout << "temp" << temp.size() << endl;
							//dp[i].push_back(temp);
							for (int l=0; l<dp[position][k].size(); ++l) {
								dp[i][dp[i].size() -1][l] = dp[position][k][l];
							}

							dp[i][dp[i].size() -1][j]++;
							//cout << "dp[i]" << dp[i].size() << endl;
							
						}
					}
				}

				if (found == -1) {
					// we need a new currency.
					currencies.push_back(i);
					sort(currencies.begin(), currencies.end());
					//cout << i << endl;
					dp[i].push_back(vector<int>(currencies.size(), 0));
					found = 0;
					for (int k=0; k<currencies.size(); ++k) {
						if (currencies[k] == i) {
							found = k;
							break;
						}
					} 
					dp[i][dp[i].size() - 1][found]++;
				}

			}


		}

		// if (testCase == 3) {
		// 	for (auto v : dp[2]) {
		// 		cout << "v" << endl;
		// 		for (int i:v) {
		// 			cout << " " << i;
		// 		}
		// 		cout << endl;
		// 	}
		// }
		cout << "Case #" << (testCase+1) << ": " << (currencies.size()-D) << endl; 
	}
}
