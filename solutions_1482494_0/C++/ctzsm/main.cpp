#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct node {
	int a, b;

	bool operator<(const node & k)const {
		if (a == k.a) return b < k.b;
		return a < k.a;
	}
} p[1005];
int T, N;
int state[1005];

bool check() {
	for (int i = 0; i < N; ++i) if (state[i] != 2) return false;
	return true;
}

void solve() {
	scanf("%d", &N);
	memset(state, 0, sizeof (state));
	for (int i = 0; i < N; ++i) scanf("%d%d", &p[i].a, &p[i].b);
	sort(p, p + N);
	int ans = 0, now = 0;
	for (int k = 1; k <= 2 * N; ++k) {
		bool flag = false;
		for (int i = N - 1; i >= 0; --i) {
			if (now >= p[i].b && state[i] == 0) {
				now += 2;
				state[i] = 2;
				ans++;
				flag = true;
			}
		}
		if(flag) continue;
		for (int i = N - 1;i >= 0; --i){
			if (now >= p[i].b && state[i] == 1){
				now += 1;
				state[i] = 2;
				ans++;
				flag = true;
			}
		}
		if(flag) continue;
		for (int i = N - 1;i >= 0; --i){
			if (now >= p[i].a && state[i] == 0){
				now += 1;
				state[i] = 1;
				ans++;
				break;
			}
		}
	}
	if(!check()) printf("Too Bad\n");
	else printf("%d\n",ans);
}

int main(int argc, char** argv) {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}

