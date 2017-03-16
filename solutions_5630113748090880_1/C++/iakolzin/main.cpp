#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	freopen("inputl.txt", "r", stdin);
	freopen("outputl.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		vector <int> arr(2510, 0);
		for (int i = 0; i < 2 * n - 1; i++)
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				arr[x]++;
			}
		cout << "Case #" << t << ": ";
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] & 1)
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}