#include <cstdio>
using namespace std;

bool found[10];
int cnt;
void update (int x) {
	while (x) {
		if (!found[x%10]) found[x%10] = 1, ++cnt;
		x/=10;
	}
}

int T, N;
int main () {
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		cnt = 0;
		for (int i=0;i<10;++i) found[i] = 0;
		scanf("%d",&N);
		if (N == 0) {
			printf("Case #%d: INSOMNIA\n",z);
			continue;
		}
		update(N);
		int t = N;
		while (cnt < 10) {
			t += N;
			update(t);
		}
		printf("Case #%d: %d\n",z,t);
	}
	return 0;
}
