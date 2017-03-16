#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

char map[] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
char s[200];

int main() {
	int n, i, j, l;
	
	scanf("%d\n", &n);
	for (i=0; i<n; i++) {
		gets(s);
		l = strlen(s);
		for (j=0; j<l; j++)
			if (isalpha(s[j]))
				s[j] = map[s[j]-'a'];
		printf("Case #%d: %s\n", i+1, s);
	}

	return 0;
}
