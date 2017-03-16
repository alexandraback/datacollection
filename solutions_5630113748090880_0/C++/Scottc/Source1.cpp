#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream in("B-small-attempt0.in");
	cin.rdbuf(in.rdbuf());
	ofstream out("B-small-attempt0.out");
	cout.rdbuf(out.rdbuf());
	// read
	int kase = 1, T, n;
	cin >> T;
	while (T--) {
		int x, count[2600] = {}, ans[101], ac = 0;
		cin >> n;
		for (int i = 0 ; i < 2 * n - 1; ++i)
			for (int j = 0 ; j < n; ++j)
				cin >> x, ++count[x];
		for (int i = 0 ; i < 2500; ++i)
			if (count[i] & 1) ans[ac++] = i;
		sort(ans, ans + ac);
		cout << "Case #" << kase++ << ":";
		for (int i = 0; i < ac; ++i)
			cout << " " << ans[i];
		cout << endl;
	}
}