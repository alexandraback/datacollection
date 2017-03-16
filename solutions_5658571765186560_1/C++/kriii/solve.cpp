#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		int X,R,C; scanf ("%d %d %d",&X,&R,&C);

		if (X >= 7) puts("RICHARD");
		else if (R * C % X) puts("RICHARD");
		else{
			if (R > C) swap(R,C);

			if (X <= 2) puts("GABRIEL");
			else if (X == 3){
				if (R == 1) puts("RICHARD");
				else puts("GABRIEL");
			}
			else if (X == 4){
				if (R <= 2) puts("RICHARD");
				else puts("GABRIEL");
			}
			else if (X == 5){
				if (R <= 2) puts("RICHARD");
				else puts("GABRIEL");
			}
			else if (X == 6){
				if (R <= 3) puts("RICHARD");
				else puts("GABRIEL");
			}
		}
	}

	return 0;
}