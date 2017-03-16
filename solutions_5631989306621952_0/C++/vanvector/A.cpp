#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
#include <map>
#include <set>
#include <list>
#include <iostream>

using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const lli LINF = 0x3f3f3f3f3f3f3f3f;

//#define _LOCAL_DEBUG_
#ifdef _LOCAL_DEBUG_
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...) 
#endif

void clear() {
}

void solve(int t) {
	string s;
	cin >> s;
	string ts = "";
	for (int i = 0; i < s.size(); i++) {
		string s1 = ts, s2 = ts;
		s1 += s[i];
		s2.insert(0, 1, s[i]);
		if (s1 > s2) ts = s1;
		else ts = s2;
	}
	cout << "Case #" << t << ": " << ts << endl;
}

int main() {
#ifdef _LOCAL_VAN
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		clear();
		solve(i + 1);
	}
	return 0;
}