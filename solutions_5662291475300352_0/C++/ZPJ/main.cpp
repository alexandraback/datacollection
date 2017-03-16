#include <iostream>
#include <fstream>
using namespace std;

#define cin fin
#define cout fout
int main() {
	ifstream fin("haha.in");
	ofstream fout("output.out");
	int T, a, n, ans;
	cin >> T;
	int p[10];
	double t[10];
	int cnt;
	for (int k = 0; k<T; k++) {
		cin >> n;
		cnt = 0;
		if (n == 1) {
			cin >> p[0] >> a >> t[0];
			if (a == 2) {
				t[1] = t[0] + 1;
				n = 2;
			}
		}
		else
			for (int i = 0; i<n; i++) {
			cin >> p[i] >> a >> t[i];
			}
		if (n>1)
			if (p[0] > p[1]) {
			int temp = p[0]; p[0] = p[1]; p[1] = temp;
			temp = t[0]; t[0] = t[1]; t[1] = temp;
			}
		if (n == 1) ans = 0; else {
			double t0 = (double)((double)(360 - p[0]) / 360.0)*(double)t[0];
			double t1 = (double)((double)(360 - p[1]) / 360.0)*(double)t[1];
			if (t1<t0) {
				if (t1 + t[1]>t0) ans = 0;  else ans = 1;
			}
			if (t0<t1) {
				if (t0 + t[0]>t1) ans = 0; else ans = 1;
			}
			if (t0 == t1) ans = 0;
		}
		cout << "Case #" << k + 1 << ": " << ans << endl;

	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}
