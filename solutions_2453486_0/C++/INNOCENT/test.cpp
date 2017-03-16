#include <iostream>
#include <string>

#define rep(i, s, t) for (int i = s; i <= t; i++)
#define UPDATE(i, j)\
	if (a[i][j] == 'X') {\
		cnt[0]++;\
	} else if (a[i][j] == 'O') {\
		cnt[1]++;\
	} else if (a[i][j] == 'T') {\
		cnt[0]++;\
		cnt[1]++;\
	}
#define CHECK\
	if (cnt[0] == 4) {\
		winx;\
	} else if (cnt[1] == 4) {\
		wino;\
	}
#define winx cout << "X won\n"; goto out
#define wino cout << "O won\n"; goto out

using namespace std;

string a[4];

int main() {
	int T;
	cin >> T;
	rep (ca, 1, T) {
		rep (i, 0, 3) {
			cin >> a[i];
		}
		cout << "Case #" << ca << ": ";
		int cnt[2];
		int sum;
		rep (i, 0, 3) {
			cnt[0] = 0;
			cnt[1] = 0;
			rep (j, 0, 3) {
				UPDATE(i, j)
			}
			CHECK
		}
		rep (j, 0, 3) {
			cnt[0] = 0;
			cnt[1] = 0;
			rep (i, 0, 3) {
				UPDATE(i, j)
			}
			CHECK
		}
		cnt[0] = 0;
		cnt[1] = 0;
		rep (i, 0, 3) {
			UPDATE(i, i)
		}
		CHECK
		cnt[0] = 0;
		cnt[1] = 0;
		rep (i, 0, 3) {
			UPDATE(i, 3-i)
		}
		CHECK
		sum = 0;
		rep (i, 0, 3) {
			rep (j, 0, 3) {
				if (a[i][j] == '.') {
					sum++;
				}
			}
		}
		if (sum == 0) {
			cout << "Draw\n";
		} else {
			cout << "Game has not completed\n";
		}
out:
		continue;
	}
	return 0;
}
