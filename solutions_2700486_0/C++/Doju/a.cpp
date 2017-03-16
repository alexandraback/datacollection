#include <stdio.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");

int t, tt;

double p[3000][3000] = {0,};

int main(){
	fscanf(input, "%d", &t);
	int i, j;
	p[0][0] = 1.0;
	for(i = 1; i < 3000; i++){
		for(j = 0; j <= i; j++){
			if(j-1 >= 0) p[i][j] += p[i-1][j-1]*0.5;
			if(j <= i-1) p[i][j] += p[i-1][j]*0.5;
		}
	}
	for(tt = 1; tt <= t; tt++){
		int a, x, y;
		fscanf(input, "%d%d%d", &a, &x, &y);
		fprintf(output, "Case #%d: ", tt);
		if(x < 0) x *= -1;
		int pd = (x+y)/2*(x+y-1);
		int wp = a-pd;
		double ans = 0.0;
		if(wp > 0){
			if(wp > x+2*y) ans = 1.0;
			else{
				if(x == 0) ans = 0.0;
				else for(i = 0; i <= wp; i++) if((i >= x+y && wp >= x+2*y+1) || (wp-i >= y+1)) ans += p[wp][i];
			}
		}
		else ans = 0.0;

		fprintf(output, "%.7lf\n", ans);
	}
	return 0;
}