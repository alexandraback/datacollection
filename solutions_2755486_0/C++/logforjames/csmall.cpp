#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long int tint;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define TOP 1024
#define get(x,c) c[x + 512]
#define in(x,c) (c.find(x) != c.end())

struct attack {
	int w, e, s;
};

inline bool operator<(const attack& a, const attack& b) {
	if (a.w < b.w) return true;
	if (a.w > b.w) return false;
	if (a.e < b.e) return true;
	if (a.e > b.e) return false;
	if (a.s < b.s) return true;
	if (a.s > b.s) return false;
	return false;
}

int alturas[1024];
map<int, set<attack> > attacks;
set<int> daysThatHaveAttacks;

int main() {
	freopen("csmall.in","r",stdin);
	freopen("csmall.out","w",stdout);
	int T;
	scanf("%d\n",&T);
	forn(caso, T) {
		forn(i,1024) alturas[i] = 0;
		int N;
		scanf("%d\n",&N);
		daysThatHaveAttacks.clear();
		attacks.clear();
		forn(i, N) {
			int d, n, w, e, s, deltad, deltap, deltas;
			scanf("%d %d %d %d %d %d %d %d\n", &d, &n, &w, &e, &s, &deltad, &deltap, &deltas);
			w *= 2;
			e *= 2;
			deltap *= 2;
			forn(i, n) {
				daysThatHaveAttacks.insert(d);
				if (!in(d, attacks)) attacks[d] = set<attack>();
				attack t; t.w = w; t.e = e; t.s = s;
				attacks[d].insert(t);
				d += deltad;
				w += deltap;
				e += deltap;
				s += deltas;
			}
		}
		int piola = 0;
		for(typeof(daysThatHaveAttacks.begin()) it = daysThatHaveAttacks.begin();it != daysThatHaveAttacks.end();it++) {
			int day = *it;
			set<attack> attacksForToday = attacks[day];
			for(typeof(attacksForToday.begin()) it2 = attacksForToday.begin();it2 != attacksForToday.end();it2++) {
				attack cur = (*(it2));
				bool gane = false; //Que feo todo esto!!! Perdon si alguien lee :(
				for (int i = cur.w;i <= cur.e;i++) {
					if (get(i,alturas) < cur.s) {
						gane = true;
					}
				}
				if (gane) piola++;
			}
			for(typeof(attacksForToday.begin()) it2 = attacksForToday.begin();it2 != attacksForToday.end();it2++) {
				attack cur = (*(it2));
				for (int i = cur.w;i <= cur.e;i++) {
					get(i,alturas) = max(get(i,alturas), cur.s);
				}
			}
		}
		cout << "Case #" << caso + 1 << ": " << piola << endl;
	}

}
