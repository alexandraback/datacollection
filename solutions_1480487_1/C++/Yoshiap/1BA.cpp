#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main() {
    ofstream fout ("1BA.out");
    ifstream fin ("1BA.in");
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		int N,points[200],sum=0,left;
		priority_queue<pair<int,int> > toprocess;
		fin >> N;
		for (int i = 0; i < N; i++) {
			fin >> points[i];
			sum += points[i];
			toprocess.push(make_pair(-points[i],i));
		}
		double ans[200];
		for (int i = 0; i < N; i++) {
			ans[i] = 0;
		}
		fout.precision(15);
		left = sum;
		set<int> process;
		while (!toprocess.empty()) {
			process.insert(toprocess.top().second);
			int level = -toprocess.top().first;
			toprocess.pop();
			while (!toprocess.empty() && -toprocess.top().first == level) {
				process.insert(toprocess.top().second);
				toprocess.pop();
			}
			int target = toprocess.empty()?999999:-toprocess.top().first;
			int needed = (target-level)*process.size();
			if (needed > left) {
				double percentAdd = ((double)left/process.size())/sum;
				set<int>::iterator it;
				for (it = process.begin(); it != process.end(); it++) {
					ans[*it] += percentAdd;
				}
				break;
			}
			else {
				double percentAdd = (double)(target-level)/sum;
				set<int>::iterator it;
				for (it = process.begin(); it != process.end(); it++) {
					ans[*it] += percentAdd;
				}
				left-=needed;
			}
		}
		fout << "Case #" << t << ":";
		for (int i = 0 ; i < N; i++) {
			fout << " " << ans[i]*100;
		}
		fout << endl;
	}
    return 0;
}