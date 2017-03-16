#pragma comment(linker, "/STACK:36777216")
#include <bits/stdc++.h>
using namespace std;
//----------------------------
#define fori(i, n) for (int i = 0; i < (int)(n); i++)
//FILE *in = fopen("input.txt", "r");
FILE *in = fopen("B-small-attempt1.in", "r");
FILE *out = fopen("output.txt", "w");
const int nMAX = 2505;
int h[nMAX];
//----------------------------
void solve() {
	fori (i, nMAX) {
		h[i] = 0;
	}
	int n, x;
	fscanf(in, "%d", &n);
	for (int i = 0; i < 2*n - 1; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(in, "%d", &x);
			h[x]++;	
		}
	}
	fori(i, nMAX) {
		if (h[i] % 2 == 1) {
			fprintf(out, " %d", i);
		}
	}
	fprintf(out, "\n");
	
}
//----------------------------
int main()
{
	int tn;
  	fscanf(in, "%d", &tn);
  	fori(t, tn) {
	  	fprintf(out, "Case #%d:", t + 1);
    	solve();
  	}
  	fclose(in);
    fclose(out);
  	return 0;
}
