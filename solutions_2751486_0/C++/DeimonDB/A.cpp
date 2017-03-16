#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

char S[1000005];

inline void transform (char *s) {
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') s[i] = '0';
		else s[i] = '1';
	}
}

inline void solve(int tc) {
	int N;
	scanf("%s %d", S, &N);
	transform(S);
	int start = 0, end = 0;
	int pjg = strlen(S);
	int lastStart = -1;
	ll res = 0;
	for (; start < pjg; start++) {
		if (end < start) end = start;
		for (; end < start + N && end < pjg && S[end] == '1'; end++);
		//printf("start %d, end %d\n", start, end);
		if (end - start == N) {
			res += (start - (lastStart + 1) + 1) * (pjg - end + 1);
			lastStart = start;
			//puts("hitung");
		}
	}
	printf("Case #%d: %lld\n", tc, res);
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
