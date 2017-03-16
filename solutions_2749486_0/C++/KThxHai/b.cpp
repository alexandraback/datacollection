
#include <map>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define INPUT_FILE_NAME "B-small-attempt1"
#define OUTPUT_FILE_NAME "a"

void solveCase(){
	// ++a first increments then returns new

	char leftt = 'W';
	char rightt = 'E';
	char up = 'N';
	char down = 'S';

	int X, Y;
	scanf("%d %d", &X,&Y);
	if(X < 0) {
		X = -X;
		char tmp = leftt;
		leftt = rightt;
		rightt = tmp;
	}
	if(Y < 0) {
		Y = -Y;
		char tmp = down;
		down = up;
		up = tmp;
	}
	int jumpStep = 1;
	int nX = 0, nY = 0;
	while(nX < X) {
		if(abs(X - nX) > abs(X - (nX + jumpStep))) {
			nX += jumpStep++;
			printf("%c", rightt);
		} else {
			break;
		}
	}
	while(nX > X) {
		nX += jumpStep++;
		nX -= jumpStep++;
		printf("%c", rightt);
		printf("%c", leftt);
	}
	while(nX < X) {
		nX -= jumpStep++;
		nX += jumpStep++;
		printf("%c", leftt);
		printf("%c", rightt);
	}
	while(nY < Y) {
		if(abs(Y - nY) > abs(Y - (nY + jumpStep))) {
			nY += jumpStep++;
			printf("%c", up);
		} else {
			break;
		}
	}
	while(nY > Y) {
		nY += jumpStep++;
		nY -= jumpStep++;
		printf("%c", up);
		printf("%c", down);
	}
	while(nY < Y) {
		nY -= jumpStep++;
		nY += jumpStep++;
		printf("%c", down);
		printf("%c", up);
	}

//	int jumpStep = 1;
//	int nX = 0, nY = 0;
//	if(Y - nY > X - nX) {
//		nY += jumpStep++;
//		printf("%c", up);
//	}
//	while(true) {
//		if(X - nX < jumpStep) {
//			break;
//		}
//		nX += jumpStep++;
//		printf("%c", right);
//		if(Y - nY < jumpStep) {
//			break;
//		}
//		nY += jumpStep++;
//		printf("%c", up);
//	}
//	if()
}

int main() {
	freopen(INPUT_FILE_NAME ".in","r",stdin);
	freopen(OUTPUT_FILE_NAME ".out","w",stdout);
	int caseAmount;
	scanf("%d", &caseAmount);
	for (int caseNumber = 1; caseNumber <= caseAmount; ++caseNumber) {
		printf("Case #%d: ", caseNumber);

		solveCase();

		printf("\n");
	}
	return 0;
}
