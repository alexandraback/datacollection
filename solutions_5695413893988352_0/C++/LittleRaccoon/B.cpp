#include <stdio.h>
#include <string.h>

char C[20], J[20], BC[20], BJ[20];
int bestC, bestJ;

int abs(int d) {
	return d < 0? -d: d;
}

void fJ(int t)
{
	if (!J[t]) {
		int c, j;
		sscanf(C, "%d", &c);
		sscanf(J, "%d", &j);
		if (abs(c - j) < abs(bestC - bestJ)) {
			bestC = c;
			bestJ = j;
			strcpy(BC, C);
			strcpy(BJ, J);
		}
		else if (abs(c - j) == abs(bestC - bestJ) && c < bestC) {
			bestC = c;
			bestJ = j;
			strcpy(BC, C);
			strcpy(BJ, J);
		}
		
		return;
	}

	if (J[t] == '?') {
		for (int i = 0; i <= 9; i++) {
			J[t] = i + '0';
			fJ(t + 1);
		}
		J[t] = '?';
	}
	else {
		fJ(t + 1);
	}
}

void fC(int t)
{
	if (!C[t]) {
		fJ(0);
		return;
	}

	if (C[t] == '?') {
		for (int i = 0; i <= 9; i++) {
			C[t] = i + '0';
			fC(t + 1);
		}
		C[t] = '?';
	}
	else {
		fC(t + 1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {
		scanf("%s%s", C, J);

		bestC = -1;
		bestJ = 1000000;
		fC(0);

		printf("Case #%d: %s %s\n", t, BC, BJ);
	}

	return 0;
}

