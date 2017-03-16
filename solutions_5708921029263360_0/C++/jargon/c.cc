#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, pair<int, int> > outfit;

#define mo(a,b,c) mp(a,mp(b,c))
#define Z -1

#define ok (m[mo(j,p,Z)] < K && m[mo(j,Z,s)] < K && m[mo(Z,p,s)] < K)

map<outfit, int> m;
vector<outfit> O;
int J, P, S, K;
int f(int j, int p, int s) {
	if (j >= J || p >= P || s >= S) return 0;
	if (!ok) return 0;
	// try not:
	int nj = j, np = p, ns = s + 1;
	if (ns >= S) { ns %= S; ++np; }
	if (np >= P) { np %= P; ++nj; }

	// With
	++m[mo(j,p,Z)],++m[mo(j,Z,s)],++m[mo(Z,p,s)];
	int x = 1+f(nj, np, ns);
	--m[mo(j,p,Z)],--m[mo(j,Z,s)],--m[mo(Z,p,s)];
	// Without
	int y = f(nj, np, ns);
//		printf("-- %d.%d [%d %d %d] [%d %d %d] %d\n", x, y, j, p, s, m[mo(j,p,Z)],m[mo(j,Z,s)],m[mo(Z,p,s)], ok);

	if (x > y && ok) {
		++m[mo(j,p,Z)],++m[mo(j,Z,s)],++m[mo(Z,p,s)];	
		O.pb(mo(j,p,s));
		return y + 1;
	}
	return y;
}

int main() {
	int T, t = 0;
	for (scanf("%d", &T); t++ < T;) {
		m.clear();
		O.clear();
		scanf("%d%d%d%d", &J, &P, &S, &K);
		f(0, 0, 0);
		printf("Case #%d: %d\n", t, (int)O.size());
		for (auto o : O)  printf("%d %d %d\n", o.first + 1, o.second.first + 1, o.second.second + 1);
	}
}
