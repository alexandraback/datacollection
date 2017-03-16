#include <stdio.h>

FILE *in, *out;
double c, f, x, rate, elapsed;

int bestchoice() {
	double direct = x / rate;
	double indirect = c / rate;
	if(indirect + x / (rate + f) < direct) {
		elapsed += indirect;
		rate += f;
		return 1;
	}
	else {
		elapsed += direct;
		return 0;
	}
}

void runtestcase(int caseno) {
	fscanf(in, "%lf %lf %lf", &c, &f, &x);
	rate = 2.0, elapsed = 0.0;
	while(bestchoice())
		;
	fprintf(out, "Case #%i: %lf\n", caseno, elapsed);
}

void main(int argc, char *argv[]) {
	in = fopen(argv[1], "r");
	out = fopen("cookie.out", "w");
	int t;
	fscanf(in, "%i", &t);
	int i;
	for(i = 0; i < t; i++) {
		runtestcase(i+1);
	}
}