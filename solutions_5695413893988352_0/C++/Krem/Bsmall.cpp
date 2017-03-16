#include<cstdio>
#include<cstring>

char C[5], J[5];
char format[] = "%02d %02d\n";

int main() {
	int T; scanf("%d", &T);
	for (int _ = 0; _ < T; _++) {
		scanf(" %s %s", C, J);
		int bc = 0, bj = 0;
		int best = 1000000;
		int max = 1;
		int len = strlen(C);
		for(int i = 0; i < len; ++i)
			max *= 10;
		for(int j = 0; j < max; ++j) {
			int x = j;
			bool bad = 0;
			for (int i = 0; i < len; ++i) {
				if (J[len-i-1] != '?' && J[len-i-1] != x%10+'0') {
					bad = 1;
					break;
				}
				x/=10;
			}
			if (bad) continue;
			for (int c = 0; c < max; ++c) {
				int y = c;
				bool badd = 0;
				for (int i = 0; i < len; ++i) {
					if (C[len-i-1] != '?' && C[len-i-1] != y%10+'0') {
						badd = 1;
						break;
					}
					y/=10;
				}
				if (!badd) {
					int res = c-j;
					res = (res < 0)?(-res):res;
					if (res < best) {
						best = res;
						bc = c;
						bj = j;
					}
				}
			}
		}
		printf("Case #%d: ", _+1);
		format[2] = format[7] = len + '0';
		printf(format, bc, bj);
	}
}
