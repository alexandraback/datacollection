
#include <cstring>
#include <cstdio>

using namespace std;

const char s1[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char s2[] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char map[26];
	memset(map, ' ', sizeof(map));
	for (int i = 0; i < strlen(s1); i ++)
		if (s1[i] != ' ') map[s1[i] - 'a'] = s2[i];
	for (int i = 0; i < 26; i ++)
		if (map[i] == ' ') {
			bool check[26] = {false};
			for (int j = 0; j < 26; j ++)
				if (map[j] != ' ') check[map[j] - 'a'] = true;
			for (int j = 0; j < 26; j ++)
				if (! check[j]) map[i] = 'a' + j;
		}
	
	int T;
	char str[101];
	scanf("%d", &T);
	gets(str);
	for (int i = 0; i < T; i ++) {
		gets(str);
		int len = strlen(str);
		for (int j = 0; j < len; j ++)
			if (str[j] != ' ') str[j] = map[str[j] - 'a'];
		printf("Case #%d: %s\n", i + 1, str);
	}
	
	return 0;
}
