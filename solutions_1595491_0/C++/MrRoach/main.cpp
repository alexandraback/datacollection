#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
int T;
int n,s,p;
const int suprS[] = {-1, -1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
				     5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8,
				     9, 9, 9, 10, 10, 10, -1, -1};
const int normS[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
					 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8,
					 9, 9, 9, 10, 10, 10};

int main(){
	cin >> T;
	for (int times = 0; times < T; ++ times) {
		cin >> n >> s >> p;
		vector<int> scores;
		scores.clear();
		for (int i = 0; i < n; ++ i){
			int score;
			cin >> score;
			scores.push_back(score);
		}
		sort(scores.rbegin(),scores.rend());
		int count = 0;
		int supCount = 0;
		for (int i = 0;i < scores.size();++i){
			if (normS[scores[i]] >= p) {
				++count;
			} else if (suprS[scores[i]] >= p && supCount < s) {
				++supCount;
				++count;
			}
		}
		cout << "Case #" << (times+1) << ": " << count <<endl;
	}	
	return 0;
}