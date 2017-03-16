#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
string dig[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
int cnt[10];
int mem[128];
void cal(int n, char c) {
	int t = mem[c];
	string z = dig[n];
	cnt[n] = t;
	rep(k, t) {
		rep(i, z.length()) {
			--mem[z[i]];
		}
	}
}

int main() {
	//freopen("A-large.in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a-ans-small", "w", stdout);
	string s;
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		cin >> s; clr(cnt, 0);
		clr(mem, 0);
		for (int i = 0; i < s.length(); ++i) mem[s[i]]++;
		cal(0, 'Z');
		cal(6, 'X');
		cal(7, 'S');
		cal(8, 'G');
		cal(2, 'W');
		cal(3, 'T');
		cal(5, 'V');
		cal(4, 'F');
		cal(1, 'O');
		cal(9, 'E');
		printf("Case #%d: ", ca++);
		rep(i, 10) {
			rep(j, cnt[i]) printf("%d", i);
		}
		puts("");
	}
	return 0;
}


