#include <iostream>
#include <cstdio>

using namespace std;

bool gwins(int X, int R, int C) {
	if ( (R*C)%X != 0) return false; //Wrong number of squares
	if (X >= 7) return false; //Richard can use a X-omino with a hole in the middle
	if (X <= 2) return true;
	if (X == 3) return (R >= 2 && C >= 2);
	if (X == 4) {
		if (R <= 2 || C <= 2) return false; //R. plays the "T"
		return true;
	}

	//Remains to work out the X=5 and X=6 cases.
}

int main() {
	int T; cin >> T;
	for (int t=1; t<=T; t++) {
		int X,R,C; cin >> X >> R >> C;
		string res = (gwins(X,R,C))? "GABRIEL" : "RICHARD";
		printf("Case #%d: %s\n",t,res.c_str());
	}
}
