#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define TAM 1000010

int A, N,
	M[101],
	mem[101][TAM];

int dp (int ind, int size) {
	if (mem[ind][size]!=-1)
		return mem[ind][size];
	int res, tam;
	if (ind == N-1)
		res = (size > M[ind] ? 0 : 1);
	else if (size > M[ind]) {
		tam = size+M[ind];
		if (tam > 1000000)
			tam = 1000001;
		res = dp(ind+1, tam);
	}
	else {
		tam = 2*size-1;
		if (tam > 1000000)
			tam = 1000001;
		if (tam > size)
			res = 1+ min( dp(ind+1, size), dp(ind, tam) );
		else
			res = 1+dp(ind+1, size);
	}
	return mem[ind][size] = res;
}

int main() {
	int T, t, res;
	scanf("%d", &T);
	for (t=1 ; t<=T ; t++) {
		scanf("%d%d", &A, &N);
		for (int i=0 ; i<N ; i++)
			scanf("%d", &M[i]);
		memset(mem, -1, sizeof(mem));
		sort(M, M+N);
		res = dp(0,A);
		printf("Case #%d: %d\n", t, res);
	}
	return 0;
}
