#include <stdio.h>

typedef long long LL;

const int L = 1000010;
char str[L];
bool flag[256];

int main()
{
	int T;
	scanf("%d", &T);
	flag['a'] = flag['e'] = flag['i'] = flag['o'] = flag['u'] = true;
	for (int cas = 1; cas <= T; cas++){
		int n;
		scanf("%s%d", str, &n);
		int cur = 0, latex = -1;
		LL ans = 0;
		for (int pos = 0; str[pos]; pos++) {
			char ch = str[pos];	
			if (!flag[ch]) cur++;
			else cur = 0;
			if (cur >= n)
				latex = pos - n + 1;
			if (latex > -1)
				ans += (latex + 1);
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
}
