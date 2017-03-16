#include <iostream>
#include <cmath>
using namespace std;

// assert abs(x) != abs(y)
inline string createPath(const int& x, const int& y) {
	string result;
	int nextJump(1);
	int currentX(0), currentY(0);

	if (abs(x) < abs(y)) {
		// Deal with X first
		if (x < 0) {
			// Move West
			while (currentX - nextJump >= x) {
				result += "W";
				currentX -= nextJump;
				nextJump++;
			}

			while (currentX != x) {
				result += "EW";
				nextJump += 2;
				currentX--;
			}
		} else {
			// Move East
			while (currentX + nextJump <= x) {
				result += "E";
				currentX += nextJump;
				nextJump++;
			}

			while (currentX != x) {
				result += "WE";
				nextJump += 2;
				currentX++;
			}
		}

		if (y < 0) {
			// Move South
			while (currentY - nextJump >= y) {
				result += "S";
				currentY -= nextJump;
				nextJump++;
			}

			while (currentY != y) {
				result += "NS";
				nextJump += 2;
				currentY--;
			}
		} else {
			// Move North
			while (currentY + nextJump <= y) {
				result += "N";
				currentY += nextJump;
				nextJump++;
			}

			while (currentY != y) {
				result += "SN";
				nextJump += 2;
				currentY++;
			}
		}
	} else {
		// Deal with Y first
		if (y < 0) {
			// Move South
			while (currentY - nextJump >= y) {
				result += "S";
				currentY -= nextJump;
				nextJump++;
			}

			while (currentY != y) {
				result += "NS";
				nextJump += 2;
				currentY--;
			}
		} else {
			// Move North
			while (currentY + nextJump <= y) {
				result += "N";
				currentY += nextJump;
				nextJump++;
			}

			while (currentY != y) {
				result += "SN";
				nextJump += 2;
				currentY++;
			}
		}

		if (x < 0) {
			// Move West
			while (currentX - nextJump >= x) {
				result += "W";
				currentX -= nextJump;
				nextJump++;
			}

			while (currentX != x) {
				result += "EW";
				nextJump += 2;
				currentX--;
			}
		} else {
			// Move East
			while (currentX + nextJump <= x) {
				result += "E";
				currentX += nextJump;
				nextJump++;
			}

			while (currentX != x) {
				result += "WE";
				nextJump += 2;
				currentX++;
			}
		}
	}

	return result;
}

int main() {
	int num_test;
	cin >> num_test;

	for (int testIndex(0); testIndex < num_test; testIndex++) {
		int x, y;
		cin >> x >> y;

		cout << "Case #" << testIndex + 1 << ": " << createPath(x, y) << endl;
	}

	return 0;
}
