#include <stdio.h>

int sx[10] = {0,1,2,3,0,0,0,0,0,0};
int sy[10] = {0,0,0,0,0,1,2,3,0,3};
int dx[10] = {0,0,0,0,1,1,1,1,1,1};
int dy[10] = {1,1,1,1,0,0,0,0,1,-1};
char B[5][5];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test,Case=1;
	int i,k,x,y;

	scanf ("%d",&Test); while (Test--){
		printf ("Case #%d: ",Case++);
		for (i=0;i<4;i++) scanf ("%s",B[i]);

		int dr=0,end=1;
		for (k=0;k<10;k++){
			int oc=0,xc=0,nc=0;
			x = sx[k];
			y = sy[k];
			for (i=0;i<4;i++){
				if (B[x][y] == 'O') oc++;
				if (B[x][y] == 'X') xc++;
				if (B[x][y] == '.') nc++;

				x += dx[k];
				y += dy[k];
			}
			if (nc) end = 0;
			else{
				if (oc >= 3 && xc == 0) dr = 1;
				if (xc >= 3 && oc == 0) dr = 2;
			}
		}

		if (dr == 1) printf ("O won");
		else if (dr == 2) printf ("X won");
		else if (end) printf ("Draw");
		else printf ("Game has not completed");
		printf ("\n");
	}

	return 0;
}