#include <iostream>

using namespace std;

int a, b, k;

int solve() {
	int count = 0;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			if ((i & j) < k)
				count++;
	return count;
}


int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> a >> b >> k;
		cout << "Case #" << i << ": " << solve() << endl;
	}
}
