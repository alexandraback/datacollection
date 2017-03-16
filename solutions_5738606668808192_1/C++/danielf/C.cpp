#include <bits/stdc++.h>
using namespace std;


void doit(int N, int &J, int inx, vector<int>& V) {
	if (J == 0) return;
	if (inx == N) { // found one more
		printf("1");
		for (int i = 1; i < N; i++) printf("%d", min(1, V[i] + V[i-1]));
		for (int i = 2; i <= 10; i++) printf(" %d", i+1);
		printf("\n");
		J--;
		return;
	}
	if (inx != 0 && inx != N-2) { // those two can't be 0
		V[inx] = 0;
		doit(N, J, inx + 1, V);
	}
	if (inx == 0 || V[inx-1] == 0) { // can be 1
		V[inx] = 1;
		doit(N, J, inx + 1, V);
	}
}

int main() {
	int N, J;
	scanf("%*d %d %d", &N, &J);
	printf("Case #1:\n");
	vector<int> V(N, 0);
	doit(N, J, 0, V);
	return 0;
}
