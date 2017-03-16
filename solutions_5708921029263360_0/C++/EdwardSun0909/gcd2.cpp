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
		int J, P, S, K;
		scanf("%d%d%d%d", &J, &P, &S, &K);
		printf("Case #%d:", TT);
		if (J*P*K < J*P*S) {
			printf(" %d\n", J*P*K);
			for (int i = 1; i <= J; i++)
				for (int j = 1; j <= P; j++) {
					for (int k = 1; k <= K; k++)
						printf(" %d %d %d\n", i, j, (i + k * j) % S + 1);
				}
		}
		else {
			printf(" %d\n", J*P*S);
			bool flag = true;
			int count = 0;
			for (int i = 1; i <= J; i++) {
				if (flag) 	
					for (int j = 1; j <= P; j++) {
						if (flag)
							for (int k = 1; k <= K; k++) 
								if (flag) {
									printf(" %d %d %d\n", i, j, (i + k * j) % S + 1);
									count++;
									if (count == J*P*S)
										flag = false;
								}
				}
			}
		}
	}
}