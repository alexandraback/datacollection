#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <deque>
#include <cstdlib>

using namespace std;

vector<int> mote;
vector<int> step;
int initMote;
int n;
int T;

int main() {
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> initMote >> n;
		mote.clear();
		step.clear();
		for (int i = 0; i < n; ++i) {
			int tmpMote = 0;
			cin >> tmpMote;
			mote.push_back(tmpMote);
			step.push_back(1000000);
		}
		sort(mote.begin(), mote.end());
		int cmote = initMote;
		int cnt = 0;
		if (cmote != 1) {
			for (int i = 0; i < n; ++i) {
				while (cmote <= mote[i]) {
					cmote = cmote * 2 - 1;
					cnt ++;
				}
				step[i] = cnt;
				cmote += mote[i];
			}
		}
		int minStep = n;
		for (int i = 0; i < n; ++i) {
			if (step[i] + (n - i - 1) < minStep) {
				minStep = step[i] + n - i - 1;
			}
		}
		cout <<"Case #" << caseNum + 1 << ": " << minStep << endl;
		
	}
	return 0;
}