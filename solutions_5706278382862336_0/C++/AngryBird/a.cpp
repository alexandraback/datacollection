#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPower(int x) {
	if (x == 1)
		return true;
	else if (x%2 == 1)
		return false;
	else 
		return isPower(x/2);
}

int parent(int a, int b) {
	if (a*2 >= b) {
		return 1;
	} else {
		return 1 + parent(a*2, b);
	}
}

int main() {
	int T;
	int P, Q;
	char c;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> P >> c >> Q;
		cout << "Case #" << i+1 << ": ";
		if (!isPower(Q)) {
			cout << "impossible" << endl;
		} else {
			cout << parent(P, Q) << endl;
		}
	}
	return 0;
}