#include<stdio.h>

char board[11][11];
int cntO, cntX, cntT, cnt_blank;
bool winO, winX;

int main() {

	int t,T,i,j;

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		winO=false, winX=false, cnt_blank=0;	// initializing
		for(i=0 ; i<4 ; i++)
			scanf("%s", board[i]);

		for(i=0 ; i<4 ; i++) {
			if(winO || winX) break;

			for(j=0, cntO=0, cntX=0, cntT=0 ; j<4 ; j++) {
				if(board[i][j]=='X') cntX++;
				else if(board[i][j]=='O') cntO++;
				else if(board[i][j]=='T') cntT++;
				else cnt_blank++;
			}

			if(cntO+cntT==4) winO=true;
			else if(cntX+cntT==4) winX=true;
		}
		for(j=0 ; j<4 ; j++) {
			if(winO || winX) break;

			for(i=0, cntO=0, cntX=0, cntT=0 ; i<4 ; i++) {
				if(board[i][j]=='X') cntX++;
				else if(board[i][j]=='O') cntO++;
				else if(board[i][j]=='T') cntT++;
				else cnt_blank++;
			}

			if(cntO+cntT==4) winO=true;
			else if(cntX+cntT==4) winX=true;
		}
		for(i=0 ; i<1 ; i++) {
			if(winO || winX) break;

			for(j=0, cntO=0, cntX=0, cntT=0 ; j<4 ; j++) {
				if(board[j][j]=='X') cntX++;
				else if(board[j][j]=='O') cntO++;
				else if(board[j][j]=='T') cntT++;
				else cnt_blank++;
			}

			if(cntO+cntT==4) winO=true;
			else if(cntX+cntT==4) winX=true;
		}
		for(i=0 ; i<1 ; i++) {
			if(winO || winX) break;

			for(j=0, cntO=0, cntX=0, cntT=0 ; j<4 ; j++) {
				if(board[j][3-j]=='X') cntX++;
				else if(board[j][3-j]=='O') cntO++;
				else if(board[j][3-j]=='T') cntT++;
				else cnt_blank++;
			}

			if(cntO+cntT==4) winO=true;
			else if(cntX+cntT==4) winX=true;
		}

		printf("Case #%d: ", t);
		if(winO) printf("O won\n");
		else if(winX) printf("X won\n");
		else if(cnt_blank!=0) printf("Game has not completed\n");
		else printf("Draw\n");
	}

	return 0;
}