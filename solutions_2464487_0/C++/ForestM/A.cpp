#include "stdio.h"
#include <math.h>

#define ll long long

int main() {
	FILE *fp, *fp2;
	int num;
	int r, t;
	int p;
	int a;
	int y;

	fopen_s(&fp, "A-small-attempt0.in", "r");
	fopen_s(&fp2, "A-small-attempt0.out", "w");
	fscanf_s(fp, "%d", &num);

	for(int i=0; i<num; ++i) {
		fscanf_s(fp, "%d %d", &r, &t);
		fprintf(fp2,"Case #%d: ",i+1);
		p = t;
		a=r;
		y=0;
		while(t>=2*a+1) {
			t-=(2*a+1);
			++y;
			a+=2;
		}
		fprintf(fp2, "%d\n", y);
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
