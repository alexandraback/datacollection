#include <stdio.h>
#include <string.h>
/*
char sin[3][100] = {
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

char sout[3][100] = {
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"
};

int map[26];

void solve(char in[], char out[]) {
	for(int i = 0; in[i]; ++i) {
		if(in[i] == ' ') continue;
		map[in[i] - 'a'] = out[i] - 'a';
	}
}

int main() {
	memset(map, -1, sizeof(map));
	map[25] = 'q' - 'a';
	map['q' - 'a'] = 25;
	for(int i = 0; i < 3; ++i) solve(sin[i], sout[i]);
	for(int i = 0; i < 26; ++i) printf("%c %c\n", 'a' + i, 'a' + map[i]);
	for(int i = 0; i < 26; ++i) printf("%d,", map[i]);
	scanf("%d");
	return 0;
}
*/
int map[26] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
char s[1000];


int main() {
	int t;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	gets(s);
	for(int i = 0; i < t; ++i) {
		gets(s);
		for(int i = 0; s[i]; ++i) {
			if(s[i] != ' ') s[i] = map[s[i] - 'a'] + 'a';	
		}
		printf("Case #%d: ", i + 1);
		puts(s);
	}
	//scanf("%d");
}
