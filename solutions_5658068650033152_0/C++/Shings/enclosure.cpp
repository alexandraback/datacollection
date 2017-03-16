#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#define INPUT "C-small-attempt2.in"
#define OUTPUT "output.out"

int main(int argc, char* argv[]){
	FILE *inf, *outf;

	int TestCase, N;
	int loop1, loop2, loop3;



	inf = fopen(INPUT, "r");
	outf = fopen(OUTPUT, "w+");

	fscanf(inf, "%d ", &TestCase);
	for (loop1 = 0; loop1 < TestCase; loop1++){
		int n, m, k;
		double rec;
		int module;
		int multi;
		fscanf(inf, "%d %d %d", &n, &m, &k);

		k += 4;
		rec = sqrt(k);
		module = (int)rec;
	//	printf("module : %d rec: %lg\n", module, rec);
		if (module - rec>0){
			module++;
		//	printf("module : %d rec: %lg\n", module, rec);
		}

		if (n > m){//m is always larger then n
			int temp = n;
			n = m;
			m = temp;
		}

		if (module > n){
			module = n;
		}
	//	printf("%d %d\n", k, module);
		if (k-4<=m)	fprintf(outf, "CASE #%d: %d\n", loop1 + 1, k-4);
		else if (n == 2)	fprintf(outf, "CASE #%d: %d\n", loop1 + 1, (k - 4) );
		else {
			if (module > 4) module = 4;
			fprintf(outf, "CASE #%d: %d\n", loop1 + 1, ((k / module) + module - 4) * 2 + (k%module));
		}
	}
	fclose(inf);
	fclose(outf);

	return 0;
}