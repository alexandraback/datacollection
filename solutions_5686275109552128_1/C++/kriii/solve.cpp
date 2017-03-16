#include <stdio.h>

int A[1010];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		int N; scanf ("%d",&N);
		for (int i=0;i<N;i++) scanf ("%d",&A[i]);
		
		int ans = 1000;
		for (int x=1000;x>=1;x--){
			int get = 0;
			for (int i=0;i<N;i++){
				get += (A[i] + x - 1) / x - 1;
			}
			if (ans > get + x)
				ans = get + x;
		}

		printf ("Case #%d: ",Case);
		printf ("%d\n",ans);
	}

	return 0;
}