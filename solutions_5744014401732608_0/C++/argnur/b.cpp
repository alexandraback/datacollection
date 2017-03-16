#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	long long t, test, i, b, m, j;
	cin >> t;
	for (test=1;test<=t;test++) {
		cout << "Case #" << test << ": ";
		cin >> b >> m;
		long long maximum = ((long long) 1) << (b-2);
		if (maximum < m) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		vector< vector<int> > a(50, vector<int>(50, 0));
		for (i=0;i<b;i++)
			for (j=i+1;j<b;j++)
				a[i][j] = 1;
		
		i = 1;
		while (maximum!=m) {
			long long d = ((long long) 1) << (b-i-2);
			if (maximum - d >= m) {
				a[0][i] = 0;
				maximum -= d;
			}
			i++;
		}
		for (i=0;i<b;i++) {
			for (j=0;j<b;j++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
}