#include <stdio.h>

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d:",Case);
		int K,C,S; scanf ("%d %d %d",&K,&C,&S);
		int n = (K + C - 1) / C;
		if (n <= S){
			long long u[111] = {0,};
			for (int i=0;i<C*n;i++){
				int g = i / C;
				u[g] = u[g] * K + i % K;
			}
			for (int i=0;i<n;i++) printf (" %lld",u[i]+1);
			puts("");
		}
		else puts(" IMPOSSIBLE");
	}
	return 0;
}