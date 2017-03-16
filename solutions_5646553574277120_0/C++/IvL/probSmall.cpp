#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define ull unsigned ll
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

int c, d, v;
int a[105];
bool has[105];
ull ALL;
bool rek(ull bit, int dep){
	if (dep == 0) return (bit & ALL) == ALL;
	FOR(1, v + 1, i)
		if (!has[i]){
			has[i] = true;
			ull b2 = (bit | ((bit << i) & ALL));
			if (rek(b2, dep - 1)) return true;
			has[i] = false;
		}
	return false;
}
int Solve(){
	memset(has, 0, sizeof has);
	scanf("%d%d%d", &c, &d, &v);
	FOR(0, d, i) scanf("%d", a + i), has[a[i]] = true;
	//if (c != 1) return -1;
	ull start = 1;
	ALL = (1LL << (v + 1)) - 1;
	FOR(0, d, i)
		start |= ((start << a[i]) & ALL);
	FOR(0, 7, dep) if (rek(start, dep)) return dep;
}

int main(){
	int t;
	scanf("%d", &t);
	FOR(1, t + 1, i) printf("Case #%d: %d\n", i, Solve());
	return 0;
}

