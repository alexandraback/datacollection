#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int R, C, M;
		int i;
		scanf("%d %d %d", &R, &C, &M);
		
		bool impossible = false;
		char field[R][C+1];
		for (i=0; i<R; i++) {
			fill(field[i], field[i]+C, '.');
			field[i][C] = '\0';
		}
		field[0][0] = 'c';

		if (M == 0); // nothing to do
		else if (R == 1 and C == 1); // nothing to do, and this never happens, but wtv
		else if (M == R*C - 1) {
			for (i=0; i<R; i++)
				fill(field[i], field[i]+C, '*');
			field[0][0] = 'c';
		}
		else if (R == 1 or C == 1) {
			if (M > R*C - 2)
				impossible = true;
			else if (R == 1)
				fill(field[0]+C-M, field[0]+C, '*');
			else 
				for (i=R-M; i<R; i++)
					field[i][0] = '*';
		}
		else if (R == 2 or C == 2) {
			if (M % 2 == 1 or M > R*C - 4)
				impossible = true;
			else if (R == 2) {
				fill(field[0]+C-M/2, field[0]+C, '*');
				fill(field[1]+C-M/2, field[1]+C, '*');
			}
			else {
				for (i=R-M/2; i<R; i++)
					field[i][0] = field[i][1] = '*';
			}
		}
		else {
			int r=R, c=C;
			while (r > 3 and M >= c) {		// Fill a line with mines
				fill(field[r-1], field[r-1]+c, '*');
				M -= c;
				--r;
			}

			if (r > 3 and M > 0) {
				if (M < c-1) {
					fill(field[r-1]+c-M, field[r-1]+c, '*');
					M = 0;
				}
				else if (M == c-1) {
					fill(field[r-1]+2, field[r-1]+c, '*');
					field[r-1-1][c-1] = '*';
					M = 0;
				}
				else; // can't happen
			}
			else if (r == 3 and M > 0) {   // here, we must have r == 3 (if M>0) or it would have been taken care of
				while (c > 3 and M >= r) {
					for (i=0; i<r; i++) field[i][c-1] = '*';
					M -= r;
					--c;
				}

				if (c > 3 and M > 0) {
					field[2][c-1] = '*';
					if (M == 2)
						field[2][c-2] = '*';
					M = 0;
				}
				else if (c == 3 and M > 0) {		// We are left with a 3x3 field
					if (M == 2 or M == 4 or M >= 6)
						impossible = true;
					else if (M == 1)
						field[2][2] = '*';
					else if (M == 3)
						field[2][2] = field[1][2] = field[0][2] = '*';
					else if (M == 5)
						field[2][2] = field[1][2] = field[0][2] = field[2][1] = field[2][0] = '*';
				}
			}
		}



		printf("Case #%d:\n", iC);
		if (impossible) {
			printf("Impossible\n");
		}
		else {
			for (i=0; i<R; i++)
				printf("%s\n", field[i]);
		}




	}
	return 0;
}