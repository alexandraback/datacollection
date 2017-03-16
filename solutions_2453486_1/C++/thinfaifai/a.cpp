#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

char s[6][6];
int dx[]={0,1,1,1},dy[]={1,0,1,-1};

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		printf("Case #%d: ",t);
		int draw = 1,ok = 0;
		for (int i=0; i<4; i++)
			scanf("%s",s[i]);
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++) {
				if (s[i][j] == '.') {
					draw = 0; continue;
				}
				for (int k=0; k<4; k++) {
					ok = 0;
					int nx,ny;
					int cntx = 0,cnto = 0;
					for (int x=0; x<4; x++) {
						nx = i+dx[k]*x; ny = j+dy[k]*x;
						if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
							if (s[nx][ny] == 'X') cntx++;
							if (s[nx][ny] == 'O') cnto++;
							if (s[nx][ny] == 'T') cntx++,cnto++;
						}
					}
					if (cntx == 4) {
						ok = 1;
						printf("X won\n");
						goto bye;
					}
					if (cnto == 4) {
						ok = 1;
						printf("O won\n");
						goto bye;
					}
				}
			}
		bye:
		if (!ok) {
			if (draw) printf("Draw\n");
			else {
				printf("Game has not completed\n");
			}
		}
	}
	return 0;
}
