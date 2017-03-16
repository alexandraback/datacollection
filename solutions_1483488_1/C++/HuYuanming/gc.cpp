/*2012.4.13*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
//#include <cmath>
using namespace std;
#define PL printf("%d\n", __LINE__);
#define MM(a, b) memset(a, b, sizeof(a));
#define For(i, a) for (register int i = 0; i < (a); i++)
#define Foru(i, a, b) for (register int i = (a); i < (b); i++)
#define foru(i, a, b) for (register int i = (a); i <= (b); i++)
#define ford(i, a, b) for (register int i = (a); i >= (b); i--)
#define fore(i, a, b) for (register __typeof(a) i = (a); (i) != (b); (i)++)
#define inf 1000000000
#define linf 10000000000000000LL
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define Walk(u) for (elist l = de[u]; l; l = l->next)
#define bgn begin
#define fi first
#define se second
#define ite iterator
#define All(x) (x).bgn(), (x).end()
#define sz(x) ((int)x.size())
#define pq priority_queue
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int pow[10];
int lll, rrr;
LL cnt;
int num[111];

int dig;

/*
int GetNum(int dig, int delta) {
	int res = 0;
	For (i, dig) res = res * 10 + num[(i + delta) % dig];
	return res;
}

void DFS(int dep) {
	if (dep == dig) {
		set<int> S;
		For (i, dig) {
			int a = GetNum(dig, i); 
	//		printf("%d\n", a);
			if(a / pow[dig - 1] && lll <= a && a <= rrr && S.find(a) == S.end()) S.insert(a);
		}
		printf("%d %d\n", GetNum(dig, 0), sz(S));
		cnt += (sz(S) - 1) * (LL)sz(S) / 2;
		return;
	}
	Foru (i, dep ? num[dep - 1] : 0, 10) num[dep] = i, DFS(dep + 1);
}
*/

map<pii, int> M;

LL Count(int ll, int rr) {
	M.clear();
	cnt = 0;
	lll = ll; rrr = rr;
	foru (a, ll, rr) {
		int dig = 0;
		while (a / pow[dig]) dig++;
		int minp = inf;
		For (i, dig) minp = min(minp, a), a = a / pow[dig - 1] + a % pow[dig - 1] * 10;
		M[mp(minp, dig)]++;
	}
	fore (i, M.bgn(), M.end()) cnt += LL(i->second - 1) * (i->second) / 2;
	return cnt;
}

int main() {
	pow[0] = 1;
	Foru (i, 1, 10) pow[i] = pow[i - 1] * 10;
	int T; scanf("%d", &T);
	For (t, T) {
		int ll, rr; scanf("%d%d", &ll, &rr);
		printf("Case #%d: %lld\n", t + 1, Count(ll, rr));
	}
	return 0;
}
