#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

struct line {
	int * line;
};

bool comp (line l1, line l2) { 
	for (int i=0; l1.line[i] >= 0 && l2.line[i] >= 0; i++)
		if (l1.line[i] != l2.line[i])
			return l1.line[i] < l2.line[i];
	return true;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int N;
		scanf("%d", &N);

		line lists[2*N-1];
		int matrix[N][N];

		for (int i=0; i<2*N-1; i++) {

			lists[i].line = new int[N+1];
			for (int j=0; j<N; j++) {
				scanf("%d", &lists[i].line[j]);
			}
			lists[i].line[N] = -1;
		}

		sort(lists, lists + 2*N-1, comp);

		for (int j=0; j<N; j++) {
			matrix[0][j] = lists[0].line[j];
			matrix[j][0] = lists[1].line[j];
		}

		int l = 1, r = 1;
		for (int i=2; i<2*N-1; i++) {
			
		}

		for (int i=0; i<2*N-1; i++) {
			for (int j=0; j<N; j++) {
				printf ("%d ", lists[i].line[j]);
			}
			printf("\n");
		}



		printf("Case #%d: %d\n", iC, 0);
	}
	return 0;
}