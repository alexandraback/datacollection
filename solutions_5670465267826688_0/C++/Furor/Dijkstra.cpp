#include <cstdio>
#include <cstring>
#include <iostream>
#define _1 0
#define _I 1
#define _J 2
#define _K 3
#define MAX 10005
#define INF 100000000000000LL

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;

int M[4][4] = {
	//       1   i    j   k
	/*1*/ { _1, _I,  _J, _K },
	/*i*/ { _I, _1,  _K, _J },
	/*j*/ { _J, _K,  _1, _I },
	/*k*/ { _K, _J,  _I, _1 }
};

int S[4][4] = {
	//       1   i    j   k
	/*1*/ {  1,  1,   1,  1 },
	/*i*/ {  1, -1,   1, -1 },
	/*j*/ {  1, -1,  -1,  1 },
	/*k*/ {  1,  1,  -1, -1 }
};

ii times(ii a, ii b) {
	return ii(a.first * b.first * S[a.second][b.second], M[a.second][b.second]);
}

ii P[4];

char L[4] = { '1', 'i', 'j', 'k' };
char str[MAX];
int C[MAX];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int c, cc, cv, i, n, p, v;
	LL x, cs;
	scanf("%d\n", &c);
	for (cc = 0; cc < c; cc++) {
		bool pos = true;
		scanf("%d %I64d\n%s\n", &n, &x, str);
		P[0] = ii(1, _1);
		P[1] = P[0];
		for (i = 0; i < n; i++) {
			C[i] = str[i] - 'i' + 1;
			P[1] = times(P[1], ii(1, C[i]));
		}
		P[2] = times(P[1], P[1]);
		P[3] = times(P[2], P[1]);
		cs = 0;
		cv = 0;
		pair<LL, int> m(INF, 0);
		ii V(1, _1);
		for (v = 0; v < n; v++) {
			V = times(V, ii(1, C[v]));
			for (p = 0; p < 4; p++)
				if (times(P[p], V) == ii(1, _I))
					m = min(m, make_pair((LL)p, v));
		}
		if (m >= make_pair(x - 1LL, n - 1))
			pos = false;
		else {
			cs = m.first;
			cv = m.second;
			V = ii(1, _1);
			for (v = cv + 1; v < n; v++) {
				V = times(V, ii(1, C[v]));
				if (V == ii(1, _J)) {
					m = make_pair(cs, v);
					break;
				}
			}
			if (v == n) {
				m = make_pair(INF, 0);
				cs++;
				ii O = V;
				V = ii(1, _1);
				for (v = 0; v < n; v++) {
					V = times(V, ii(1, C[v]));
					for (p = 0; p < 4; p++)
						if (times(O, times(P[p], V)) == ii(1, _J))
							m = min(m, make_pair((LL)p + cs, v));
				}
			}
			if (m >= make_pair(x - 1LL, n - 1))
				pos = false;
			else {
				cs = m.first;
				cv = m.second;
				V = ii(1, _1);
				for (v = cv + 1; v < n; v++)
					V = times(V, ii(1, C[v]));
				int r = (x - cs - 1) % 4LL;
				pos = times(V, P[r]) == ii(1, _K);
			}
		}
		printf("Case #%d: %s\n", cc + 1, pos ? "YES" : "NO");
	}
	return 0;
}
