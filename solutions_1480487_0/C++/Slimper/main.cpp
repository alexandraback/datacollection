#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;


vector<double> SolveTestCase() {
	int n;
	cin >> n;
	int sum = 0;
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	vector<int> s1 = s;
	sort(s1.begin(), s1.end());
	vector<double> ans(n);
	int k = 0;
	int cumsum = 0;
	for (k; k < n; k++) {
		cumsum += s1[k];
		if (cumsum + sum <= (k + 1) * s1[k]) break;
	}
	if (k < n)
		cumsum -= s1[k];
	for (int i = 0; i < n; i++) {
		ans[i] = max(0.0, 100.0 * ((cumsum + sum)/ (double) k - s[i]) / sum);
	}

	/*
	int newSum = 2 * sum;
	for (int i = 0; i < n; i++) {
		if (s[i] * n >= 2 * sum) {
			ans[i] = 0;
			newSum -= s[i];
		}
	}

	double ansSum = 0.0;
	for (int i = 0; i < n; i++) {
		if (s[i] * n >= 2 * sum) continue;
		ans[i] = (newSum / (double) n - s[i]) / sum;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			ans[i] = min(ans[i], 50 * (s[j] - s[i]) / (double) sum + 50);
		}
		ans[i] = max(ans[i], 0.0);
		ansSum += ans[i]; 
	}
	for (int i = 0; i < n; i++) {
		ans[i] = 100.0 * ans[i] / ansSum;
	}*/
	return ans;
}

template <class T> 
void PrintAnswerToTestCase(T ans, int testCase) {
	cout << "Case #" << testCase << ": ";
	for (int i = 0; i < ans.size() - 1; i++) {
		cout.precision(12);
		cout << ans[i] << " ";
	}
	cout << ans.back() << endl;
}

int main() {

	//freopen("input.txt", "r", stdin);
	freopen("small.in", "r", stdin);
	//freopen("large.in", "r", stdin);
	
	freopen("output.txt", "w", stdout);
	
	int numCases;
	cin >> numCases;

	for (int testCase = 1; testCase <= numCases; testCase++) {
		cerr << "Case #" << testCase << endl;
		PrintAnswerToTestCase(SolveTestCase(), testCase);
	}
	return 0;
}