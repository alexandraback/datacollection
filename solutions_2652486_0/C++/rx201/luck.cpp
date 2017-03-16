#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include <queue>
#include <stack>
#include <set>
#include <map>
#include <assert.h>

using namespace std;

void fill(int i, int N, int M, int* c) {
	if (i >= N) {
		return;
	}
	int x;
	if (i ==0)
		x = 2;
	else
		x = c[i-1];
	for(; x<=N; x++){
		c[i] = x;
		fill(i+1, N, M, c);
	}
}

int toindex(int i0, int i1, int i2) {
	return (i0-2)*16 + (i1-2)*4 + (i2-2);
}
void solve(int R, int N, int M, int K, int* p) {
	assert(M==5);
	assert(N==3);
	//assert(K==7);
	int c[3];
	double prob[4*4*4];
	memset(prob ,0, sizeof(prob));
	for(int i0=2; i0<=M; i0++) {
		c[0] = i0;
		for(int i1=2; i1<=M; i1++) {
			c[1] = i1;
			for(int i2=2; i2<=M; i2++) {
				c[2] = i2;
				
				int v[8];
				v[0] = c[0];
				v[1] = c[1];
				v[2] = c[2];
				v[3] = c[0]*c[1];
				v[4] = c[0]*c[2];
				v[5] = c[1]*c[2];
				v[6] = c[0]*c[1]*c[2];
				v[7] = 1;
				double w[8];
				w[0] = 0.5;
				w[1] = 0.5;
				w[2] = 0.5;
				w[3] = 0.25;
				w[4] = 0.25;
				w[5] = 0.25;
				w[6] = 0.125;
				w[7] = 0.125;
				for(int k=0; k<K; k++) {
					bool found = false;
					for(int i=0; i<8; i++) {
						if (p[k] == v[i])
							found = true;
					}
					if (found) {
						prob[toindex(i0, i1, i2)] += 1;
						prob[toindex(i0, i2, i1)] += 1;
						prob[toindex(i1, i0, i2)] += 1;
						prob[toindex(i1, i2, i0)] += 1;
						prob[toindex(i2, i0, i1)] += 1;
						prob[toindex(i2, i1, i0)] += 1;
					}
				}
				
			}
		}
	}
	int maxi = -1;
	for(int v=0; v<4*4*4; v++)
		if(maxi == -1 || prob[v] > prob[maxi]) maxi = v;
		
	int i0 = maxi / 16 + 2;
	int i1 = (maxi / 4) % 4 + 2;
	int i2 = maxi % 4 + 2;
	printf("%d%d%d\n", i0, i1, i2);
}

int main(int argc, char* argv[]) {
	int T;
	setbuf(stdout, NULL);
	
	//FILE* f = fopen(argv[1], "rt");
	//fscanf(f, "%d\n", &T);
	scanf("%d\n", &T);
	
	printf("Case #%d:\n", 1);
	for(int t=0; t<T; t++) {
		int R, N, M, K;
		//fscanf(f, "%d", &N);
		scanf("%d %d %d %d", &R, &N, &M, &K);
		
		for(int i=0; i<R; i++) {
			int p[1000];
			for(int j=0; j<K; j++) {
				scanf("%d", &p[j]);
			}
			solve(R, N, M, K, p);
		}
	}
	//fclose(f);
	return 0;
}
