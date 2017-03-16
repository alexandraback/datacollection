#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char A[4][10];
int N,X,T,O,n;
bool ok;
void won(char K) {
	if (!ok) printf("Case #%d: %c won\n",n,K);
	ok=1;
}
int main () {
	scanf("%d",&N);
	for (n=1;n<=N;n++) {
		ok=0;
		for (int i=0;i<4;i++) scanf("%s",A[i]);
		for (int i=0;i<4;i++) {
			X=T=O=0;
			for (int j=0;j<4;j++) {
				if (A[i][j]=='X') X++;
				else if (A[i][j]=='O') O++;
				else if (A[i][j]=='T') T++;
			}
			if ( (X==3 && T==1) || X==4) won('X');
			if ( (O==3 && T==1) || O==4) won('O');
		}
		for (int i=0;i<4;i++) {
			X=T=O=0;
			for (int j=0;j<4;j++) {
				if (A[j][i]=='X') X++;
				else if (A[j][i]=='O') O++;
				else if (A[j][i]=='T') T++;
			}
			if ( (X==3 && T==1) || X==4) won('X');
			if ( (O==3 && T==1) || O==4) won('O');
		}
		X=T=O=0;
		for (int i=0;i<4;i++) {
			if (A[i][i]=='X') X++;
			else if (A[i][i]=='O') O++;
			else if (A[i][i]=='T') T++;
		}
		if ( (X==3 && T==1) || X==4) won('X');
		if ( (O==3 && T==1) || O==4) won('O');
		X=T=O=0;
		for (int i=0;i<4;i++) {
			if (A[3-i][i]=='X') X++;
			else if (A[3-i][i]=='O') O++;
			else if (A[3-i][i]=='T') T++;
		}
		if ( (X==3 && T==1) || X==4) won('X');
		if ( (O==3 && T==1) || O==4) won('O');
		if (!ok) {
			bool clear=1;
			for (int i=0;i<4;i++) for (int j=0;j<4;j++) if (A[i][j]=='.') clear=0;
			if (clear) printf("Case #%d: Draw\n",n);
			else printf("Case #%d: Game has not completed\n",n);
		}
	}
	scanf("\n");
	return 0;
}
