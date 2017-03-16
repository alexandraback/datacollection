#include <iostream>

using namespace std;

int T;
int x, y;
char step[10000];
int n;

int main(){
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> x >> y;
		n = (int)sqrt((double)(abs(x) + abs(y))) * 2 - 2;
		bool found = false;
		while (!found) {
			n ++;
			int tx = x;
			int ty = y;
			for (int i = n; i > 0; --i) {
				if (abs(tx) > abs(ty)) {
					if (tx > 0) {
						step[i - 1] = 'E';
						tx -= i;
					} else {
						step[i - 1] = 'W';
						tx += i;
					}
				} else {
					if (ty > 0) {
						step[i - 1] = 'N';
						ty -= i;
					} else {
						step[i - 1] = 'S';
						ty += i;
					}
				}
			}
			if (tx == 0 && ty == 0) {
				found = true;
			}
		}
		cout << "Case #" << caseNum + 1 << ": ";
		for (int i = 0; i < n; ++i) {
			cout << step[i];
		}
		cout << endl;
	}
}