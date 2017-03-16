#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

const string outPrefix = "Case #";

int main(){
	int T;
	cin >> T;
	
	for (int t=1; t <= T; ++t){
		int Smax;
		cin >> Smax;
		string S;
		cin >> S;
		
		vector<int> sum(S.size()+1);
		sum[0] = S[0] - '0';
		for (int i=1; i < S.size(); ++i){
			sum[i] = sum[i-1] + S[i] - '0';
		}
		
		int maxNeeded = 0;
		for (int i=1; i < S.size(); ++i){
			int curNeeded = i - sum[i-1];
			if (curNeeded > maxNeeded) maxNeeded = curNeeded;
			if (sum[i] > 9) break;
		}
		
		cout << outPrefix << t << ": " << maxNeeded << endl;
	}
	
	return 0;
}
