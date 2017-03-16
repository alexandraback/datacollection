#include <cstdio>
#include <cstdlib>
#include <cstring>

int T;
int mp[26];
bool used[26];
char s[105];

const char *in = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char *out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

void work()
{
	static int ttt = 0;
	printf("Case #%d: ", ++ttt);
	gets(s);
	for (int i = 0; s[i]; ++i) 
		if (s[i] >= 'a' && s[i] <= 'z')
			printf("%c", mp[s[i] - 'a'] + 'a');
		else
			printf("%c", s[i]);
	printf("\n");
}

int main()
{
	for (int i = 0; i < 26; ++i) mp[i] = -1;
	memset(used, 0, sizeof(used));
	for (int i = 0; in[i]; ++i) {
		mp[in[i] - 'a'] = out[i] - 'a';
		used[out[i] - 'a'] = true;
	}
	int start[3], end[3];
	start[0] = end[0] = 0;
	int countused = 0;
	for (int i = 0; i < 26; ++i) {
		countused += used[i];
		if (!used[i]) end[++end[0]] = i;
	}
	for (int i = 0; i < 26; ++i)
		if (mp[i] == -1) start[++start[0]] = i;
	mp[start[1]] = end[2];
	mp[start[2]] = end[1];
	scanf("%d\n", &T);
	for (; T > 0; --T) work();
}