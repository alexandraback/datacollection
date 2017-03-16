#include <cstdio>

int main() {
	int T;
	char buf[110], s[110];
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%s", buf);
		int cnt = 0;
		for (int i = 0 ; buf[i] ; ++i) {
			if (i == 0 || buf[i] != buf[i-1])
				s[cnt++] = buf[i];
		}
		s[cnt] = 0;
		if (s[cnt-1] == '+') --cnt;
		printf("Case #%d: %d\n", ca, cnt);
	}
	return 0;
}