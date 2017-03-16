#include <cstdio>


const int N = 10000 + 10;

int n, x;
char str[N];

inline int convert(int x, char ch) {
	int o, s, ret;
	if (x > 3) o = 4, s = x - 4; else o = 0, s = x;
	
	if (s == 0) {
		switch (ch) {
			case 'i': ret = 1; break;
			case 'j': ret = 2; break;
			case 'k': ret = 3; break;
		}
	}
	else if (s == 1) {
		switch (ch) {
			case 'i': ret = 4; break;
			case 'j': ret = 3; break;
			case 'k': ret = 6; break;
		}
	}
	else if (s == 2) {
		switch (ch) {
			case 'i': ret = 7; break;
			case 'j': ret = 4; break;
			case 'k': ret = 1; break;	
		}
	}
	else if (s == 3) {
		switch (ch) {
			case 'i': ret = 2; break;
			case 'j': ret = 5; break;
			case 'k': ret = 4; break;
		}
	}
	
	ret = (ret + o) % 8;
	return ret;
}

inline bool Work() {
	scanf("%d %d %s ", &n, &x, str);
	
	int times = x % 4, ans = 0;
	if (x > 4) times += 4;
	bool flag1 = false, flag2 = false;
	
	for (int i = 0; i < times; ++i)
		for (int j = 0; j < n; ++j) {
			ans = convert(ans, str[j]);
		//	printf("%c %d\n", str[j], ans);
			if (flag1) {
				if (!flag2 && ans == 3) flag2 = true;
			}
			else {
				if (ans == 1) flag1 = true;
			}
		}
	
	return flag1 && flag2 && ans == 4;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	int T; scanf("%d ", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		puts(Work()? "YES": "NO");
	}
	
	return 0;
}
