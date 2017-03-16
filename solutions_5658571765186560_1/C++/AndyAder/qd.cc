#include <cstdio>

int main()
{
	FILE *fin, *fout;
	int T, test_case;
	bool possible;
	int X, R, C;

	fin = fopen("D-large.in", "r");
	fout = fopen("output", "w");

	fscanf(fin, "%d", &test_case);
	for(T=1; T<=test_case; T++) {
		possible = false;
		fscanf(fin, "%d %d %d", &X, &R, &C);

		if(X==1) possible = true;
		else if(X==2 && (R*C)%2==0) possible = true;
		else if(X==3 && (R*C)%3==0) {
			if( (R>=3 && C>=2) || (R>=2 && C>=3) ) possible = true;
		}
		else if(X==4 && (R*C)%4==0) {
			if( (R>=4 && C>=3) || (R>=3 && C>=4) ) possible = true;
		}
		// large input
		else if(X==5 && (R*C)%5==0) {
			if( (R>=5 && C>=4) || (R>=4 && C>=5) ) possible = true;
		}
		else if(X==6 && (R*C)%6==0) {
			if( (R>=6 && C>=4) || (R>=4 && C>=6) ) possible = true;
		}

		fprintf(fout, "Case #%d: %s\n", T, possible?"GABRIEL":"RICHARD");
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
