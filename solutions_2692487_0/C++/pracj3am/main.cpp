#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int ops(vector<int>::iterator it, vector<int>::iterator end, int N, int A) {

	if (A > 1e6) return 0;

	int O = 0;
	while (A <= *it) {
		A += A - 1;
		O++;
		if (O > N) {
			return N;
		}
	}
	if (it != end) {
		O += ops(++it, end, N-1, A + *it);
	}
	if (O > N) {
		return N;
	}
	return O;
}


int
main(void) {
    int N, A, T;
    int i, j;
	int* M;
    
    scanf("%d\n", &T);

    for (i = 0; i < T; i++) {
		scanf(" %d %d", &A, &N);
		M = (int *) malloc(N*sizeof(int));
		for (j=0; j<N; j++) {
			scanf(" %d", M+j);
		}
		vector<int> vM(M, M+N);
		sort(vM.begin(), vM.end());

		printf("Case #%d: %d\n", i+1, ops(vM.begin(), vM.end(), N, A));
		free(M);
    }
}
