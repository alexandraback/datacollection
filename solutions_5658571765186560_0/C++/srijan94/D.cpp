#include <cstdio>

using namespace std;

int X, R, C;

int main(int argc, char const *argv[])
{
	freopen("iSD.in", "r", stdin);
	freopen("oSD.txt", "w", stdout);
	int tc, T;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d%d%d", &X, &R, &C);
		printf("Case #%d: ", tc);
		if(X == 1) {
			puts("GABRIEL");
			continue;
		}
		if(R == 1 && C == 1) {
			puts("RICHARD");
			continue;
		}
		if(X == 2) {
			if(R == 1 && C == 3) puts("RICHARD");
			else if(R == 3 && C == 1) puts("RICHARD");
			else if(R == 3 && C == 3) puts("RICHARD");
			else puts("GABRIEL");
		}
		else if(X == 3) {
			if(R == 1 || C == 1) puts("RICHARD");
			else if(R == 2 && C == 2) puts("RICHARD");
			else if(R == 2 && C == 4) puts("RICHARD");
			else if(R == 4 && C == 2) puts("RICHARD");
			else if(R == 4 && C == 4) puts("RICHARD");
			else puts("GABRIEL");
		}
		else if(X == 4) {
			if(R == 1 || C == 1) puts("RICHARD");
			else if(R == 2 || C == 2) puts("RICHARD");
			else if(R == 3 && C == 3) puts("RICHARD");
			else puts("GABRIEL");
		}
	}
	return 0;
}