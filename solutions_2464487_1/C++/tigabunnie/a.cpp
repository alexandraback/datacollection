#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
	if (argc!=3) {
		printf("provide input and output file names as command line parameters\n");
	}
	FILE *fp_in, *fp_out;
	if ((fp_in=fopen(argv[1],"r"))==NULL) { printf("can't open file %s\n", argv[1]); exit(1); }
	if ((fp_out=fopen(argv[2],"w"))==NULL) { printf("can't open file %s\n", argv[2]); exit(1); }
	
	int num_cases;
	fscanf(fp_in, "%d\n", &num_cases);
	
	long r, t, rings, incr, paint_needed, paint_needed2, i;
	double paint_float;
	for (int test_case=1; test_case<=num_cases; test_case++) {
		fscanf(fp_in, "%ld %ld\n", &r, &t);
	//	printf("case %d, r %ld t %ld\n", test_case, r, t);
		
		rings = 0;
		for (incr=1000000; incr>=1; incr/=10) {
		
			while (1) {
				paint_needed = 0;
				for (i=0; i<incr; i++) paint_needed += 2*(r+1+2*i) - 1;
			//	paint_needed2 = incr*(2*r+incr);
			//	paint_needed2 = incr + 2*r*incr;
			//	for (i=0; i<incr; i++) paint_needed2 += 4*i;
			//	paint_needed2 = incr + 2*r*incr + 2*incr*(incr-1);
				paint_needed2 = incr*(2*r+2*incr-1);
				paint_float = (2.0*r+2*incr-1)*incr;
				if (paint_float > 1e18) break;	//wrap around
				
			//	if (paint_needed != paint_needed2) { printf("mismatch %ld %ld\n", paint_needed, paint_needed2); }
				if (paint_needed2 > t) break;
			//	printf("incr %ld, paint %ld, t %ld, float %lf\n", incr, paint_needed2, t, paint_float);
				t -= paint_needed2;
				rings += incr;
				r += 2*incr;
			}
		}
		
		fprintf(fp_out, "Case #%d: %ld\n", test_case, rings);		
	}
	
	
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
