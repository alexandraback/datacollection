#include<iostream>
#include<string>
using namespace std;


int main() {
	FILE *fpi, *fpo;
	fpi = fopen("B-small-attempt0.in", "r");
	fpo = fopen("smallB.out", "w");
	int re;
	fscanf(fpi, "%d", &re);
	for (int co = 1; co <= re; co++) {
		char a[103];
		fscanf(fpi, "%s", a);
		bool flag = true;
		int t = strlen(a);
		int count = 0;
		for (int i = t - 1; i >= 0; i--) {
			bool now = (a[i] == '+');
			if (now^flag) {
				count++;
				flag ^= 1;
			}
		}
		fprintf(fpo, "Case #%d: %d\n", co, count);

	}
	fclose(fpi);
	fclose(fpo);
}