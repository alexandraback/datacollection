#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int cmap[256];
char str[1024];

string a0 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
string b0 = "our language is impossible to understand";

string a1 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string b1 = "there are twenty six factorial possibilities";

string a2 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
string b2 = "so it is okay if you want to just give up";

void gao(string a, string b) {
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] != ' ') {
			cmap[a[i]] = b[i];
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	gao(a0, b0);
	gao(a1, b1);
	gao(a2, b2);
	cmap['q'] = 'z';
	cmap['z'] = 'q';
	int cas;
	scanf("%d%*c", &cas);
	for (int c = 1; c <= cas; ++c) {
		gets(str);
		printf("Case #%d: ", c);
		for (int i = 0; str[i]; ++i)
			printf("%c", (str[i] >= 'a' && str[i] <= 'z') ? cmap[str[i]] : str[i]);
		puts("");
	}

	return 0;
}