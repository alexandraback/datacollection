#include <cstdio>
#include <cstring>
#include <algorithm>

inline long long max(long long a, long long b) { return a > b? a: b;}

int E, R, N;
long long left[10001];
long long use[10001];
long long ans;


struct act{
	int no, V;
	bool operator<(const act &cmp) const {
		return V > cmp.V;
	}
}Act[10001];

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		memset(use, 0, sizeof(use));
		ans = 0;
		scanf("%d%d%d", &E, &R, &N);
		for(int i = 0; i < N; ++i) {
			scanf("%d", &Act[i].V);
			Act[i].no = i;
		}
		for(int i = 0; i < N; ++i)
			left[i] = E;
		std::sort(Act, Act + N);
		for(int i = 0; i < N; ++i) {
			int now = Act[i].no;
			int nxt = now + 1;
			while(nxt < N && use[nxt] == 0) ++nxt;
			long long lft = E - (nxt - now) * R; 
			if(nxt == N || lft <= 0) 
				use[now] = left[now];
			else 
				use[now] = max(0, left[now] - lft);
			for(int j = now + 1, tmp = R; j < nxt; ++j) {
				if(tmp > E) tmp = E;
				left[j] = tmp;
				tmp += R;
			}
		}
		for(int i = 0; i < N; ++i) {
			ans += use[Act[i].no] * Act[i].V;
			//printf("%d %d %lld %lld\n", Act[i].no, Act[i].V, use[Act[i].no], left[Act[i].no]);
		}
		printf("Case #%d: %lld\n", t, ans);
	}
}
