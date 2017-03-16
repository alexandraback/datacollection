#include <cstdio>
#include <cstring>

const char pro[26] = {
	'y', 'h', 'e', 's', 'o', 'c', 'v', 
	'x', 'd', 'u', 'i', 'g', 'l', 'b', 
	'k', 'r', 'z', 't', 'n', 'w', 
	'j', 'p', 'f', 'm', 'a', 'q'};
	

int casei, cases;
char st[200];

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d", &cases);
	gets(st);
	for (casei = 1; casei <= cases; ++casei) {
		gets(st);
		int len = strlen(st);
		for (int i = 0; i < len; ++i) 
			if (st[i] >= 'a' && st[i] <= 'z') st[i] = pro[st[i] - 'a'];
		printf("Case #%d: %s\n", casei, st);
	}
	return 0;
}
