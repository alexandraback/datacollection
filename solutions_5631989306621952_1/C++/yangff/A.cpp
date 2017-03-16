#include <cstdio>
#include <cstring>

char buf[1111];
char str[2222];

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		scanf("%s", buf);
		printf("Case #%d: ", cas);
		int head = 1001, tail = 1001;
		str[head] = buf[0];
		int l = strlen(buf);
		
		for (int i = 1; i < l; i++) {
			if (buf[i] >= str[head]) {
				str[--head] = buf[i];
			} else {
				str[++tail] = buf[i];
			}
		}
		for (int i = head; i <= tail; i++)
			printf("%c", str[i]);
		puts("");
	}
}