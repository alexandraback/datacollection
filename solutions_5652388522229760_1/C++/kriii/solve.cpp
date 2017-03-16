#include <stdio.h>

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		int N; scanf ("%d",&N);
		if (!N) puts("INSOMNIA");
		else{
			int c = 0;
			for (long long i=1;;i++){
				long long t = i * N;
				while (t){
					c |= 1 << (t % 10);
					t /= 10;
				}
				if (c == 1023){
					printf ("%lld\n",i*N);
					break;
				}
			}
		}
	}
	return 0;
}