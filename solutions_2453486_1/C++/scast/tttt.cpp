#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

char tab[10][10];
int t, tx[4], ty[4], td1, td2, ox[4], oy[4], od1, od2, xx[4], xy[4], xd1, xd2;
bool done;
int main() {
    scanf("%d\n", &t);
    for (int i=0; i<t; i++) {
	done = true;
	memset(tx, 0, sizeof tx);
	memset(ty, 0, sizeof ty);
	memset(ox, 0, sizeof ox);
	memset(oy, 0, sizeof oy);
	memset(xx, 0, sizeof xx);
	memset(xy, 0, sizeof xy);
	td1 = td2 = od1 = od2 = xd1 = xd2 = 0;
	for (int i=0; i<4; i++) {
	    for (int j=0; j<4; j++) {
		scanf("%c", &tab[i][j]);
		switch(tab[i][j]) {
		case 'X':
		    xx[i]++, xy[j]++;
		    if (i == j) xd1++;
		    if (j == 3-i) xd2++;
		    break;
		case 'O':
		    ox[i]++, oy[j]++;
		    if (i == j) od1++;
		    if (j == 3-i) od2++;
		    break;
		case 'T':
		    tx[i]++, ty[j]++;
		    if (i == j) td1++;
		    if (j == 3-i) td2++;
		    break;
		case '.':
		    done = false;
		    break;
		}
	    }
	    scanf("\n");
	}
	bool won = false;
	printf("Case #%d: ", i+1);
	for (int i=0; i<4 && !won; i++) {
	    if (ox[i] + tx[i] == 4 ||
		oy[i] + ty[i] == 4 ||
		od1 + td1 == 4 || od2 + td2 == 4) {
		printf("O won");
		won = true;
	    }
	    if (xx[i] + tx[i] == 4 ||
		xy[i] + ty[i] == 4 ||
		xd1 + td1 == 4 || xd2 + td2 == 4) {
		printf("X won");
		won = true;
	    }
	}
	if (!won) {
	    if (done) printf("Draw");
	    else printf("Game has not completed");
	}
	printf("\n");
	scanf("\n");
    }
    return 0;
}
