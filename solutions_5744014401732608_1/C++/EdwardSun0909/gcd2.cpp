#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <climits>
using namespace std;
#define MAXF 120
long long Fibonacci[MAXF];
long long Sum[MAXF];
int main() {
	int T;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++) {
		int B;
		long long M;
		scanf("%d%lld", &B, &M);
		printf("Case #%d:", TT);
		Fibonacci[0] = Sum[0] = 0;
		Fibonacci[1] = Sum[1] = 1;
		int Fi = 1;
		while (Sum[Fi] < M) {
			Fi++;
			Fibonacci[Fi] = 0;
			for (int i = 0; i < Fi; i++)
				Fibonacci[Fi] += Fibonacci[i];
			Sum[Fi] = Sum[Fi - 1] + Fibonacci[Fi];
		}
		if (Fi >= B) {
			printf(" IMPOSSIBLE\n");
		}
		else {
			printf(" POSSIBLE\n");
			bool used[MAXF] = { false };
			for (int i = Fi; i > 0; i--) {
				if (M >= Fibonacci[i]) {
					M -= Fibonacci[i];
					used[i] = true;
				}
			}
			for (int i = 1; i < B; i++) {
				for (int j = 1; j <= i; j++)
					printf("0");
				for (int j = i + 1; j < B; j++)
					printf("1");
				printf((used[i]) ? "1" : "0");
				printf("\n");
			}
			for (int i = 1; i <= B; i++)
				printf("0");
			printf("\n");
		}
	}
}