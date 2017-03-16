#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring> // memset(void *b, int c, size_t len);
#include <algorithm> // sort
#include <iomanip> // cout << std::fixed << std::setprecision(4)

using namespace std;

int main(int argc, char* argv[]) {
	int T, X, R, C;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> X >> R >> C;
		int area = R*C;
		int L = (R > C)? R: C;
		int S = (R < C)? R: C;
		int R_winFlag = 0;
		if(X == 1) {
			R_winFlag = 0;
		} else if(X == 2) {
			if(area % 2 == 0) R_winFlag = 0;
			else R_winFlag = 1;
		} else if(X == 3) {
			if(area % 3 == 0 && L >= 3 && S >= 2) R_winFlag = 0;
			else R_winFlag = 1;
		} else if(X == 4) {
			if(area % 4 == 0 && L >= 4 && S >= 3) R_winFlag = 0;
			else R_winFlag = 1;
		} else if(X == 5) {
			if(area % 5 == 0 && ((L >= 10 && S >= 3) || L >= 5 && S >= 4)) R_winFlag = 0;
			else R_winFlag = 1;
		} else if(X == 6) {
			if(area % 6 == 0 && ((L >= 12 && S >= 3) || L >= 6 && S >= 5)) R_winFlag = 0;
			else R_winFlag = 1;
		} else {
			R_winFlag = 1;
		}
		if(R_winFlag) cout << "Case #" << t+1 << ": RICHARD" << endl;
		else cout << "Case #" << t+1 << ": GABRIEL" << endl;
	}
	return 0;
}

