#include <cstdio>
#include <cstring>

const int MAXN = 100 + 5;

char s[MAXN];

char* x[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char* y[] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};


char p[256+5];
char used[256+5];

void init() {

	memset(used, false, sizeof(used));
	memset(p, 0, sizeof(p));


	p['a'] = 'y';
	p['o'] = 'e';
	p['z'] = 'q';
	
	used['y'] = used['e'] = used['q'] = true;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < strlen(x[i]); j++) {
			if(x[i][j] == ' ') continue;
			p[x[i][j]] = y[i][j];
			used[y[i][j]] = true;
		}
	}

	for(char i = 'a'; i <= 'z'; i++) {
		if(p[i] == 0) {
			for(char j = 'a'; j <= 'z'; j++) {
				if(!used[j]) {
					//printf("%c %c\n", i, j);
					p[i] = j;
					
				}
			}
		}
	}



}

void solve() {
	while(true) {
		char c;
		if(scanf("%c", &c) == -1) break;
		if(c == '\r') continue;
		if(c == '\n') break;
		if(c == ' ') printf(" ");
		else printf("%c", p[c]);
	}

}

int main() {

	init();

	int t;
	scanf("%d\n", &t);

	for(int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

}