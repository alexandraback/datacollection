#include <cstdio>
#include <cstring>
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t;
	char s[110];
	int ans = 0, i;
	scanf("%d", &t);
	gets(s);
	int len;
	for(int x = 1;x<=t;++x) {
		gets(s);
		ans = 0;
		len = strlen(s);
		while(true) {
			bool flag = true;
			for(i = 0;i<len;++i) {
				if(s[i] == '-')	
					flag = false;
			}
			if(flag)
				break;
			for(i = len - 1;i>=0;--i)
				if(s[i] == '-')
					break;
			++ans;
			for(int j = 0;j<=i;++j) {
				if(s[j] == '-')
					s[j] = '+';
				else
					s[j] = '-';
			}
		}
		printf("Case #%d: %d\n", x, ans);
	}
	
}
