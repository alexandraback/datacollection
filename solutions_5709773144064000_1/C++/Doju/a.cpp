#include <stdio.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int t;
double c, f, x;
int main(){
	fscanf(input, "%d", &t);
	int tt;
	for(tt = 1; tt <= t; tt++){
		fscanf(input, "%lf%lf%lf", &c, &f, &x);
		double prod = 2;
		double tm = 0;
		for(;;){
			double t1 = x / prod;
			double t2 = c / prod + x / (prod + f);
			if(t1 <= t2){
				tm += t1;
				break;
			}
			tm += c / prod;
			prod += f;
		}
		fprintf(output, "Case #%d: %.7lf\n", tt, tm);
	}
	return 0;
}