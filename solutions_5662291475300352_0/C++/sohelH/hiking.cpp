#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

int debug = 0;
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

struct Node {
	double start, speed;
};

vector<Node> vn;
int n;

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		vn.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int d, h, m;
			cin >> d >> h >> m;
			for (int k = m; k < m + h; k++) {
				Node node;
				node.start = d; node.speed = k;
				vn.push_back(node);
			}
		}
		cout << "Case #" << cases << ": ";
		if (vn.size() == 1) {
			cout << 0 << endl;
			continue;
		}

		double t1 = (360 - vn[0].start) / 360.0 * vn[0].speed;
		double t2 = (360 - vn[1].start) / 360.0 * vn[1].speed;

		if (debug) {
			DEBUG(t1);
			DEBUG(t2);
		}

		if (t1 < t2) {
			vn[0].start = 0;
			vn[1].start += t1 / vn[1].speed * 360.0;
		} else {
			vn[1].start = 0;
			vn[0].start += t2 / vn[0].speed * 360;
		}

		if (fabs(t1 - t2) < 1e-9) {
			cout << 0 << endl;
			continue;
		}

		if (fabs(vn[0].start) < 1e-9) {
			swap(vn[0], vn[1]);
		}

		t1 = (360.0 - vn[0].start) / 360.0 * vn[0].speed;
		if (debug) DEBUG(t1);

		double coverOther = t1 / vn[1].speed * 360;

		if (debug) DEBUG(coverOther);

		if (coverOther >= 360.0) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
