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
		int maxSizeToPair[N + 1];
		bool paired[N+1];
		for (int i = 1; i <= N; i++){
			paired[i] = false;
			maxSizeToPair[i] = 0;
		}
		vector< pair<int, int> > pairs;
		for (int i = 1; i <= N; i++){
			if ((partner[i] > i) && (partner[partner[i]] == i)){
				pairs.push_back(make_pair(i, partner[i]));
				paired[i] = true;
				paired[partner[i]] = true;
			}
		}
		int solution = 0;
		for (int start = 1; start <= N; start++){
			if (paired[start]){
				continue;
			}
			int used[N+1];
			for (int i = 1; i <= N; i++){
				used[i] = 0;
			}
			used[start] = 1;
			int current = start;
			int next = 2;
			while(used[partner[current]] == 0){
				used[partner[current]] = next++;
				current = partner[current];
				if (paired[current]){
					maxSizeToPair[current] = max(maxSizeToPair[current], next - 2);	
					break;
				}
			}
			if (used[partner[current]] == 1){
				solution = max(solution, next - 1);
			}
		}
		int solution2 = 0;
		for (int i = 1; i <= N; i++){
			if (paired[i]){
				solution2 += (1 + maxSizeToPair[i]);
			}
		}
		cout << max(solution, solution2) << endl;
	}
}
