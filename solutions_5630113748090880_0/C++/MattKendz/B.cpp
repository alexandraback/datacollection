#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t, n, temp;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> v;
		for (int j = 0; j < (2 * n * n) - n; j++) {
				cin >> temp;
				vector<int>::iterator place = find(v.begin(), v.end(), temp);
				if (place == v.end())
					v.push_back(temp);
				else
					v.erase(place);
		}

		sort(v.begin(), v.end());
		cout << "Case #" << i + 1 << ": ";
		for (int x = 0; x < v.size(); x++)
			cout << v[x] << " ";
		cout << endl;
	}

	return 0;
}