#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int link(vector<string> &car, int p, char c, int s, vector<bool> &mark) {
	if (p == car.size()) {
		int num = pow(2, s);
		for (int i = 1; i <= s+1; i++) {
			num *= i;
		}
		return num;
	}
	if (c == ' ' || car[p][0] == c) {
		for (int i = 0; i < car[p].size(); i++) {
			char t = car[p][i];
			if (c == ' ' || t == c || mark[t-'a'] == false) {
				mark[t-'a'] = true;
			} else {
				return 0;
			}
		}
		return link(car, p+1, car[p][car[p].size()-1], s, mark);
	} else if (car[p][0] > c) {
		return link(car, p, car[p][0], s+1, mark);
	} else if (car[p][0] < c) {
		for (int i = 0; i < car[p].size(); i++) {
			char t = car[p][i];
			if (mark[t-'a'])
				return 0;
		}
		return link(car, p, car[p][0], s+1, mark);
	}
	return 0;
}

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<string> car(N);
		for (int j = 0; j < N; j++) {
			cin >> car[j];
		}
		sort(car.begin(), car.end());
		cout << "Case #" << i+1 << ": ";
		vector<int> set;
		vector<bool> mark(26, false);
		cout << link(car, 0, ' ', 0, mark) << endl;
	}
	return 0;
}