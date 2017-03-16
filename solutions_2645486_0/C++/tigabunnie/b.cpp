#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define N_MAX 10000

int main(int argc, char **argv) {
	if (argc!=3) {
		printf("provide input and output file names as command line parameters\n");
	}
	FILE *fp_in, *fp_out;
	if ((fp_in=fopen(argv[1],"r"))==NULL) { printf("can't open file %s\n", argv[1]); exit(1); }
	if ((fp_out=fopen(argv[2],"w"))==NULL) { printf("can't open file %s\n", argv[2]); exit(1); }
	
	int num_cases;
	fscanf(fp_in, "%d\n", &num_cases);
	
	long E, R, N, i, j, max_so_far, max_index, gain, e_spend, regen, req;
	long *v = new long [N_MAX];
	long *e_required = new long [N_MAX];
	long *e_available = new long [N_MAX];
	char *visited = new char [N_MAX];
	for (int test_case=1; test_case<=num_cases; test_case++) {
		fscanf(fp_in, "%ld %ld %ld\n", &E, &R, &N);
		for (i=0; i<N; i++) fscanf(fp_in, "%ld", &(v[i]));
		
		for (i=0; i<N; i++) e_required[i] = 0;
		for (i=0; i<N; i++) e_available[i] = E;
		for (i=0; i<N; i++) visited[i] = 0;
		
		
		gain = 0;
		for (i=0; i<N; i++) {
			max_so_far = 0;
			max_index = 0;
			for (j=0; j<N; j++) {
				if (v[j] > max_so_far && visited[j]==0) {
					max_so_far = v[j];
					max_index = j;
				}
			}
			visited[max_index] = 1;
			
			e_spend = e_available[max_index] - e_required[max_index];
			if (e_spend > 0)
				gain += e_spend * v[max_index];
			
			j = max_index+1;
			regen = R;
			while (j<N) {
				if (e_available[j] > regen) {
					e_available[j] = regen;
					regen += R;
					j++;
				}
				else break;
			}
			
			j = max_index-1;
			req = e_available[max_index]-R;
			while (j>=0) {
				if (e_required[j] < req) {
					e_required[j] = req;
					req -= R;
					j--;
				}
				else break;
			}
		}
		
		
		
		fprintf(fp_out, "Case #%d: %ld\n", test_case, gain);		
	}
	
	
	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
