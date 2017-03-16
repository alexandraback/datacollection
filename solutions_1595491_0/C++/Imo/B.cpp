#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int case_num;
	scanf("%d", &case_num);
	for (int case_x = 1; case_x <= case_num; case_x++) {
		printf("Case #%d: ", case_x);
		int N, S, p;
		scanf("%d%d%d", &N, &S, &p);
		int A[N];
		for (int i = 0; i < N; i++) scanf("%d", &(A[i]));
		sort(A, A + N);
		reverse(A, A + N);
		int ccc = 0;
		for (int i = 0; i < N; i++) {
			if (p <= (A[i] + 2) / 3) { ccc++; continue; }
			if (p <= (A[i] ? (A[i] + 4) / 3 : 0) && S) { ccc++; S--; continue; }
		}
		printf("%d\n", ccc);
	}
}
