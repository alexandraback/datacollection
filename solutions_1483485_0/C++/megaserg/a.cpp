#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long int64;
typedef long double ldouble;

#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)

#define PROBLEM "A"

const string x = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv zq";
const string y = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up qz";

const int MAXL = 128;
char s[MAXL];

int main() {
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);

		gets(s);
		int n = strlen(s);
		string a = "";
		for (int i = 0; i < n; i++) {
			char c = '?';
			for (int k = 0; k < (int) x.size(); k++) {
				if (x[k] == s[i]) {
					c = y[k];
					break;
				}
				
			}
			a.PB(c);
		}
		cout << a;

		printf("\n");
	}

	return 0;
}
