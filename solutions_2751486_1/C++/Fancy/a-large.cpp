#include <cstdio>
#include <cstring>

const int N = 1000005;

int l, n;
char s[N];

bool vowel(char ch) {
	return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}

long long gao() {
	scanf("%s%d", s, &n);
	l = strlen(s);
	long long ans = 0;
	for(int cnt=0, f=-1, i=0; i<l; ++i) {
		if(vowel(s[i])) {
			cnt = 0;
		} else {
			++cnt;
			if(cnt >= n) {
				f = i-n+1;
			}
		}
		ans += f+1;
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	for(int cas=1; cas<=T; ++cas) {
		printf("Case #%d: %I64d\n", cas, gao());
	}
}
