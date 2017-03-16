#include <cstdio>
#include <vector>
#include <algorithm>
#define ALL(c) (c).begin(), (c).end()
#define VAR(v,n) __typeof(n) v=n
#define FOR(i,b,e) for(int i=(b); i<=(e); ++i)
#define PB push_back
#define TAB(x,f,t) __##x[t-f+1], *x=__##x-f
using namespace std;

const int MAX = 200;

struct attack
{
	int d, w, e, s;
	attack(int d, int w, int e, int s): d(d), w(w), e(e), s(s) {}
	bool operator<(attack x) const { return d<x.d; }
};

int TAB(h, -MAX, MAX), r;
vector<attack> al;

bool win(attack x)
{
	FOR(i, x.w, x.e) if (x.s > h[i]) return true;
	return false;
}

void set(attack x)
{
	FOR(i, x.w, x.e) h[i] = max(h[i], x.s);
}


int main()
{
	int Q; scanf("%d", &Q);
	FOR(q, 1, Q) {
		FOR(i, -MAX, MAX) h[i] = 0;
		al.clear();
		r = 0;
		
		int N; scanf("%d", &N);
		while (N--) {
			int d, n, w, e, s, D, P, S;
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &D, &P, &S);
			--e;
			while (n--) {
				al.PB(attack(d, w, e, s));
				d += D;
				w += P; e += P;
				s += S;
			}
		}
		
		sort(ALL(al));
		VAR(i, al.begin());
		VAR(j, al.begin());
		
		while (i < al.end()) {
			while (j<al.end() && i->d==j->d) ++j;
			for (VAR(k, i); k<j; ++k) if (win(*k)) ++r;
			for (VAR(k, i); k<j; ++k) set(*k);
			i = j;
		}
		
		printf("Case #%d: %d\n", q, r);
	}
	
	return 0;
}
