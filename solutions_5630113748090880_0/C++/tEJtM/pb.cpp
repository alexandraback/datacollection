#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N(5555);
int cnt[N];
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		int n;
		scanf("%d", &n);
		for(int i(1); i <= 2500; i++) {
			cnt[i] = 0;
		}
		for(int i(1); i <= (2 * n - 1) * n; i++) {
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}
		printf("Case #%d:", qq);
		for(int i(1); i <= 2500; i++) {
			if(cnt[i] % 2 == 1) {
				printf(" %d", i);
			}
		}
		printf("\n");
	}
}
