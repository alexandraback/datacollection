#include <stdio.h>

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d:\n",Case);
		int N = 16, J = 50, C = 0;
		for (int i=0;i<(1<<(N/2-2));i++){
			int u = (1 << (N/2-1)) + i * 2 + 1;
			
			for (int j=N/2-1;j>=0;j--) printf ("%d",(u&(1<<j)) > 0);
			for (int j=N/2-1;j>=0;j--) printf ("%d",(u&(1<<j)) > 0);

			for (int b=2;b<=10;b++){
				long long tu = u, s = 0, p = 1;
				while (tu){
					s += (tu % 2) * p;
					p *= b;
					tu /= 2;
				}
				printf (" %lld",s);
			}
			puts("");
			if (++C == J) break;
		}
	}
	return 0;
}