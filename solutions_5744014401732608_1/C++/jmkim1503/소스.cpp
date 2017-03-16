#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

int main() {

	int T;
	scanf("%d", &T);

	for (int tt = 1; tt <= T; tt++) {
		printf("Case #%d: ", tt);

		ll B, M;

		scanf("%lld %lld", &B, &M);

		if (pow(2, B - 2) < M) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("POSSIBLE\n");

			ll need_num = pow(2, B - 2) - M;
			queue<int> myQ;

			while (need_num > 0) {
				myQ.push(need_num % 2);
				need_num /= 2;
			}

			for (int i = 1; i <= B; i++) {

				for (int j = 1; j <= i; j++) {
					printf("0");
				}
				for (int j = i + 1; j < B; j++) {
					printf("1");
				}

				if (i == 1) printf("1");
				else if (i == B) {
					printf("\n");
					break;
				}
				else {
					if (myQ.empty()) {
						printf("1");
					}
					else {
						int now = myQ.front();
						myQ.pop();

						if (now == 1) printf("0");
						else printf("1");
					}
				}


				printf("\n");
			}

		}
	}
}