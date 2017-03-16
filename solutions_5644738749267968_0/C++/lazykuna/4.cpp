#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

FILE *fp, *fout;

double arr[2][1500];
int f[2], r[2];
int bcnt;
int res[2];
int ind = 0;

void dodwar() {
}

void dowar(int t1, int t2) {
	int i;
	for (i=0; i<2; i++) {
		f[i] = 0;
		r[i] = bcnt-1;
	}
	res[t1] = 0;

//	double a = arr[t2][ r[t2] ];	// biggest of t2
//	printf("%lf\n", a);
	while (f[t2] <= r[t2]) {
		//printf("%lf, %lf\n", arr[t2][ r[t2] ], arr[t1][ r[t1] ]);
		if (arr[t2][ r[t2] ] > arr[t1][ r[t1] ]) {
			r[t2] --;
			r[t1] --;
			if (t1==1) res[t1] ++;
		} else {
			f[t2]++;
			r[t1]--;
			if (t2==1) res[t1]++;
		}	
	}
}

void printans() {
	ind++;
	fprintf(fout, "Case #%d: %d %d\n", ind, res[1],res[0]);
}

int main() {
	fp = fopen("4.input", "r");
	fout = fopen("4.output", "w");
	
	int cnt=0;
	fscanf(fp, "%d", &cnt);
	
	for (int i=0; i<cnt; i++) {
		fscanf(fp, "%d", &bcnt);
		for (int j=0; j<2; j++) {
			for (int k=0; k<bcnt; k++) {
				fscanf(fp, "%lf", &arr[j][k]);
				//printf("%lf\n", arr[j][k]);
			}
			std::sort(&arr[j][0], &arr[j][bcnt]);
		}
		dowar(1,0);
		dowar(0,1);
		printans();
	}

	fclose(fp);
	fclose(fout);

	return 0;
}
