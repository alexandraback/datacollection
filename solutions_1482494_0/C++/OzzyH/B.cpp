//#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream cin("B-small.in");
ofstream cout("B-small.out");

int main () {
	int T; cin >> T >> ws;
	for (int t=0; t<T; t++) {
		int N; cin >> N;
		vector <int> a, b, d;
		for (int i=0; i<N; i++) {
			int t; cin >> t;
			a.push_back(t);
			cin >> t;
			b.push_back(t);
			d.push_back(0);
		}
		int cur = 0, mn = 0;
		bool fail = false;
		while(true) {
			bool ok = false;
			for (int j=0; j<N; j++)
				if (b[j]<=cur && d[j]<2) {
					cur += 2-d[j];
					mn++;
					d[j] = 2;
					ok = true;
					break;
				}
			if (ok) continue;
			int mx=-1, mxi=0;
			for (int j=0; j<N; j++)
				if (a[j]<=cur && d[j]==0 && b[j]>mx) {
					mx = b[j];
					mxi = j;
					ok = true;
				}
			if (ok) {
				d[mxi] = 1;
				cur++; mn++;
				continue;
			} else {
				for (int j=0; j<N; j++)
					if (d[j]<2)
						fail = true;
				break;
			}
		}
		cout << "Case #" << t+1 << ": ";
		if (fail) cout << "Too Bad";
		else cout << mn;
		cout << endl;
	}
}
