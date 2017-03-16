#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

const int MAXSTEPS = 500;
const int LIMINF = -100;
const int LIMSUP = 100;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		char output[MAXSTEPS+1];
		int x, y;
		scanf("%d %d", &x, &y);

		const char * st = "SN";
		if (y < 0) {
			st = "NS";
			y = -y;
		}

		char * p = output;
		for (int i=0; i<y; i++) {
			*(p++) = st[0];
			*(p++) = st[1];
		}

		st = "WE";
		if (x < 0) {
			st = "EW";
			x = -x;
		}

		for (int i=0; i<x; i++) {
			*(p++) = st[0];
			*(p++) = st[1];
		}
		*p = '\0';

		printf("Case #%d: %s\n", iC, output);
	}
	return 0;
}