#include <iostream>
#include <string>
using namespace std;

int rows, columns, mines, cases;
string map[100];

void display(bool inverted) {
	if (inverted) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				cout<<map[j][i];
			}
			cout<<"\n";
		}
	} else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout<<map[i][j];
			}
			cout<<"\n";
		}
	}
}

int main() {
	cin>>cases;
	for (int c = 1; c <= cases; c++) {
		bool inverted = false;
		cin>>rows>>columns>>mines;
		if (columns > rows) {
			inverted = true;
			int t = columns;
			columns = rows;
			rows = t;
		}
		for (int i = 0; i < rows; i++) {
			map[i] = "";
			for (int j = 0; j < columns; j++) {
				map[i] += '.';
			}
		}

		cout<<"Case #"<<c<<":\n";
		int remaining = rows*columns - mines;
		// Special case: 2
		if (columns == 2) {
			if (remaining == 2 || (remaining != 1 && remaining % 2 == 1)) {
				cout<<"Impossible\n";
				continue;
			}
		} else if (columns == 1) {
			for (int i = 0; i < mines; i++) {
				map[i][0] = '*';
			}
			map[rows-1][0] = 'c';
			display(inverted);
			continue;
		} else if (remaining == 7 || remaining == 5 || remaining == 3 || remaining == 2) {
			cout<<"Impossible\n";
			continue;
		}

		// More specials!
		if (remaining == 6 || remaining == 4 || remaining == 1) {
			for (int i = 0; i < rows; i++) {
				map[i] = "";
				for (int j = 0; j < columns; j++) {
					map[i] += '*';
				}
			}

			map[0][0] = 'c';
			if (remaining > 1) map[0][1] = map[1][0] = map[1][1] = '.';
			if (remaining == 6) map[2][0] = map[2][1] = '.';

			display(inverted);
			continue;
		}

		// Now do greedy. I may assume board is >= 3.
		remaining = mines;
		map[0][0] = 'c';
		int right = columns-1;
		int top = rows-1;
		while (remaining) {
			if (right > top) {
				// fill the column.
				if (remaining == top+1 - 1) {
					// Tricky!
					for (int i = top; i >= 2; i--) {
						map[i][right] = '*';
					}
					map[top][right-1] = '*';
				} else {

					for (int i = 0; i < min(top+1, remaining); i++) {
						map[top-i][right] = '*';
					}
				}

				remaining = max(0, remaining - top - 1);
				right --;
			} else {
				// fill the row
				if (remaining == right+1-1) {
					for (int i = right; i >= 2; i--) {
						map[top][i] = '*';
					}
					map[top-1][right] = '*';
				} else {
					for (int i = 0; i < min(right+1, remaining); i++) {
						map[top][right-i] = '*';
					}
				}

				remaining = max(0, remaining-right - 1);
				top--;
			}
		}

		display(inverted);
	}
}