#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	
	for (int z = 1; z <= T; ++z) {
		int K,C,S;
		scanf("%d %d %d", &K, &C, &S);
		
		printf("Case #%d: ", z);
		for (int i = 1; i <= S; ++i) {
			if (i != S) printf("%d ", i);
			else printf("%d\n", i);
		}
	}
}
