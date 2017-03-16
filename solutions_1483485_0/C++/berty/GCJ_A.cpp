#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int T;
char s[111];

int main () {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	string a = " abcdefghijklmnopqrstuvwxyz";
	string b = " yhesocvxduiglbkrztnwjpfmaq";
	scanf("%d\n", &T);
	for (int i = 0; i < T; ++i) {
		gets(s);
		int N = strlen(s);
		printf("Case #%d: ", i + 1);
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 27; ++k)
				if (s[j] == a[k])
					printf("%c", b[k]);
		}
		puts("");
	}
}
