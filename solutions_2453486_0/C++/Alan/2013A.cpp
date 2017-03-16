#include <cstdio>
#include <algorithm>
#define ROW 4
#define COL 4
using namespace std;
int main() {
	int T;
	char b[ROW][COL + 1];
	scanf("%d", &T);
	for(int cs = 1; cs <= T; ++cs) {
		int cnt = 0;
		for(int i = 0; i < ROW; ++i) {
			scanf("%s", b[i]);
			for(int j = 0; j < COL; ++j) {
				if(b[i][j] != '.')
					++cnt;
			}
		}
		int mocnt = 0, mxcnt = 0;
		for(int i = 0; i < ROW; ++i) {
			int ocnt = 0, xcnt = 0;
			for(int j = 0; j < COL; ++j) {
				if(b[i][j] == 'X' || b[i][j] == 'T')
					xcnt++;
				if(b[i][j] == 'O' || b[i][j] == 'T')
					ocnt++;
			}
			mocnt = max(mocnt, ocnt);
			mxcnt = max(mxcnt, xcnt);
		}
		for(int j = 0; j < COL; ++j) {
			int ocnt = 0, xcnt = 0;
			for(int i = 0; i < ROW; ++i) {
				if(b[i][j] == 'X' || b[i][j] == 'T')
					xcnt++;
				if(b[i][j] == 'O' || b[i][j] == 'T')
					ocnt++;
			}
			mocnt = max(mocnt, ocnt);
			mxcnt = max(mxcnt, xcnt);
		}
		{
			int ocnt = 0, xcnt = 0;
			for(int i = 0, j = 0; j < COL && i < ROW; ++i, ++j) {
				if(b[i][j] == 'X' || b[i][j] == 'T')
					xcnt++;
				if(b[i][j] == 'O' || b[i][j] == 'T')
					ocnt++;
			}
			mocnt = max(mocnt, ocnt);
			mxcnt = max(mxcnt, xcnt);
			ocnt = 0, xcnt = 0;
			for(int i = 0, j = COL - 1; j >=0 && i < ROW; ++i, --j) {
				if(b[i][j] == 'X' || b[i][j] == 'T')
					xcnt++;
				if(b[i][j] == 'O' || b[i][j] == 'T')
					ocnt++;
			}
			mocnt = max(mocnt, ocnt);
			mxcnt = max(mxcnt, xcnt);
		}
		printf("Case #%d: ", cs);
		if(mocnt == 4 && mxcnt == 4) {
			puts("Draw");
		}
		else if(mocnt == 4) {
			puts("O won");
		}
		else if(mxcnt == 4) {
			puts("X won");
		}
		else if(cnt == ROW * COL) {
			puts("Draw");
		}
		else {
			puts("Game has not completed");
		}
	}
	return 0;
}
