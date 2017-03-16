#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <functional>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string c, j;
		cin >> c >> j;
		int sz = c.size();
		queue<string> qc;
		qc.push(c);
		vector<int> qcc;
		string num = "0123456789";
		while (!qc.empty()) {
			string qqc = qc.front();
			qc.pop();
			bool h = true;
			for (int jj = 0; jj < qqc.size(); jj++) {
				if (qqc[jj] == '?') {
					string kqqc = qqc;
					for (int k = 0; k <= 9; k++) {
						kqqc[jj] = num[k];
						qc.push(kqqc);
					}
					h = false;
					break;
				}
			}
			if (h) {
				stringstream ss;
				ss << qqc;
				int kk;
				ss >> kk;
				qcc.push_back(kk);
			}
		}
		queue<string> qj;
		qj.push(j);
		vector<int> qjj;
		while (!qj.empty()) {
			string qqj = qj.front();
			qj.pop();
			bool h = true;
			for (int jj = 0; jj < qqj.size(); jj++) {
				if (qqj[jj] == '?') {
					string kqqj = qqj;
					for (int k = 0; k <= 9; k++) {
						kqqj[jj] = num[k];
						qj.push(kqqj);
					}
					h = false;
					break;
				}
			}
			if (h) {
				stringstream ss;
				ss << qqj;
				int kk;
				ss >> kk;
				qjj.push_back(kk);
			}
		}
		int kc, kj, ks;
		kc = qcc[0];
		kj = qjj[0];
		ks = abs(kc-kj);
		for (int jj = 0; jj < qcc.size(); jj++) {
			for (int kk = 0; kk < qjj.size(); kk++) {
				//cout << qcc[jj] << ' ' << qjj[kk] << endl;
				int kks = abs(qcc[jj]-qjj[kk]);
				if (kks < ks) {
					kc = qcc[jj];
					kj = qjj[kk];
					ks = kks;
				} else if (kks == ks) {
					if (qcc[jj] < kc) {
						kc = qcc[jj];
						kj = qjj[kk];
					} else if (qcc[jj] == kc && qjj[kk] < kj) {
						kj = qjj[kk];
					}
				}
			}
		}
		printf("Case #%d: ", i+1);
		if (sz == 1) {
			cout << kc << ' ' << kj << endl;
		} else if (sz == 2) {
			printf("%02d %02d\n", kc, kj);
		} else if (sz == 3) {
			printf("%03d %03d\n", kc, kj);
		}
	}
	return 0;
}