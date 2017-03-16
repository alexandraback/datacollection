#include <stdio.h>
#include <string.h>

#define i64 __int64

const i64 MAX = 100000000000005;

int len;
i64 fs[1005];

bool isPalindrom(i64 a) {
	char str[30];
	int i, j, k;

	sprintf(str, "%I64d", a);
	j = strlen(str) - 1;
	for(i=0; i<=j; i+=1, j-=1) {
		if(str[i] != str[j]) return false;
	}
	return true;
}

void precal() {
	i64 i, j;
	int k = 0;
	for(i=1; i*i<MAX; i+=1) {
		if(isPalindrom(i)) {
			if(isPalindrom(i*i)) {
				fs[k++] = i * i;
			}
		}
	}
	//printf("%d\n", k);
	len = k;
}

int main() {
	freopen("C-large-1.in", "r", stdin);
	//freopen("C-large-1.out", "w", stdout);

	int i, j, k;
	int test, t = 0;
	i64 lw, hg;
	int ans;

	precal();
	scanf("%d", &test);
	while(test--) {
		scanf("%I64d %I64d", &lw, &hg);
		ans = 0;
		for(i=0; i<len; i+=1) {
			if(fs[i]>=lw && fs[i]<=hg) ans += 1;
		}
		printf("Case #%d: %d\n", ++t, ans);
	}
	return 0;
}