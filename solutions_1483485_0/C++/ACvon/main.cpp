#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

const int N = 26;

char s[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char ed[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
char str[1000];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	int n, i, t, cas = 0;
	scanf("%d", &t);
	gets(str);
	while(t--) {
		gets(str);
		n = strlen(str);
		printf("Case #%d: ", ++cas);
		for(i = 0; i < n; ++i) {
			if(str[i] == ' ')	printf(" ");
			else if(str[i] >= 'a' && str[i] <= 'z')	printf("%c", ed[str[i] - 'a']);
		}
		printf("\n");
	}
	return 0;
}
