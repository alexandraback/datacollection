#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define taskname "a"
using namespace std;

int n, it;
const int L = 1000;
char s[L];
map<char, char> go;

void work(const char * s1, const char * s2) {
	int n = strlen(s1);
	for (int i = 0; i < n; ++i)
		go[s1[i]] = s2[i];
}

int main() {
	freopen(taskname".in", "r", stdin);
	freopen(taskname".out", "w", stdout);
	work("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	work("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	work("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
	work("qz", "zq");
	scanf("%d\n", &n);
	for (int it = 0; it < n; ++it) {
		fgets(s, L, stdin);
		int n = strlen(s);
		printf("Case #%d: ", it + 1);
		for (int i = 0; i < n; ++i)
			if (go.count(s[i]))
				printf("%c", go[s[i]]);
			else
				printf("%c", s[i]);
	}
	return 0;
}