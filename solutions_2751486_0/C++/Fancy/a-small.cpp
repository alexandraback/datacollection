#include <cstdio>
#include <cstring>

int l, n;
char s[105];

bool vowel(char ch) {
	return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}

bool check(int i, int j) {
	for(int cnt=0, k=i; k<=j; ++k) {
		if(vowel(s[k])) {
			cnt = 0;
		} else {
			++cnt;
			if(cnt >= n) return true;
		}
	}
	return false;
}

int gao() {
	scanf("%s%d", s, &n);
	l = strlen(s);
	int ans = 0;
	for(int i=0; i<l; ++i) {
		for(int j=i; j<l; ++j) {
			if(check(i, j)) ++ans;
		}
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	for(int cas=1; cas<=T; ++cas) {
		printf("Case #%d: %d\n", cas, gao());
	}
}
