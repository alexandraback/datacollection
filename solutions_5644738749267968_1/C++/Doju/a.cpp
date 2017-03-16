#include <stdio.h>
#include <algorithm>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int t;
double p[1010] = {0,};
double q[1010] = {0,};
int ch[1010] = {0,};
int a;
int main(){
	fscanf(input, "%d", &t);
	int tt;
	for(tt = 1; tt <= t; tt++){
		fscanf(input, "%d", &a);
		int i, j;
		for(i = 0; i < a; i++) fscanf(input, "%lf", &p[i]);
		for(i = 0; i < a; i++) fscanf(input, "%lf", &q[i]);
		std::sort(p, p+a);
		fprintf(output, "Case #%d: ", tt);
		int c = 0;
		for(i = 0; i < a; i++){
			double min = 2.0, max = -1.0;
			for(j = 0; j < a; j++){
				if(ch[j] == 1) continue;
				if(q[j] < min) min = q[j];
				if(q[j] > max) max = q[j];
			}
			if(min < p[i]){
				c++;
				for(j = 0; j < a; j++) if(q[j] == min) ch[j] = 1;
			}
			else{
				for(j = 0; j < a; j++) if(q[j] == max) ch[j] = 1;
			}
		}
		fprintf(output, "%d ", c);
		for(i = 0; i < a; i++) ch[i] = 0;
		c = 0;
		for(i = 0; i < a; i++){
			double min = 2.0, min1 = 2.0;
			for(j = 0; j < a; j++){
				if(ch[j] == 1) continue;
				if(q[j] > p[i] && q[j] < min1) min1 = q[j];
				if(q[j] < min) min = q[j];
			}
			if(min1 == 2.0){
				c++;
				for(j = 0; j < a; j++) if(q[j] == min) ch[j] = 1;
			}
			else{
				for(j = 0; j < a; j++) if(q[j] == min1) ch[j] = 1;
			}
		}
		fprintf(output, "%d\n", c);
		for(i = 0; i < a; i++) ch[i] = 0;
		c = 0;
	}
	return 0;
}