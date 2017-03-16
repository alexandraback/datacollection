#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_a"
const ldb pi = acos(-1.0);
const int L = (int) 1e6 + 10;
int t, m;
char s[L];

bool isvowel(char c) {
	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

int main() {
	//assert(freopen(taskname".in", "r", stdin));
	//assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%s%d", s, &m);
		int n = strlen(s), conslen = 0, last = -1;
		int64 ans = 0;
		for (int i = 0; i < n; ++i) {
			if (isvowel(s[i]))
				conslen = 0;
			else
				conslen++;
			if (conslen >= m)
				last = i - m + 1;
			if (last != -1)
				ans += last + 1;
		}
		printf("Case #%d: %lld\n", it + 1, ans);
	}	
	return 0;
}