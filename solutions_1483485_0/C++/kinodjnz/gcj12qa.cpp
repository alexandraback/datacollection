#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

/*
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
 */

int main(int argc, char *argv[])
{
	char b[200];
	//          abcdefghijklmnopqrstuvwxyz
	char d[] = "yhesocvxduiglbkrztnwjpfmaq";
	if (argc >= 2) {
		int T;
		char ss[30][200];
		gets(b);
		sscanf(b, "%d", &T);
		for (int i = 0; i < T; i++) {
			gets(ss[i]);
		}
		char m[30];
		memset(m, -1, sizeof(m));
		for (int i = 0; i < T; i++) {
			gets(b);
			for (int j = 0; ss[i][j]; j++) {
				if (ss[i][j] != ' ') {
					if (m[ss[i][j]-'a'] == -1) {
						m[ss[i][j]-'a'] = b[j];
					} else if (m[ss[i][j]-'a'] != b[j]) {
						printf("mismatch: ss[%d][%d]=%c b[%d]=%c m=%c\n",
							   i, j, ss[i][j], j, b[j], m[ss[i][j]-'a']);
					}
				}
			}
		}
		for (int j = 0; j < 26; j++) {
			if (m[j] == -1) {
				printf("?");
			} else {
				printf("%c", m[j]);
			}
		}
		printf("\n");
		return 0;
	}
	int T;
	gets(b);
	sscanf(b, "%d", &T);
	for (int i = 0; i < T; i++) {
		gets(b);
		printf("Case #%d: ", i+1);
		for (int j = 0; b[j]; j++) {
			if (b[j] == ' ')
				printf(" ");
			else
				printf("%c", d[b[j]-'a']);
		}
		printf("\n");
	}
	return 0;
}
