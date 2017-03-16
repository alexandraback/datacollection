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
		int R_winFlag = 0;
		if(X == 1) {
			R_winFlag = 0;
		}else if(X == 2) {
			if(area % 2 == 0) R_winFlag = 0;
			else R_winFlag = 1;
		}else if(X == 3) {
			if(area >= 6 && area % 3 == 0) R_winFlag = 0;
			else R_winFlag = 1;
		}else if(X == 4) {
			if(R < 4 && C < 4) R_winFlag = 1;
			else if( (R == 4 && C <= 2) || (R <= 2 && C == 4)) R_winFlag = 1;
			else R_winFlag = 0;
		}
		if(R_winFlag) cout << "Case #" << t+1 << ": RICHARD" << endl;
		else cout << "Case #" << t+1 << ": GABRIEL" << endl;
	}
	return 0;
}

