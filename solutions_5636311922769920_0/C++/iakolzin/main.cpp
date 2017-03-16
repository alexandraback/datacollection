#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << t << ": ";
		for (int i = 1; i <= c; i++)
			cout << i << " ";
		cout << endl;
	}
}