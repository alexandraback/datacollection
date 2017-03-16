#include<stdio.h>
#include<string.h>

short board[55][55];
bool vis[55][55];
int rmin, cmin, rmax, cmax, m;

bool inbound(int rx, int cx){
	if (rx >= 0 && cx >= 0 && rx < rmax && cx < cmax) return true;
	return false;
}

void addmine(int rx, int cx){
	board[rx][cx] = -1;
	int d[] = {-1, 0, 1};
	for(int i = 0; i < 3;i++){
		for(int j = 0; j < 3;j++){
			if (i == 1 && j == 1) continue;
			int rn = rx + d[i];
			int cn = cx + d[j];
			if (inbound(rn, cn)){
				if (board[rn][cn] != -1){
					board[rn][cn] ++;
				}
			}
		}
	}
	m --;
}

void rmvmine(int rx, int cx){
	board[rx][cx] = 0;
	int d[] = {-1, 0, 1};
	for(int i = 0; i < 3;i++){
		for(int j = 0; j < 3;j++){
			if (i == 1 && j == 1) continue;
			int rn = rx + d[i];
			int cn = cx + d[j];
			if (inbound(rn, cn)){
				if (board[rn][cn] != -1){
					board[rn][cn] --;
				}
				else board[rx][cx] ++;
			}
		}
	}
	m++;
}

void printboard(){
	for(int i = 0; i < rmax;i++){
		for(int j = 0; j < cmax;j++){
			if (i == rmax - 1 && j == cmax - 1) printf("c");
			else if (board[i][j] == -1) printf("*");
			else printf(".");
		}
		printf("\n");
	}
}

void minerow(){
	for(int i = cmin; i < cmax;i++){
		addmine(rmin, i);
	}
	rmin ++;
}

void minecol(){
	for(int i = rmin; i < rmax;i++){
		addmine(i, cmin);
	}
	cmin ++;
}

int checkboard(int rx, int cx){
	if (!inbound(rx, cx)) return 0;
	if (vis[rx][cx] == true) return 0;
	vis[rx][cx] = true;
	if (board[rx][cx] == -1) return 0;
	if (board[rx][cx] != 0) return 1;
	int ret = 1;

	int d[] = {-1, 0, 1};
	for(int i = 0; i < 3;i++){
		for(int j = 0; j < 3;j++){
			if (i == 1 && j == 1) continue;
			int rn = rx + d[i];
			int cn = cx + d[j];
			if (inbound(rn,cn)){
				ret += checkboard(rn,cn);
			}
		}
	}
	return ret;
}

int main(){
	freopen("in.in","r",stdin);
	freopen("out.out", "w",stdout);
	int n;
	scanf("%d",&n);
	for(int x = 1; x <= n;x++){
		memset(board,0, sizeof(board));
		memset(vis, false, sizeof(vis));
		rmin = 0; cmin = 0;
		scanf("%d %d %d",&rmax,&cmax,&m);
		int mines = m;
		while(m > 0){
			int width = cmax - cmin;
			int height = rmax - rmin;
			if (m >= width && m >= height){
				if (width < height) minerow();
				else minecol();
			}
			else if (m >= width) minerow();
			else if (m >= height) minecol();
			else break;
		}
		int leftcol = cmin;
		while(m && (cmax - leftcol) > 2) addmine(rmin, leftcol ++);
		int toprow = rmin + 1;
		while(m && (rmax - toprow) > 2) addmine(toprow ++, cmin);
		printf("Case #%d:\n", x);
		if (m == 0){
			int reachable = checkboard(rmax - 1, cmax - 1);
			if (reachable > 0 && (reachable + mines == rmax * cmax)){
				printboard();
			}
			else printf("Impossible\n");
		}
		else printf("Impossible\n");
	}
}