#include <bits/stdc++.h>
using namespace std;

FILE *in = fopen("f.in" ,"r");
FILE *out = fopen("f.out", "w");

int N;
char inp[1111];

int solve(){
	fscanf(in, "%d %s", &N, inp);
	int result = 0, have = 0;
	for(int q = 0; q < N + 1; q++){
		if(have < q){
			result += q - have;
			have = q;
		}
		have += inp[q] - '0';
	}

	return result;
}

int main(){
	int ntest;
	fscanf(in, "%d", &ntest);
	for(int test = 1; test <= ntest; test++){
		int result = solve();
		fprintf(out, "Case #%d: %d\n", test, result);
	}
	return 0;
}