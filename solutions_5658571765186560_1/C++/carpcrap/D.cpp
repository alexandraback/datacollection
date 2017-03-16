#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		bool ok = true;
		int X,R,C;
		cin >> X >> R >> C;
		//central space
		if (X >=7) ok = false;

		// area
		if ( (R*C)%X != 0) ok = false;

		// check T-piece out of grid
		if (R < (X+1)/2 || C < (X+1)/2) ok = false;

		// check basic blocks
		// 3 : 2*3
		//     no need
		// 4 : 3*4 (T block)
		// 5 : 3*5 (T block, +block, c block)
		// 6 : 4*6 (4 hori T block) 3*8 (3 hori T block)
		//     + block => 4*6
		int tmp;
		if (R > C) { tmp = R; R = C; C = tmp; }
		// R is smallest
		switch(X)
		{
			case 4:
				if (R<3 || C <4) ok = false;
				break;
			case 5:
				if (R<3) ok = false;
				break;
			case 6:
				if (R<4 || C <6) ok = false;
				break;
			default:
				break;
		}
		printf("Case #%d: %s\n", t, ok?"GABRIEL" : "RICHARD"); 
	}
}
