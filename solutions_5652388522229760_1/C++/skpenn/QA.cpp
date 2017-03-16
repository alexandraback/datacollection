#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;


int main() {
	FILE *fpi, *fpo;
	fpi = fopen("A-large.in", "r");
	fpo = fopen("largeA.out", "w");
	int re;
	fscanf(fpi, "%d", &re);
	for (int co = 1; co <= re; co++) {
		int n;
		fscanf(fpi, "%d", &n);
		int t;
		bool a[10] = { false, false, false, false, false, false, false, false, false, false };
		t = n;
		do {
			int f = t % 10;
			a[f] = true;
			t /= 10;
		} while (t != 0);
		if(2*n==n)fprintf(fpo, "Case #%d: INSOMNIA\n", co);
		else {
			t = n;
			while ((a[0] & a[1] & a[2] & a[3] & a[4] & a[5] & a[6] & a[7] & a[8] & a[9]) != true) {
				t += n;
				int t1 = t;
				do {
					int f = t1 % 10;
					a[f] = true;
					t1 /= 10;
				} while (t1 != 0);
			}
			fprintf(fpo, "Case #%d: %d\n", co, t);
		}

		
	}
	fclose(fpi);
	fclose(fpo);
}