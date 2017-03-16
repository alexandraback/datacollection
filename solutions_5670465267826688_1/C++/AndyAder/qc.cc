#include <cstdio>

int t[5][5] = {
		0, 0, 0, 0, 0,
		0, 1, 2, 3, 4,
		0, 2,-1, 4,-3,
		0, 3,-4,-1, 2,
		0, 4, 3,-2,-1
};

int mul(int a, int b) {
	int neg = 1;
	if(a<0) { neg = -1; a = -a; }
	return neg*t[a][b];
}

int main()
{
	FILE *fin, *fout;
	int T, test_case;
	long L, X;
	char input[10001];
	int i_res, j_res, k_res;
	int OK;

	fin = fopen("C-large.in", "r");
//	fin = fopen("C-small-attempt0.in", "r");
//	fin = fopen("C-large.sample.in", "r");
	fout = fopen("output", "w");

	fscanf(fin, "%d", &test_case);
	for(T=1; T<=test_case; T++) {
		i_res = j_res = k_res = 1;
		OK = 0;
		fscanf(fin, "%ld %ld", &L, &X);
		fscanf(fin, "\n%s", input); // for the small input
		if(X >= 8) {
			X %= 8;
			X += 8;
		}
		if(X==0) {
			fprintf(fout, "Case #%d: NO\n", T);
			continue;
		}
		int i=0, j=0;
		long LX = L*X;
		while(X!=1 || i<L) {
			if(i==L) { X--; i=0; }
			i_res = mul(i_res, input[i]-'i'+2);
			if(i_res == 2) break;
			i++;
		}
		i++;
		while(X!=1 || i<L) {
			if(i==L) { X--; i=0; }
			j_res = mul(j_res, input[i]-'i'+2);
			if(j_res == 3) break;
			i++;
		}
		i++;
		while(X!=1 || i<L) {
			if(i==L) { X--; i=0; }
			k_res = mul(k_res, input[i]-'i'+2);
			i++;
		}
		if(i==L && k_res==4) OK=1;

		fprintf(fout, "Case #%d: %s\n", T, OK?"YES":"NO");
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
