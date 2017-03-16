#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int tt=1;
int A, N;
int list[101];

void solve() {
	int ans = 101;
	int cnt(0);
	scanf("%d %d", &A, &N);
	for(int i=0; i<N; i++) scanf("%d", &list[i]);
	sort(list, list+N);
	for(int i=0; i<N; i++) {
		ans = min(ans, N-i+cnt);
		if( A > list[i] ) {
			A += list[i];
		} else {
			if( A == 1 ) break;
			while( list[i] >= A ) A+=(A-1), cnt++;
			A += list[i];
		}
		ans = min(ans, N-i-1+cnt);
	}
	printf("Case #%d: %d\n", tt++, A==1? N:ans);
}

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int TC;
	scanf("%d", &TC);
	while(TC-- > 0) solve();
	return 0;
}
