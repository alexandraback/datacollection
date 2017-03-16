#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>

using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		int D;
		cin >> D;
		int plates[D];
		for (int i = 0; i < D; i++){
			cin >> plates[i];
		}
		int notOk = 0, ok = 1000;
		while(notOk + 1 != ok){
			int testMin = (ok + notOk) / 2;
			bool found = false;
			for (int eat = 1; eat <= testMin; eat++){
				int sep = testMin - eat;
				int requiredSep = 0;
				for (int i = 0; i < D; i++){
					requiredSep += ((plates[i] - 1) / eat);
					if (requiredSep > sep)
						break;
				}
				if (requiredSep <= sep){
					found = true;
					break;
				}
			}
			if (found){
				ok = testMin;
			} else {
				notOk = testMin;
			}
		}
		cout << "Case #" << t + 1 << ": " << ok << endl;
	}
}
