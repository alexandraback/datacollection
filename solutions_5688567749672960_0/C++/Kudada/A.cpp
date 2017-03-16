
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm> 

using namespace std;

#define N_MAX 1000000

#define MAX(a,b) ((a>=b)?(a):(b))
#define MIN(a,b) ((a<b)?(a):(b))

int t;
int ans;
int *buf;

int reverse_int(int n) {

	int reverse = 0;
	while (n != 0) {
		reverse = reverse * 10;
		reverse = reverse + n % 10;
		n  = n/10;
	}

	return reverse;
}

int get_step(int n) {

	if (buf[n] > 0) {
		return buf[n];
	}

	if (n == 1) {
		return 1;
	}
	int n_rev = reverse_int(n);

	if ((n % 10 > 0) && (n_rev < n)) {
		int ret = MIN(get_step(n-1), get_step(n_rev)) + 1;
		buf[n] = ret;
		return ret;
	} else {
		int ret = get_step(n-1) + 1;
		buf[n] = ret;
		return ret;
	}
}


int main(void) {

	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	buf = (int *)malloc(N_MAX*sizeof(int));
	memset(buf, 0, N_MAX*sizeof(int));

	// fill up buf to avoid stack overflow
	for (int i=1; i<N_MAX; i+=100) {
		get_step(i);
	}

	fscanf(fp, "%d", &t);
	for (int tc=1; tc<=t; tc++) {
		fscanf(fp, "%d", &ans);
		ans = get_step(ans);
		fprintf(ofp, "Case #%d: %d\n", tc, ans);
	}

	return 0;
}
