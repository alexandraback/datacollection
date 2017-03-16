#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <iostream>
using namespace std;

FILE* fin = stdin;
FILE* fout = stdout;


int  N;
typedef vector<int> VI;
VI  src;
double g[1024];

bool OK(int idx, double xx) {
	int  sum = accumulate(src.begin(), src.end(), 0);
	double  val = src[idx] + xx * sum;
	int  n = 0;
	for(int i=0; i<N; ++i) if(i != idx) {
			g[n++] = src[i];
		}
	double  rem = sum - xx*sum;
	if(n == 1) {
		return rem + g[0] <= val;
	}
	while(rem > 1e-12) {
		sort(g, g+n);
		if(g[0]+1e-12 >= g[n-1]) {
			g[0] += rem / n;
			rem = 0;
			break;
		}
		int  ii = 1;
		for(; ii<n; ++ii) {
			if(g[0]+1e-12 < g[ii]) break;
		}
		double  tmp = (g[ii] - g[0]) * ii;
		if(tmp >= rem) {
			g[0] += rem / ii;
			break;
		}
		for(int k=0; k<ii; ++k) g[k] = g[ii];
		rem -= tmp;
	} return g[0] <= val;
}

double calc(int idx) {
	double lo=0, hi=1.0, mi=0;
	for(int kk=0; kk<100; ++kk) {
		mi = (lo + hi) * 0.5;
		if(OK(idx, mi))
			hi = mi;
		else
			lo = mi;
	} return hi*100.0;
}

void go(int case_idx) {
	src.clear();
	fscanf(fin, "%d", &N);
	for(int i=0; i<N; ++i) {
		int v; fscanf(fin, "%d", &v);
		src.push_back(v);
	}
	//	int  sum = accumulate(v.begin(), v.end(), 0);
	fprintf(fout, "Case #%d:", case_idx);


	for(int i=0; i<N; ++i) {
		fprintf(fout, " %.12f", calc(i));
	}
	
	fprintf(fout, "\n");
}

int main() {
	
	int  T; fscanf(fin, "%d", &T);
	int  it=1;
	for(; it<=T; ++it) {
		go(it);
	}
	return 0;
}
