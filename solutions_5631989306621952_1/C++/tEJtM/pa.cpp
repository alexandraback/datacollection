#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N(1111);
char st[N];
void solve(int le, int ri) {
	int mx(0), mxi;
	for(int i(ri); i >= le; i--) {
		if(st[i] > mx) {
			mxi = i;
			mx = st[i];
		}
	}
	char tmp(st[mxi]);
	for(int i(mxi); i > le; i--) {
		st[i] = st[i - 1];
	}
	st[le] = tmp;
	if(le + 1 <= mxi) {
		solve(le + 1, mxi);
	}
}
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		scanf("%s", st);
		int len(strlen(st));
		solve(0, len - 1);
		printf("Case #%d: %s\n", qq, st);
	}
}
