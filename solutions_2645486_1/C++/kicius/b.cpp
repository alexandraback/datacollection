#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

long long int E, R, V[400000];
int N;
long long int zlicz(long long int *first, long long int *last, long long int start, long long int stop) {
	if (first==last) return 0ll;
long long res=0;
	long long int *cur=max_element(first, last);
	long long int masz=min(start+(cur-first)*R, E);
	long long int zostaw=max(stop-(last-cur)*R, 0ll);
	res+=(*cur)*(masz-zostaw);
	res+=zlicz(first, cur, start, masz);
	res+=zlicz(cur+1, last, zostaw+R, stop);
	return res;
}


int main() {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%lld %lld %d", &E, &R, &N);
		for (int n=0; n<N; n++) scanf("%lld", V+n);
		printf("Case #%d: %lld\n", t, zlicz(V, V+N, E, R));
	}
	return 0;
}

