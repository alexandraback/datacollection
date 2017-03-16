#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define x first
#define y second
typedef pair<int, int> ii;
typedef long long int ll;

int N, T, X, Y, k, K;
double memo[2020][2020];
bool vst[2020][2020];

double DP(int lf, int rt, int dep) {
	//printf("%d %d %d %d\n", N, dep, lf, rt);
	if (vst[lf][rt]) return memo[lf][rt];
	vst[lf][rt] = true;
	//printf("%d %d %d %d\n", N, dep, lf, rt);
	if (lf+rt>K) return memo[lf][rt] = 0.0;
	if (Y<rt) return memo[lf][rt] = 1.0;
	if (lf==2*k) return memo[lf][rt] = DP(lf, rt+1,dep+1);
	return memo[lf][rt] = (DP(lf+1,rt,dep+1)+DP(lf,rt+1,dep+1))/2;
}
	
	

int main() {
	//FILE* fin = fopen("data.txt", "r");
	FILE* fin = fopen("B-small-attempt2.in", "r");
	FILE* fout = fopen("answer.txt", "w");
	fscanf(fin, "%d", &T);
	REP(mm, T) {
		fprintf(fout, "Case #%d: ", mm+1);
		fscanf(fin, "%d%d%d", &N, &X, &Y);
		X = (X<0)? -X : X;
		k = (X+Y)/2;
		K = N-(2*k-1)*k;
		if (K<=0) fprintf(fout, "0.0\n");
		else if (K>=4*k+1) fprintf(fout, "1.0\n");
		else if (Y==2*k) fprintf(fout, "0.0\n");
		else {
			REP(i, 2*k+4) memset(vst[i], false, 2*k+4);
			fprintf(fout, "%lf\n", DP(0,0,0));
		}
	}
}
