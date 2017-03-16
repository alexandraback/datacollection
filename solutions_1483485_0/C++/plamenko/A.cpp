#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

#include <stdint.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char *sp = "a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char *sc = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";

char p2c[256], zp;
char c2p[256], zc;

int main() {
	for (int i = 0; sp[i]; i++) p2c[sp[i]] = sc[i];
	for (int i = 0; sc[i]; i++) c2p[sc[i]] = sp[i];
	for (zc = 'a'; zc <= 'z' && c2p[zc]; zc++);
	for (zp = 'a'; zp <= 'z' && p2c[zp]; zp++);
	c2p[zc] = zp;
	p2c[zp] = zc;

	char g[128];
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf(" %[^\n]", g);
		for (int i = 0; g[i]; i++) g[i] = c2p[g[i]];
		printf("Case #%d: %s\n", t, g);
	}
	
	return 0;
}
