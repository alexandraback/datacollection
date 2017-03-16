#include <iostream>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int size, rows, columns;
		cin >> size >> rows >> columns;
		if(rows * columns % size != 0 //can't tile
			|| (size > rows && size > columns) //can't place -
			|| (size > 2 && (size / 2 >= rows || size / 2 >= columns)) //can't place +
			|| size >= 7) { //can contain holes
			cout << "Case #" << test << ": RICHARD\n";
		} else {
			cout << "Case #" << test << ": GABRIEL\n";
		}
	}
	return 0;
}
