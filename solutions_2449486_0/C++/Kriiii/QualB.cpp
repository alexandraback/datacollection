#include <stdio.h>

int N,M,B[101][101];

bool can()
{
	int i,j,k,h;

	for (h=1;h<=100;h++){
		for (i=0;i<N;i++) for (j=0;j<M;j++){
			if (B[i][j] == h){
				for (k=0;k<M;k++) if (B[i][k] != h) break;
				if (k == M) continue;
				for (k=0;k<N;k++) if (B[k][j] != h) break;
				if (k == N) continue;
				return false;
			}
		}
		for (i=0;i<N;i++) for (j=0;j<M;j++) if (B[i][j] == h) B[i][j] = h+1;
	}
	return true;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test,Case=1;
	int i,j;
	scanf ("%d",&Test); while (Test--){
		printf ("Case #%d: ",Case++);
		scanf ("%d %d",&N,&M);
		for (i=0;i<N;i++) for (j=0;j<M;j++) scanf ("%d",&B[i][j]);
		puts(can()?"YES":"NO");
	}

	return 0;
}