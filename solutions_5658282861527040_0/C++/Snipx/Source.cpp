# include <string>
# include <fstream>
# include <algorithm>
# include <set>
# include <map>
# include <iostream>
# include <vector>
using namespace std;


int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		int ans = 0;
		int a, b, k;
		cin >> a >> b >> k;
		for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
		if ((i & j) < k)
			ans++;

		cout << ans;

		cout << endl;
	}

	return 0;
}