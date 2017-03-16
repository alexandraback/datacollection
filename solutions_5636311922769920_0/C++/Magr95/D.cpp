#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	freopen("D-small-attempt0.in.txt", "r", stdin);
	//freopen("D-large-practice.in", "r", stdin);
	freopen("small.out", "w", stdout);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int K, C, S;
		cin >> K >> C >> S;
		printf("Case #%d:", i);
		for (int i = 1; i <= S; i++) printf(" %d", i);
		printf("\n");
	}
	return 0;
}