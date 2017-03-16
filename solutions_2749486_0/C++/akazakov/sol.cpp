#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

string makeSeq(int x, char up, char down) {
	if (x == 0) {
		return "";
	}
	if (x < 0) {
		swap(up, down);
		x = -x;
	}
	string res = "";
	for (int i = 0; i < x; ++i) {
		res += down;
		res += up;
	}
	return res;
}

void solveTestCase_stupid() {
	int x, y;
	cin >> x >> y;
	cout << makeSeq(y, 'N', 'S') << makeSeq(x, 'E', 'W');
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << (i + 1) << ": ";
		solveTestCase_stupid();
		cout << endl;
	}
	return 0;
}