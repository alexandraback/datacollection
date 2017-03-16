#include <stdio.h>
inline int max(int a, int b)
{
	return a>b?a:b;
}
int main()
{
	int t, s, p, n , i, ind, res, g;
	int lb1 , lb2;
	scanf("%d", &t);
	for(ind = 1; ind <= t; ind++) {
		scanf("%d %d %d", &n, &s, &p);
		res = 0; 
		lb1 = (p-1>=0) ?( 3*p -2): p; 
		lb2 = (p-2>=0)? (3*p -4) : lb1;
		for(i = 0; i < n ; i++) {
			scanf("%d", &g);
			if(g >= lb1) res++;
			else if(s > 0 && g >= lb2){
					res++;
					s--;
			}
		}

		printf("Case #%d: %d\n",ind, res);
	}
	return 0;
}

