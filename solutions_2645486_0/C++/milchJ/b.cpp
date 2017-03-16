#include <cstdio>
#include "string.h"

int dpe[5000][2];

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {

	int T;
	scanf("%d ", &T);
	
	for(int t=0; t<T; ++t) {

		memset(dpe, 0, sizeof(dpe));

		int E, R, N;
		scanf("%d %d %d ", &E, &R, &N);
		dpe[0][0] = E;
		int vi;
		int max=0;
		/*
		for(int j=0; j<=max; ++j) {
			printf("%d ", dpe[j][0]);
		} printf("\n");
		*/ 
		
		for(int i=0; i<N; ++i) {
			scanf("%d ", &vi);
			int nmax=max;
			for(int j=max; j>=0; --j) {
				//printf("schau %d an:\n", j);
				for(int k=0; k<=dpe[j][i%2]; ++k) {
					int nv = j + vi*k;
					if(nv>nmax) nmax=nv;
					int ne = min(dpe[j][i%2] - k + R,E);
					//printf("spend %d nv%d ne%d\n", k, nv, ne);
					if(ne>dpe[nv][(i+1)%2])
						dpe[nv][(i+1)%2] = ne;
				}
			}
			max=nmax;/*
			for(int j=0; j<=max; ++j) {
				printf("%d ", dpe[j][(i+1)%2]);
			} printf("\n");*/
		}	
		printf("Case #%d: %d\n", t+1, max);
	}


	return 0;
}
