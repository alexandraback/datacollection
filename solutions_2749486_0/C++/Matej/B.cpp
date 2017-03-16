#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxS = 100;

int X, Y;
bool pos[409][409][maxS + 1];
string rec[409][409][maxS + 1];

void setReachable(int x, int y, int s, string r) {
	pos[x + 200][y + 200][s] = true;
	rec[x + 200][y + 200][s] = r;
}
void init() {
	for (int i = 0; i < 409; ++i)
		for (int j = 0; j < 409; ++j)
			for (int s = 0; s <= maxS; ++s) {
				pos[i][j][s] = false;
				rec[i][j][s] = "!";
			}
	setReachable(0, 0, 0, "");
}
bool inRange(int x, int y) {
	return (x >= -200 && x <= 200 && y >= -200 && y <= 200);
}
bool reachable(int x, int y, int steps) {
	if (!inRange(x, y))
		return false;
	return pos[x + 200][y + 200][steps];
}
string getPath(int x, int y, int s) {
	return rec[x + 200][y + 200][s];
}

int main()
{
	// precalculation
	init();
	for (int s = 1; s <= maxS; ++s)
		for (int x = -200; x <= 200; ++x)
			for (int y = -200; y <= 200; ++y) {
				if (reachable(x - s, y, s - 1))
					setReachable(x, y, s, getPath(x - s, y, s - 1) + "E");
				else if (reachable(x + s, y, s - 1))
					setReachable(x, y, s, getPath(x + s, y, s - 1) + "W");
				else if (reachable(x, y - s, s - 1))
					setReachable(x, y, s, getPath(x, y - s, s - 1) + "N");
				else if (reachable(x, y + s, s - 1))
					setReachable(x, y, s, getPath(x, y + s, s - 1) + "S");
			}

	/*
	int cnt = 0;
	for (int x = -100; x <= 100; ++x)
		for (int y = -100; y <= 100; ++y) {
			bool ok = false;
			for (int s = 0; s <= maxS; ++s)
				if (reachable(x, y, s))
					ok = true;
			if (!ok) {
				cnt++;
			}
		}
	cout << cnt << endl;
	*/

	int T;
	cin >> T;
	for (int Ti = 1; Ti <= T; Ti++)
	{
		cin >> X >> Y;
		int s = 0;
		while (!reachable(X, Y, s))
			s++;
		cout << "Case #" << Ti << ": " << getPath(X, Y, s) << endl;
	}
	return 0;
}