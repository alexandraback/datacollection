#include "stdio.h"
#include <math.h>

#define ll long long

int main() {
	FILE *fp, *fp2;
	int num;
	ll r, t;
	ll p;
	ll a;
	long double tmp;
	int y;

	fopen_s(&fp, "A-large.in", "r");
	fopen_s(&fp2, "A-large.out", "w");
	fscanf_s(fp, "%d", &num);

	for(int i=0; i<num; ++i) {
		fscanf_s(fp, "%lld %lld", &r, &t);
		fprintf(fp2,"Case #%d: ",i+1);
		p = t;
		a=r;
		tmp = (2*r-1)/long double(t);
		y=floor(2/(tmp+sqrt(tmp*tmp+8/long double(t))));
		fprintf(fp2, "%d\n", y);
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
