#include <stdio.h>
#include <algorithm>
using namespace std;

int T,C,N,S,P,OK[4][111],D[111][111];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i,j,k,l,t,x;

	scanf ("%d\n",&T); while (T--){
		scanf ("%d %d %d",&N,&S,&P);
		for (l=1;l<=N;l++){
			scanf ("%d",&t); OK[0][l] = OK[1][l] = OK[2][l] = OK[3][l] = 0;
			for (i=0;i<=10;i++) for (j=0;j<=10;j++) for (k=0;k<=10;k++){
				if (i + j + k != t) continue;
				x = max(i,max(j,k)) - min(i,min(j,k));
				if (x == 2){
					if (max(i,max(j,k)) >= P) OK[1][l] = 1;
					else OK[0][l] = 1;
				}
				else if (x <= 1){
					if (max(i,max(j,k)) >= P) OK[3][l] = 1;
					else OK[2][l] = 1;
				}
			}
		}

		for (i=0;i<=N;i++) for (j=0;j<=S;j++) D[i][j] = -N*N;
		D[0][0] = 0;
		for (i=1;i<=N;i++){
			if (OK[0][i] == 1) for (j=1;j<=S;j++) D[i][j] = max(D[i][j],D[i-1][j-1]);
			if (OK[1][i] == 1) for (j=1;j<=S;j++) D[i][j] = max(D[i][j],D[i-1][j-1]+1);
			if (OK[2][i] == 1) for (j=0;j<=S;j++) D[i][j] = max(D[i][j],D[i-1][j]);
			if (OK[3][i] == 1) for (j=0;j<=S;j++) D[i][j] = max(D[i][j],D[i-1][j]+1);
		}

		printf ("Case #%d: %d\n",++C,D[N][S]);
	}

	return 0;
}