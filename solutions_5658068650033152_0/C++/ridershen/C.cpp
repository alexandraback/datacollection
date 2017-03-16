#include <iostream>

using namespace std;

int main()
{
	freopen("E:\\Projects\\VS2010\\gcj2014\\gcj2014\\Round1C\\C\\C-small-attempt0.in", "r", stdin);
	freopen("E:\\Projects\\VS2010\\gcj2014\\gcj2014\\Round1C\\C\\C.out", "w", stdout);
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";

		int n, m, k;
		cin >> n >> m >> k;

		if (n < 3 || m < 3) {
			cout << k << endl;
			continue;
		}

		if (n==3 && m==3) {
			cout << k-1 << endl;
			continue;
		}
		if ( n == 3 || m == 3) {
			if (k < 5) {
				cout << k << endl;
				continue;
			}
			if (k < 8) {
				cout << k-1 << endl;
				continue;
			}
			if (k < 11) {
				cout << k-2 << endl;
				continue;
			}
			if (k < 14) {
				cout << k-3 << endl;
				continue;
			}
			cout << k-4 << endl;
			continue;
		}
		
		if (n==4 && m==4) {
			if (k < 5) {
				cout << k << endl;
				continue;
			}
			if (k<8) {
				cout << k-1 << endl;
				continue;
			}
			if (k < 10) {
				cout << k-2 << endl;
				continue;
			}
			if (k < 12) {
				cout << k-3 << endl;
				continue;
			}
			cout << k-4 << endl;
			continue;
		}
		
		if (n==4 || m==4) {
			if (k < 5) {
				cout << k << endl;
				continue;
			}
			if (k<8) {
				cout << k-1 << endl;
				continue;
			}
			if (k < 10) {
				cout << k-2 << endl;
				continue;
			}
			if (k < 12) {
				cout << k-3 << endl;
				continue;
			}	
			if (k <14) {
				cout << k-4 << endl;
				continue;
			}
			if (k < 16) {
				cout << k-5 << endl;
				continue;
			}
			
			cout << k-6 << endl;
			continue;
		}

	}
	return 0;
}
	