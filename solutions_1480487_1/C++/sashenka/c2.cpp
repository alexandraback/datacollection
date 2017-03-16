#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<string>
#include<set>
#include <algorithm>

using namespace std;

int main() {
	ifstream inp;
	ofstream out;
	inp.open("input.txt");
	out.open("output.txt");
	int t;
	inp >> t;
	for (int test = 0; test < t; ++test) {
		cout << test;
		int n;
		inp >> n;
		vector<double> judgeScore;
		double judgeSum = 0;
		for (int i = 0; i < n; ++i) {
			double score;
			inp >> score;
			judgeScore.push_back(score);
			judgeSum += score;
		}
		vector<double> judgeScoreOld = judgeScore;
		sort (judgeScore.begin(), judgeScore.end());
		double volume = 0;
		int i = 0;
		while (volume < judgeSum && i < n - 1){
			volume += (judgeScore[i + 1] - judgeScore[i]) * (i + 1);
			++i;
		}
		double level = 0;
		if (volume > judgeSum) {
			double diff = (volume - judgeSum) / i;
			level = judgeScore[i] - diff;
		} else {
			double diff = (judgeSum - volume) / n;
			level = judgeScore[n - 1] + diff;	
		}
		out << "Case #" << test + 1 << ": ";
		for (int i = 0; i < n; ++i) {
			double res = 0;
			if (judgeScoreOld[i] < level) {
				res = (level - judgeScoreOld[i]) * 100 / judgeSum;
			}
			out << res << " ";
		}		
		out << endl;
	}
	return 0;
}