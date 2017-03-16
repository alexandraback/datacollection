#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int testCases;
	cin >> testCases;
	for (int count = 0; count < testCases; count++) {
		int numCont;
		cin >> numCont;
		vector<int> scores;
		int total=0;
		for (int i = 0; i < numCont; i++) {
			int score;
			cin >> score;
			total += score;
			scores.push_back(score);
		}
		printf("Case #%d:", (count + 1));
		vector<int> scoresOrig = scores;
		for (int i = 0; i < numCont; i++) {
			int k = i;
			scores = scoresOrig;
			while(true) {
				double average= 0;
				int max=0;
				int maxindex=0;
				for (int j = 0; j < scores.size(); j++) {
					if (k==j) continue;
					average += scores[j];
					if (scores[j] >= max) {
						max = scores[j];
						maxindex = j;
					}
				}
				average = average/(scores.size() - 1);
				int score = scores[k];
				double prop = (double) total/(scores.size() - 1) + average - score;
				prop = prop/(1 + 1/((double) scores.size() -1));
				prop = prop / total;
				if (prop < 0) prop = 0;
				double test = (1 - prop)/(scores.size() - 1) * total + average;
				if (test < max) {
					if (k > maxindex) k--;
					scores.erase(scores.begin() + maxindex);
					continue;
				}
				prop = prop * 100;
				printf(" %f", prop);
				break;
			}
		}
		printf("\n");
	}
	return 0;	
}

