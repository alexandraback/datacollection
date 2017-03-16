#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an;
char a[10][10];
bool empty, xwin, owin;

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		empty = true;
		xwin = false;
		owin = false;
		printf("Case #%d: ", rr);
		for (int i=0; i<4; i++)
			scanf("%s", a[i]);
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				if (a[i][j] == '.')
					empty = false;
		for (int i=0; i<4; i++){
			cnt = 0;
			for (int j=0; j<4; j++)
				if (a[i][j] == 'X' || a[i][j] == 'T')
					cnt++;
			if (cnt == 4)
				xwin = true;

			cnt = 0;
			for (int j=0; j<4; j++)
				if (a[j][i] == 'X' || a[j][i] == 'T')
					cnt++;
			if (cnt == 4)
				xwin = true;

			cnt = 0;
			for (int j=0; j<4; j++)
				if (a[i][j] == 'O' || a[i][j] == 'T')
					cnt++;
			if (cnt == 4)
				owin = true;

			cnt = 0;
			for (int j=0; j<4; j++)
				if (a[j][i] == 'O' || a[j][i] == 'T')
					cnt++;
			if (cnt == 4)
				owin = true;
		}

		cnt = 0;
		for (int i=0; i<4; i++){
			if (a[i][i] == 'X' || a[i][i] == 'T')
				cnt++;
		}
		if (cnt == 4)
			xwin = true;

		cnt = 0;
		for (int i=0; i<4; i++){
			if (a[i][3-i] == 'X' || a[i][3-i] == 'T')
				cnt++;
		}
		if (cnt == 4)
			xwin = true;

		cnt = 0;
		for (int i=0; i<4; i++){
			if (a[i][i] == 'O' || a[i][i] == 'T')
				cnt++;
		}
		if (cnt == 4)
			owin = true;

		cnt = 0;
		for (int i=0; i<4; i++){
			if (a[i][3-i] == 'O' || a[i][3-i] == 'T')
				cnt++;
		}
		if (cnt == 4)
			owin = true;

		if (xwin)
			printf("X won\n");
		else if (owin)
			printf("O won\n");
		else if (empty)
			printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}
