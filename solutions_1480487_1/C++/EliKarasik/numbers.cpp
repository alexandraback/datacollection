/*
 * Eli Karasik
 * Code Jam Round 1B - question A - numbers
 */


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct contestant {
	int pts;
	int num;
	double prec;
};

bool comparePts(contestant first, contestant second) {
	return first.pts < second.pts;
}

bool compareNum(contestant first, contestant second) {
	return first.num < second.num;
}

void solve () {
	int n;
	cin >> n;
	contestant* contestants = new contestant[n];
	int i,j;
	int sumPts = 0;
	for (i = 0; i < n; i++) {
		cin >> contestants[i].pts;
		sumPts += contestants[i].pts;
		contestants[i].num = i+1;
		contestants[i].prec = 0.0;
	}
	int leftPts = sumPts;
	sort(contestants, contestants+n, comparePts);
	for (i = 1; i < n; i++) {
		int catchUp = contestants[i].pts - contestants[i-1].pts;
		double prec;
		if (catchUp*i > leftPts) {
			prec = (((double)leftPts)/i)/sumPts;
			leftPts = 0;
		} else {
			prec = ((double)catchUp)/sumPts;
			leftPts -= catchUp*i;
		}
		for (j = 0; j < i; j++) {
			contestants[j].prec += prec;
		}
		if (leftPts == 0) {
			break;
		}
	}

	double divide = (((double)leftPts)/n)/sumPts;
	for (i = 0; i < n; i++) {
		contestants[i].prec += divide;
	}

	sort(contestants, contestants+n, compareNum);

	for (i = 0; i < n; i++) {
		cout << " " << contestants[i].prec*100.0;
	}
	
}

int main() {
	int t;
	cin >> t;
	int i;
	cout.precision(10);
	for (i = 1; i <= t; i++) {
		cout << "Case #" << i << ":";
		solve();
		cout  << endl;
	}
}

