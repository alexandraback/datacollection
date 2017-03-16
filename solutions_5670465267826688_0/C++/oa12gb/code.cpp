#include <bits/stdc++.h>
using namespace std;

FILE *in = fopen("f.in", "r");
FILE *out = fopen("f.out", "w");


#define MAXL 11111
int L, X, N;
char inp[MAXL];
int dp[MAXL][8][3];
string S;

int getind(char ch){
	switch(ch){
		case '1': return 0;
		case 'i': return 1;
		case 'j': return 2;
		case 'k': return 3;
	}
	return -1;
}

int mult[4][4] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4}
};

// 1 i j k -1 -i -j -k
// 0 1 2 3  4  5  6  7

int doit(int a, int b){
	int ia = a % 4;
	int sa = a >= 4;
	int ib = b % 4;
	int sb = b >= 4;
	int c = mult[ia][ib];
	int ic = c % 4;
	int sc = c >= 4;
	sa += sb + sc;
	if(sa % 2){
		return ic + 4;
	}
	return ic;
}

int f(int i, int l, int p){
	if(i == N){
		if(l == 3 && p == 2){
			return 1;
		}
		return 0;
	}
	int &ret = dp[i][l][p];
	if(ret != -1){
		return ret;
	}
	ret = 0;

	int vi = getind(S[i]);
	if(l == p + 1 && p < 2){
		ret |= f(i + 1, vi, p + 1);
	}
	ret |= f(i + 1, doit(l, vi), p);

	return ret;
}

bool solve(){
	fscanf(in, "%d%d\n%s", &L, &X, inp);
	memset(dp, -1, sizeof dp);
	
	S = "";
	for(int q = 0; q < X; q++){
		S += inp;
	}
	N = L * X;
	return f(0, 0, 0);
}

int main(){
	int ntest;
	fscanf(in, "%d", &ntest);
	for(int test = 1; test <= ntest; test++){
		if(solve()){
			fprintf(out, "Case #%d: YES\n", test);
		}
		else{
			fprintf(out, "Case #%d: NO\n", test);
		}
	}
	return 0;
}