#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int a, vector<int> motes) {
	sort(motes.begin(), motes.end());
	int minr = motes.size();
	int cntr = 0;
	int i;
	for(i = 0; i < motes.size(); i++) {
		if(motes[i] < a) {
			a += motes[i];
			continue;
		}
		if(cntr + motes.size() - i < minr) {
			minr = cntr + motes.size() - i;
		}
		if (cntr + 1 >= minr) {
			break;
		}
		if (a == 1) {
			break;
		}
		while(motes[i] >= a) {
			cntr += 1;
			a += a - 1;
		} 
		a += motes[i];
	}
	return i == motes.size() ? min(cntr, minr) : minr;
}

void input(int &a, vector<int> &motes) {
	int n;
	cin >> a >> n;
	motes.resize(n);
	for(int i = 0; i < n; i++)
		cin >> motes[i];
}

void output(int t, int res) {
	printf("Case #%d: %d\n", t + 1, res);
}

int main() {
	int t, a, r;
	vector<int> motes;
	cin >> t;
	for(int i = 0; i < t; i++) {
		input(a, motes);
		r = solve(a, motes);
		output(i, r);
	}
	return 0;
}