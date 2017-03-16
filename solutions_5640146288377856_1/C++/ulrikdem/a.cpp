#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int rows, columns, width;
		cin >> rows >> columns >> width;
		cout << "Case #" << test << ": " << rows * (columns / width) + width - (columns % width ? 0 : 1) << '\n';
	}
	return 0;
}
