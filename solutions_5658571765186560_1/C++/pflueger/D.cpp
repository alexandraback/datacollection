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

	//Now the hard cases...
	if (X == 5) {
		if (R < 3 || C < 3) return false; //R. plays the "L"
		if (R > C) swap(R,C);
		if (R == 3) return (C >= 10); //Can slide the piece around in a 3x10 bounding box
		//If both dimensions are at least four, we're set.
		return true;
	}
	if (X == 6) {
		if (R>C) swap (R,C); //WLOG
		/* Consider this piece:
			xx
			 xxx
			 x
		  It's a winning move for R. when R<=3, since it doesn't fit if R<3, and
		  if R=3 it has 2mod3 boxes on one side of it.
		*/
		if (R<=3) return false;
		
		//If R>=4, make a 4x6 box. You can place any 6-omino in it, then place 3 more.
		return true;
	}
}

int main() {
	int T; cin >> T;
	for (int t=1; t<=T; t++) {
		int X,R,C; cin >> X >> R >> C;
		string res = (gwins(X,R,C))? "GABRIEL" : "RICHARD";
		printf("Case #%d: %s\n",t,res.c_str());
	}
}
