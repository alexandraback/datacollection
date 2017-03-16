/*	Arkadiusz Wróbel - metsuryuu
 *
 *	Konkurs: Google Code Jam 2015
 *	Zadanie: Dijkstra
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <cmath>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

#define REP(I, N) for(int I = 0; I < (N); ++I)
#define FOR(I, M, N) for(int I = (M); I <= (N); ++I)
#define FORD(I, M, N) for(int I = (M); I >= (N); --I)
//#define FOREACH(IT, CON) for(__typeof((CON).begin()) IT = (CON).begin(); IT != (CON).end(); ++IT)

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define SIZE(CON) ((int)(CON).size())
#define ALL(CON) (CON).begin(), (CON).end()

const int INF = 1000000000;
const LL INFLL = 1000000000000000000LL;

template<typename T>
T fastExponentiation(T a, LL b) {
	T wyn(1);
	while (true) {
		if (b % 2) {
			wyn = wyn * a;
		}
		b /= 2;
		if (b == 0) {
			return wyn;
		}
		a = a * a;
	}
}

//######################################################################

#include <cassert>

struct Quater{
	int x;
	Quater(const int a) : x(a) {
		if (a < -4 || a == 0 || a > 4) {
			fprintf(stderr, "FAIL! Quater(%d)\n", a);
			exit(1);
		}
	}
};

inline int signum(const Quater x) {  // without zero
	return x.x < 0 ? -1 : 1;
}

Quater operator*(const Quater aa, const Quater bb) {
	int a = aa.x, b = bb.x;
	
	int sig = signum(a) * signum(b);
	a = abs(a);
	b = abs(b);
	
	if (a == 1)
		return Quater(sig * b);
	if (b == 1)
		return Quater(sig * a);
	if (a == b)
		return Quater(sig * -1);
	
	if (a == 2 && b == 3)
		return Quater(sig * 4);
	if (a == 3 && b == 2)
		return Quater(sig * -4);
	if (a == 2 && b == 4)
		return Quater(sig * -3);
	if (a == 4 && b == 2)
		return Quater(sig * 3);
	if (a == 3 && b == 4)
		return Quater(sig * 2);
	if (a == 4 && b == 3)
		return Quater(sig * -2);
	
	return Quater(0);
}

bool operator==(const Quater a, const Quater b) {
	return a.x == b.x;
}

//----------------------------------------------------------------------

LL L, X;
vector<Quater> t;

Quater iloczynL(1);

LL howManyLetters1() {
	Quater x(1);
	LL v = 0;
	LL result = 0;
	
	REP(i, 10) {  // 8 should be enough
		REP(j, L) {
			x = x * t[v];
			++result;
			
			if (x == Quater(2)) {
				return result;
			}
			
			++v;
			v %= L;
		}
	}
	
	return -1;
}

LL howManyLetters2() {
	Quater x(1);
	LL v = L-1;
	LL result = 0;
	
	REP(i, 10) {  // 8 should be enough
		REP(j, L) {
			x = t[v] * x;
			++result;
			
			if (x == Quater(4)) {
				return result;
			}
			
			--v;
			if (v < 0) {
				v += L;
			}
		}
	}
	
	return -1;
}

bool make() {
	LL wyn1 = howManyLetters1();
//	printf("wyn1: %lld\n", wyn1);
	if (wyn1 == -1)
		return false;
	LL wyn2 = howManyLetters2();
//	printf("wyn2: %lld\n", wyn2);
	if (wyn2 == -1)
		return false;
	
	if (wyn1 + wyn2 >= L*X)
		return false;
	
	// Teraz sprawdzamy, czy reszta wymnaża się do j, czyli Quater(3)
	Quater iloczyn1(1);
	
	while (wyn1 % L != 0) {
		iloczyn1 = iloczyn1 * t[wyn1 % L];
		++wyn1;
	}
//	printf("--- %d\n", iloczyn1.x);
	
	Quater iloczyn2(1);
	LL v = wyn2 % L;
	v = (L - 1 - v);
	while (wyn2 % L != 0) {
		iloczyn2 = t[v] * iloczyn2;
		--v;
		if (v < 0) {
			v += L;
		}
		++wyn2;
	}
//	printf("--- %d\n", iloczyn2.x);
//	printf("wyn1: %lld, wyn2: %lld\n", wyn1, wyn2);
	
	Quater iloczyn = iloczyn1 * fastExponentiation(iloczynL, X - (wyn1 + wyn2)/L) * iloczyn2;
	
	return iloczyn.x == 3;
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		//wej
		scanf("%lld%lld", &L, &X);
		t.clear();
		REP(i, L) {
			char c;
			scanf(" %c", &c);
			if (c == '1')
				t.PB(Quater(1));
			else if (c == 'i')
				t.PB(Quater(2));
			else if (c == 'j')
				t.PB(Quater(3));
			else if (c == 'k')
				t.PB(Quater(4));
			else
				t.PB(Quater(999));
		}
		iloczynL = Quater(1);
		REP(i, L)
			iloczynL = iloczynL * t[i];
		
		//wyj
		printf("Case #%d: %s\n", testCounter, make() ? "YES" : "NO");
	}
	
//	vector<Quater> vect = {1, 2, 3, 4, -1, -2, -3, -4};
//	for (Quater a : vect) {for (Quater b : vect) {printf(" %2d", (a*b).x);}printf("\n");}
	return 0;
}
