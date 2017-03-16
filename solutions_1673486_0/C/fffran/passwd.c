#include <stdio.h>
#include <string.h>
float p[100000];
float res;
int main()
{
	int tind, t, a, b;
	int i, j, k;
	scanf("%d", &t);
	for(tind = 1; tind <= t; tind++) {
		float tmp;
		scanf("%d%d",&a,&b);
		res = (float)(b  + b + 2);
		p[0] = 1.0;
		for(i = 1; i <= a; i++) {
			scanf("%f", &tmp);
			p[i] = p[i - 1] * tmp;
		}
		tmp = (float)(b - a + 1) + ( b + 1.0)*(1 - p[a]);
		//printf("1-%f\n",tmp);
		if(tmp < res) res = tmp;
		for(i = 1; i <= a; i++) {
			tmp = (float)(b - a + 1 + 2*i) + (1-p[a-i]) * (b +1.0);
			//printf("2-%f\n",tmp);
			if(tmp < res) res = tmp;
		}
		tmp = b + 2.0;
		//printf("3-%f\n",tmp);
		if(tmp < res) res = tmp;
		printf("Case #%d: %.6f\n", tind , res);
	}
}
