#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 2123123123
#define pb push_back
using namespace std;

char C[20], J[20];

bool isMatchC(int x) {
	if (strlen(C) == 1) {
		if (x >= 10) {
			return false;
		}

		if (C[0] == '?' || (C[0] - '0') == x)
			return true;

		return false;
	}

	if (strlen(C) == 2) {
		if (x >= 100) {
			return false;
		}

		char c0 = C[0];
		char c1 = C[1];
		char x0 = (x / 10) + '0';
		char x1 = (x % 10) + '0';

		if ((c0 == '?' || c0 == x0) && (c1 == '?' || c1 == x1))
			return true;

		return false;
	}

	char c0 = C[0];
	char c1 = C[1];
	char c2 = C[2];
	char x0 = (x / 100) + '0';
	char x1 = ((x / 10) % 10) + '0';
	char x2 = (x % 10) + '0';

	if ((c0 == '?' || c0 == x0) && (c1 == '?' || c1 == x1) && (c2 == '?' || c2 == x2))
		return true;

	return false;
}

bool isMatchJ(int x) {
	if (strlen(J) == 1) {
		if (x >= 10) {
			return false;
		}

		if (J[0] == '?' || (J[0] - '0') == x)
			return true;

		return false;
	}

	if (strlen(J) == 2) {
		if (x >= 100) {
			return false;
		}

		char j0 = J[0];
		char j1 = J[1];
		char x0 = (x / 10) + '0';
		char x1 = (x % 10) + '0';

		if ((j0 == '?' || j0 == x0) && (j1 == '?' || j1 == x1))
			return true;

		return false;
	}

	char j0 = J[0];
	char j1 = J[1];
	char j2 = J[2];
	char x0 = (x / 100) + '0';
	char x1 = ((x / 10) % 10) + '0';
	char x2 = (x % 10) + '0';

	if ((j0 == '?' || j0 == x0) && (j1 == '?' || j1 == x1) && (j2 == '?' || j2 == x2))
		return true;

	return false;
}

int main() {
	int T, ansC, ansJ, ansDiff;

	scanf("%d", &T);

	FORU(tc, 1, T) {
		scanf("%s %s", C, J);

		ansDiff = -1;

		REP(i, 1000) {
			if (isMatchC(i)) {
				REP(j, 1000) {
					if (isMatchJ(j)) {
						int diff = abs(i - j);

						if (ansDiff == -1 || diff < ansDiff) {
							ansDiff = diff;
							ansC = i;
							ansJ = j;
						}
						else if (ansDiff == diff) {
							if (i < ansC) {
								ansC = i;
								ansJ = j;
							}
							else if (i == ansC) {
								ansJ = min(ansJ, j);
							}
						}
					}
				}
			}
		}

		printf("Case #%d:", tc);

		if (strlen(C) == 1) {
			printf(" %d", ansC);
		}
		else if (strlen(C) == 2) {
			printf(" %02d", ansC);
		}
		else {
			printf(" %03d", ansC);
		}

		if (strlen(J) == 1) {
			printf(" %d\n", ansJ);
		}
		else if (strlen(J) == 2) {
			printf(" %02d\n", ansJ);
		}
		else {
			printf(" %03d\n", ansJ);
		}
	}

	return 0;
}
