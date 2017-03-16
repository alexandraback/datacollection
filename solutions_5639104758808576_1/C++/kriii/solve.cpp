#include <stdio.h>

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		int ans = 0, lev = 0, S; char P[1010];
		scanf ("%d %s",&S,P);
		for (int i=0;i<=S;i++){
			if (lev < i) {
				ans += i - lev;
				lev = i;

			}
			lev += P[i] - '0';
		}

		printf ("Case #%d: ",Case);
		printf ("%d\n",ans);
	}

	return 0;
}