#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void fillv(vector<bool> &vpos, vector<int> &vd, int c, int pos, int sum) {
	if (pos == vd.size()) {
		vpos[sum] = true;
		return;
	}
	for (int i = 0; i < c+1; ++i) {
		fillv(vpos, vd, c, pos+1, sum+vd[pos]*i);
	}
}

int canfill(int v, int c, vector<int> &vd) {
	vector<bool> vpos(v+1);
	fillv(vpos, vd, c,  0, 0);
	int mispos = -1;
	bool start = true;
	int res = 0;
	while(mispos != -1 or start) {
		start = false;
		mispos = -1;
		for(int i = 0; i < vpos.size() && mispos == -1; ++i) {
			if (not vpos[i]) {
				vd.push_back(i);
				++res;
				mispos = i;
			}
		}
		fillv(vpos, vd, c,  0, 0);
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	for (int cas = 1; cas < t+1; ++cas) {
		int c,d,v;
		cin >> c >> d >> v;
		vector<int> vd(d);
		for (int i = 0; i < d; ++i) {
			cin >> vd[i];
		}
		cout << "Case #" << cas << ": " << canfill(v, c, vd) << endl;
	}
}