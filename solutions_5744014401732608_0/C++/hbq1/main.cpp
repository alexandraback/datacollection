#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef long long int lli;

const int MAXSIZE = 70;

int a[MAXSIZE];


int main() {
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int t, tn = 1;
	cin >> t;
	while (tn <= t) {
		cout << "Case #" << tn << ": ";
		tn++;
		memset(a, 0, MAXSIZE*sizeof(int));
		lli b, m;
		cin >> b >> m;

		int r = 0;
		int c = 0;
		lli k = m;
		while (k != 0) {
			c += k & 1;
			a[r++] = int(k & 1);
			k /= 2;
		}
		if (c == 1 && r+1 == b) {//ll
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < b - 1; ++i) {
				for (int j = 0; j < b; ++j)
					if (j <= i) cout << '0'; else cout << '1';
				cout << endl;
			}
			for (int j = 0; j < b; ++j)
				cout << '0';
			cout << endl;
		}
		else {
			if (r+1 >= b) {
				cout << "IMPOSSIBLE";
				cout << endl;
			}
			else {
				cout << "POSSIBLE" << endl;
				cout << '0';
				for (int j = 1; j < b - 1; ++j)
					cout << '1';
				cout << '0' << endl;
				for (int i = 1; i < r; ++i) {
					for (int j = 0; j < b-1; ++j)
						if (j <= i) cout << '0'; else cout << '1';
					cout << a[i-1];
					cout << endl;
				}
				for (int i = r; i < b; ++i) {
					for (int j = 0; j < b-1; ++j)
						cout << '0';
					if (i == r) cout << '1'; else cout << '0';
					cout << endl;
				}
				
			}
		}

		//cout << endl;
	}
	return 0;
}

