#include <cstdio>
#include <cstring>

const char map[] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 
'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'};
int T;
char s[110], rev[30];

int main(){
	scanf("%d\n", &T);
	for (int i = 0; i < 26; i++) rev[(int)map[i] - 'a'] = (char)('a' + i);
	for (int ca = 1; ca <= T; ca++){
		gets(s); int n = strlen(s);
		for (int i = 0; i < n; i++)
			if (s[i] >= 'a' && s[i] <= 'z') s[i] = rev[s[i] - 'a'];
		printf("Case #%d: %s\n", ca, s);
	}
}
