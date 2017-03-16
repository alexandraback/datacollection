#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int step (int a) {
	if (a == 0)
		return 1;
	else
		return (1 << (a-1));
}

int main () {
	ifstream cin ("input.txt");
	ofstream cout ("output.txt");
	int t;
	cin >> t;
	for (int k = 0; k < t; ++k) {
		cout << "Case #" << k + 1 << ": ";
		int b, m;
		cin >> b >> m;
		if (step(b-1) < m)
			cout << "IMPOSSIBLE" << endl;
		else {
			vector < vector <bool> > mt (b, vector <bool> (b, false));
			for (int i = 0; i < b-1; ++i)
				for (int j = i+1; j < b-1; ++j)
					mt[i][j] = true;
			for (int j = b-2; j >= 0; --j)
				if (m >= step(j)) {
					m -= step(j);
					mt[j][b-1] = true;
				}
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < b; ++j)
					cout << (int)mt[i][j];
				cout << endl;
			}
		}
	}
}