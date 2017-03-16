#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int X, R, C;
		scanf("%d %d %d", &X, &R, &C);

		string winner = "GABRIEL";
		if ((R*C)%X != 0) {						// Can't fill the grid with X-ominoes
			winner = "RICHARD";
		}
		else if (X >= 7) {						// Richard will just chose a omino with a hole, which can be done for X>=7
			winner = "RICHARD";		
		}
		else if (R < X and C < X) { 			// Use a beam, and it won't fit either way
			winner = "RICHARD";	
		}
		else if (R < (X+1)/2 or C < (X+1)/2) { 	// Richard can choose an L-shape that is ((X+1)/2)x((X+1)/2) and can't be placed
			winner = "RICHARD";
		}
		else if (X >= 4 and (R == 2 or C == 2)) {
			// For X = 4, use a T, that partitions the grid into two parts with odd number of cells
			// For X = 5, use the wall to make a hole
			winner = "RICHARD";
		}
		else if (X >= 6 and (R == 3 or C == 3)) {
			// We can use a cross (4x3) to make the two parts not divisible by 3, and therefore not divisible by 5
			// We can't do this for X=5, because 5 and 3 are coprime
			winner = "RICHARD";
		}

		printf("Case #%d: %s\n", iC, winner.c_str());
	}
	return 0;
}