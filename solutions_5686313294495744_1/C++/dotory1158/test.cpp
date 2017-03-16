#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 534567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

map <string, int> Mx;
map <string, int> My;
int chx(string u) {
	if (Mx.count(u)) return Mx[u];
	int t = Mx.size() + 1;
	Mx[u] = t;
	return t;
}
int chy(string u) {
	if (My.count(u)) return My[u];
	int t = My.size() + 1;
	My[u] = t;
	return t;
}

class edge {
public:
	int s, e, f;
	edge() {
		*this = edge(0, 0, 0);
	}
	edge(int s, int e, int f) : s(s), e(e), f(f) {}
};

vector <edge> E;
vector <int> conn[100050];
void epush(int s, int e, int f) {
	edge e1 = edge(s, e, f);
	edge e2 = edge(e, s, 0);
	conn[s].push_back(E.size());
	conn[e].push_back(E.size() + 1);
	E.push_back(e1);
	E.push_back(e2);
}
int dchk[100050];
bool DFS(int n, int snk, int C) {
	if (n == snk) return true;
	dchk[n] = C;
	for (auto it : conn[n]) {
		edge& ed = E[it];
		if (ed.f == 0 || dchk[ed.e] == C) continue;
		if (DFS(ed.e, snk, C)) {
			ed.f--;
			E[it ^ 1].f++;
			return true;
		}
	}
	return false;
}
void init(int snk) {
	E.clear();
	for (int i = 0; i <= snk; i++) conn[i].clear();
	fill(dchk, dchk + snk + 1, 0);
}

char in1[25];
char in2[25];

int in[1050][2];
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int N, i, j, t1, t2;
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			scanf("%s %s", in1, in2);
			t1 = chx(string(in1));
			t2 = chy(string(in2));
			in[i][0] = t1, in[i][1] = t2;
		}

		int snk = Mx.size() + My.size() + 1;
		for (i = 1; i <= N; i++) epush(in[i][0], Mx.size() + in[i][1], 1);
		for (i = 1; i <= Mx.size(); i++) epush(0, i, 1);
		for (i = 1; i <= My.size(); i++) epush(Mx.size() + i, snk, 1);

		int f = 0;
		while (DFS(0, snk, f + 1)) f++;
		f = Mx.size() + My.size() - f;

		printf("Case #%d: %d\n", tc, N - f);

		init(snk);
		Mx.clear();
		My.clear();
	}
	return 0;
}