#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

//尾部从len-1到0
//尾部为'+' continue
//开头结尾部为'-'时，翻转到尾部
//否则翻转到'-'的前一个

char s[110], buf[110];
int ans;

void flip(int x) {
	for (int i = 0; i <= x; i++) {
		buf[i] = s[i];
	}
	for (int i = 0; i <= x; i++) {
		s[i] = buf[x - i] == '+' ? '-' : '+';
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int kase = 0;
	while (T--) {
		printf("Case #%d: ", ++kase);
		scanf("%s", s);
		int len = strlen(s);
		ans = 0;
		int lastIdx = len;
		while (--lastIdx >= 0) {
			if (s[lastIdx] == '+') continue;
			if (s[0] == '+') {
				ans++;
				for (int i = 1; i <= lastIdx; i++) {
					if (s[i] == '-') {
						flip(i - 1);
						break;
					}
				}
			}
			ans++;
			flip(lastIdx);
		}

		printf("%d\n", ans);
	}
}

