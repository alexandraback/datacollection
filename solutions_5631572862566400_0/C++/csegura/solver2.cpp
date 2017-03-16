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
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <strings.h>
#include <string.h>
using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		cout << "Case #" << (t+1) << ": ";
		int N;
		cin >> N;
		int partner[N+1];
		for (int i = 1; i <= N; i++){
			cin >> partner[i];
		}
		bool solved = false;
		for (int checkSize = N; checkSize >= 2 && (!solved); checkSize--){
			vector<int> selected;
			for (int i = 0; i < N; i++){
				if (i < checkSize){
					selected.push_back(1);
				} else {
					selected.push_back(0);
				}
			}
			sort(selected.begin(), selected.end());
			do {
				vector<int> all;
				for (int i = 0; i < N; i++){
					if (selected[i]){
						all.push_back(i+1);
					}
				}
				sort(all.begin(), all.end());
				do {
					bool ok = true;
					for (int i = 0; i < checkSize; i++){
						if ((partner[all[i]] != all[(i+1) % checkSize]) && (partner[all[i]] != all[(i-1+checkSize) % checkSize])){
							ok = false;
							break;
						}
					}
					if (ok){
						cout << checkSize << endl;
						solved = true;
						break;
					}
				} while(next_permutation(all.begin(), all.end()));
				if (solved){
					break;
				}
			} while(next_permutation(selected.begin(), selected.end()));
		}
		if (!solved){
			cout << "1" << endl;
		}
	}
}
