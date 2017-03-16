#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXH = 3000;

int N, T;
int f[MAXH];

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d", &T);
	for(int nt = 1; nt <= T; nt++) {
		scanf("%d", &N);
		memset(f, 0, sizeof(f));
		for(int i = 0; i < 2*N-1; i++) {
			for(int j = 0, x; j < N; j++) {
				scanf("%d", &x);
				f[x]++;
			}
		}
		printf("Case #%d: ", nt);
		for(int i = 0; i < MAXH; i++) {
			if(f[i]%2 == 1)
				printf("%d ", i);
		}
		puts("");
	}
}