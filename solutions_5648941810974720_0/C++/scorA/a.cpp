#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int d[26] = {0};
		for (int j = 0; j < s.size(); j++) {
			for (int k = 0; k < 26; k++) {
				if (s[j] == abc[k]) {
					d[k]++;
					break;
				}
			}
		}
		vector<int> dd;
		if (d[25] > 0) {
			int kk = d[25];
			for (int j = 0; j < kk; j++) {
				dd.push_back(0);
			}
			d[25] -= kk;
			d[4] -= kk;
			d[17] -= kk;
			d[14] -= kk;
		}
		if (d[22] > 0) {
			int kk = d[22];
			for (int j = 0; j < kk; j++) {
				dd.push_back(2);
			}
			d[19] -= kk;
			d[22] -= kk;
			d[14] -= kk;
		}
		if (d[23] > 0) {
			int kk = d[23];
			for (int j = 0; j < kk; j++) {
				dd.push_back(6);
			}
			d[18] -= kk;
			d[8] -= kk;
			d[23] -= kk;
		}
		if (d[6] > 0) {
			int kk = d[6];
			for (int j = 0; j < kk; j++) {
				dd.push_back(8);
			}
			d[4] -= kk;
			d[8] -= kk;
			d[6] -= kk;
			d[7] -= kk;
			d[19] -= kk;
		}
		if (d[7] > 0) {
			int kk = d[7];
			for (int j = 0; j < kk; j++) {
				dd.push_back(3);
			}
			d[19] -= kk;
			d[7] -= kk;
			d[17] -= kk;
			d[4] -= kk;
			d[4] -= kk;
		}
		if (d[20] > 0) {
			int kk = d[20];
			for (int j = 0; j < kk; j++) {
				dd.push_back(4);
			}
			d[5] -= kk;
			d[14] -= kk;
			d[20] -= kk;
			d[17] -= kk;
		}
		if (d[18] > 0) {
			int kk = d[18];
			for (int j = 0; j < kk; j++) {
				dd.push_back(7);
			}
			d[18] -= kk;
			d[4] -= kk;
			d[21] -= kk;
			d[4] -= kk;
			d[13] -= kk;
		}
		if (d[14] > 0) {
			int kk = d[14];
			for (int j = 0; j < kk; j++) {
				dd.push_back(1);
			}
			d[14] -= kk;
			d[13] -= kk;
			d[4] -= kk;
		}
		if (d[5] > 0) {
			int kk = d[5];
			for (int j = 0; j < kk; j++) {
				dd.push_back(5);
			}
			d[5] -= kk;
			d[8] -= kk;
			d[21] -= kk;
			d[4] -= kk;
		}
		if (d[8] > 0) {
			int kk = d[8];
			for (int j = 0; j < kk; j++) {
				dd.push_back(9);
			}
		}
		sort(dd.begin(), dd.end());
		printf("Case #%d: ", i+1);
		for (int j = 0; j < dd.size(); j++) {
			cout << dd[j];
		}
		cout << endl;
	}
	return 0;
}