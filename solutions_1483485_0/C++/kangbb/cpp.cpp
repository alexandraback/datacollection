#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int uint64;
#define MAXN 110

char p1[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

char s[MAXN];
char c[26];

int main() {
	c[0] = 'y';
	c[1] = 'h';
	c[2] = 'e';
	c[3] = 's';
	c[4] = 'o';
	c[5] = 'c';
	c[6] = 'v';
	c[7] = 'x';
	c[8] = 'd';
	c[9] = 'u';
	c[10] = 'i';
	c[11] = 'g';
	c[12] = 'l';
	c[13] = 'b';
	c[14] = 'k';
	c[15] = 'r';
	c[16] = 'z';
	c[17] = 't';
	c[18] = 'n';
	c[19] = 'w';
	c[20] = 'j';
	c[21] = 'p';
	c[22] = 'f';
	c[23] = 'm';
	c[24] = 'a';
	c[25] = 'q';

	int cases;
	int caseindex = 0;

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &cases);
	gets(s);
	while (cases--) {
		gets(s);
		for( int i = 0;i < (int)strlen(s); i++){
			if(s[i] != ' ')
				s[i] = c[s[i] - 'a'];
		}
		//scanf("%s", s);
		caseindex++;
		printf("Case #%d: %s\n", caseindex, s);
	}

	return 0;
}
