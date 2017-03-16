
#include <cstdio>

#include <vector>

using namespace std;


typedef long long LL;

static constexpr LL M = 1000000007;

LL m(LL l) { return l % M; }

LL ff[120];


char bf[120][120];

struct CC {
	char b, e;
	CC(char b, char e): b(b), e(e) {}
};

vector<CC> cs;

LL p() {
	cs.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", bf[i]);

	int ss[26] = {};
	for (int i = 0; i < n; ++i) {
		char x = bf[i][0];
		char *s = bf[i];

		//printf("pr %s\n", s);
		while ( *s == x ) ++s;
		if ( *s == '\0' ) {
			++ss[x - 'a'];
			//printf("find %c\n", x);
			continue;
		}
		while ( true ) {
			char y = *s;
			while ( *s == y ) ++s;
			if ( *s == '\0' ) {
				//printf("find %c%c\n", x, y);
				cs.emplace_back(x, y);
				break;
			}
			for (int j = 0; j < n; ++j) {
				char *t = j == i ? s : bf[j];
				while ( *t ) if ( *t++ == y ) return 0LL;
			}
		}
	}
	
	for (size_t i = 0; i < cs.size(); ++i) {
		for (size_t j = 0; j < cs.size(); ++j) {
			if ( j == i ) continue;
			if ( cs[i].b == cs[j].b || cs[i].e == cs[j].e ) return 0LL;
		}
	}

	LL rr = 1LL;
	LL sc = 0;
	for (char x = 'a'; x <= 'z'; ++x) {
		int k = ss[x - 'a'];
		if ( k == 0 ) continue;
		rr = m(rr * ff[k]);
		bool f = false;
		for (CC &cr : cs) {
			if ( f ) break;
			if ( cr.b == x || cr.e == x ) {
				f = true;
				break;
			}
		}
		if ( !f ) {
			++sc;
		}
	}

	while ( !cs.empty() ) {
		++sc;
		CC cr = cs.back();
		cs.pop_back();
		char x = cr.e;
		int cq = 1;
		
		while ( true ) {
			bool f = false;
			for (size_t i = 0; i < cs.size(); ++i) {
				if ( cs[i].b == x ) {
					x = cs[i].e;
					cs[i] = cs.back();
					cs.pop_back();
					++cq;
					f = true;
					break;
				}
			}
			if ( !f ) break;
		}
		if ( x == cr.b ) {
			rr = m(rr * cq);
		}
		x = cr.b;
		while ( true ) {
			bool f = false;
			for (size_t i = 0; i < cs.size(); ++i) {
				if ( cs[i].e == x ) {
					x = cs[i].b;
					cs[i] = cs.back();
					cs.pop_back();
					f = true;
					break;
				}
			}
			if ( !f ) break;
		}
	}
	return m(rr * ff[sc]);
}

int main() {
	ff[0] = ff[1] = 1;
	for (int i = 2; i < 120; ++i)
		ff[i] = m(ff[i-1] * i);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		printf("Case #%d: %lld\n", i, p());
	return 0;
}

