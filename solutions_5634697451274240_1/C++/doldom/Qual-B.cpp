#include <cstdio>
using namespace std;

int main() {
	freopen("qual\\B-large.in", "r", stdin);
	freopen("qual\\B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		char s[101];
		scanf("%s", s);
		int ans = 0, i = 0;
		for (i=1; s[i]; ++i)
			if (s[i] != s[i-1])
				++ans;
		if (s[i-1] == '-') ++ans;
		printf("Case #%d: ", N);
		printf("%d\n", ans);
	}
}