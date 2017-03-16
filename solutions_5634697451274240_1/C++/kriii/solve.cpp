#include <stdio.h>

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);
		char S[111];
		scanf ("%s",S);
		int L = 0, C = 0;
		while (S[L]) L++;
		for (int i=L-1;i>=0;i--) if (S[i] == '-'){
			for (int j=0;j<=i;j++){
				if (S[j] == '-') S[j] = '+';
				else S[j] = '-';
			}
			C++;
		}
		printf ("%d\n",C);
	}
	return 0;
}