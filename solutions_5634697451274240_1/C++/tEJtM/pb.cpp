#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char st[11111];
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		scanf("%s", st);
		int len(strlen(st));
		st[len] = '+';
		int ans(0);
		for(int i(0); i < len; i++) {
			ans += st[i] != st[i + 1];
		}
		printf("Case #%d: %d\n", qq, ans);
	}
}
