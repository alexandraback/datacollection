#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long UL;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define sz(x) ((int)(x.size()))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N = 3e3 + 7;
const int P = 1e7 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e7;
const double EPS = 1e-10;
int n, c[N];
set<int> s;
set<int>::iterator it;
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int _c = 1; _c <= T; ++_c) {
		scanf("%d", &n);
		s.clear();
		memset(c, 0, sizeof(c));
		for (int i = 1; i < (n << 1); ++i) {
			for (int j = 0; j < n; ++j) {
				int x;
				scanf("%d", &x);
				++c[x];
				s.insert(x);
			}
		}
		printf("Case #%d:", _c);
		for (it = s.begin(); it != s.end(); ++it)
			if ((c[*it] & 1) > 0) {
				printf(" %d", *it);
			}
		puts("");
	}
	return 0;
}
