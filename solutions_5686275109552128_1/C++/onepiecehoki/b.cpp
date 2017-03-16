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

int main(){
		int T;
	cin >> T;
	
	for (int t=1; t <= T; ++t){
		int D;
		cin >> D;
		vector<int> P(D);
		for (int i=0; i < D; ++i){
			cin >> P[i];
		}
		
		int minTime = 10000;
		for(int maxRemainder = 1; maxRemainder <= 1000; ++maxRemainder){
			//We divide each P so that it become less or equal to maxRemainder
			int numMove = 0;
			for (int i=0; i < P.size(); ++i){
				numMove += (P[i]-1)/maxRemainder;
			}
			int totalTime = numMove + maxRemainder;
			if (totalTime < minTime) minTime = totalTime;
		}

		cout << "Case #" << t << ": ";
		cout << minTime << endl;
	}
	return 0;
}