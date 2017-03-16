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

void solve(int);
int main() {
	int  T, it=1;
	scanf("%d", &T);
	for(; it<=T; ++it) {
		solve(it);
	}
	return 0;
}

const int NN = 512;
int  N, src[NN];
int  sum[1<<20];
void solve(int case_idx) {
	scanf("%d", &N);
	for(int i=0; i<N; ++i) scanf("%d", src+i);
	int  bit_end = (1<<N)-1;
	map<int, vector<int> >  hash;
	int  ansA=0, ansB=0;
	//memset(sum, 0, sizeof(sum));
	sum[0] = 0;
	for(int i=0; i<N; ++i) sum[1<<i] = src[i];
	for(int bit=1; bit<bit_end; ++bit) {
		int  tt = bit&(bit-1);
		sum[bit] = sum[tt] + sum[bit-tt];
		vector<int>& t = hash[sum[bit]];
		for(size_t i=0; i<t.size(); ++i) {
			if(!(t[i]&bit)) {
				ansA = t[i];
				ansB = bit;
				goto End;
			}
		}
		t.push_back(bit);
	}
 End:
	printf("Case #%d:\n", case_idx);
	if(ansA) {
		int  ff = 1;
		int  bit = ansA;
		for(int i=0; i<N; ++i) if(bit&(1<<i)) {
				if(!ff) putchar(' ');
				printf("%d", src[i]);
				ff = 0;
			}
		putchar('\n');
		ff = 1; bit = ansB;
		for(int i=0; i<N; ++i) if(bit&(1<<i)) {
				if(!ff) putchar(' ');
				printf("%d", src[i]);
				ff = 0;
			}
		putchar('\n');
	}
	else
		puts("Impossible");
}
