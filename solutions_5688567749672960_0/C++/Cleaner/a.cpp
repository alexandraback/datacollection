#include <iostream>
#include <vector>
using namespace std;

int n = 1000000;

int flip(int i) {
	int r = 0;
	while (i > 0) {
		r = r * 10 + i % 10;
		i /= 10;
	}
	return r;
}

int main() {
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0 || d[i] > d[i - 1] + 1)
			d[i] = d[i - 1] + 1;
		int f = flip(i);
		//cout << i << " " << f << "\n";
		if (d[f] == 0 || d[f] > d[i] + 1)
			d[f] = d[i] + 1;
	}
	int cs;
	cin >> cs;
	for (int cc = 1; cc <= cs; cc++) {
		int m;
		cin >> m;
		cout << "Case #" << cc << ": " << d[m] << "\n";
	}
}
