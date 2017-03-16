#include <bits/stdc++.h>
using namespace std;

FILE *in = fopen("f.in", "r");
FILE *out = fopen("f.out", "w");

bool solve(){
	int X, R, C, N;
	fscanf(in, "%d%d%d", &X, &R, &C);
	
	if(		2 * min(R, C) + 1 - (R == C) <= X 
		|| 	R * C < X 
		|| 	max(R, C) < X
		||  (R * C) % X
		||	(X == 4 && min(R, C) < 3)){
		return true;
	}

	return false;
}

int main(){
	int ntest;
	fscanf(in, "%d", &ntest);
	for(int test = 1; test <= ntest; test++){
		if(solve()){
			fprintf(out, "Case #%d: RICHARD\n", test);
		}
		else{
			fprintf(out, "Case #%d: GABRIEL\n", test);
		}
	}
	return 0;
}