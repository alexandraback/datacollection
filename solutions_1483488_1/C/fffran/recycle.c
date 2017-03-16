#include <stdio.h>
#include <stdlib.h>
inline int digit(int i)
{
//i <10000000
	if(i < 10) return 1;
	if(i < 100) return 2;
	if(i < 1000) return 3;
	if(i < 10000) return 4;
	if(i < 100000) return 5;
	if(i < 1000000) return 6;
	return 7;
}
inline int ten(int i)
{
	if(i  == 1) return 10;
	if(i  == 2) return 100;
	if(i  == 3) return 1000;
	if(i  == 4) return 10000;
	if(i  == 5) return 100000;
	if(i  == 6) return 1000000;
	if(i  == 7) return 10000000;
}
inline int recycle(int a, int len, int digit)
{
	div_t tmp = div(a, ten(len));
	return tmp.quot + tmp.rem*ten(digit-len);
}
int main()
{
	int t, a, b, ind;
	int i, j, k ,res;
	scanf("%d",&t);
	for(ind = 1 ; ind<= t; ind++) {
		scanf("%d%d",&a, &b);
		res = 0;
		for(i = a; i <= b ; i++) {
			int d = digit(i); 
			for(j = 1; j < d; j++) {
				int tt[8];
				int tmp = recycle(i, j, d);
				tt[j] = tmp;
				if(tmp < i && tmp >= a && digit(tmp) == d) {
				   	//printf("%4d %4d\n",i,tmp);
					for(k = 1; k<j;k++)if(tmp ==tt[k])break;
					if(k >= j) res++;
				}
			}
		}
		printf("Case #%d: %d\n",ind, res);
	}
	return 0;
}
