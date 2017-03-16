
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef long double ld;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()
#define Max(a,b) (a)<(b)?(b):(a)
#define Min(a,b) (a)<(b)?(a):(b)

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

char buf[1024];

enum ans_t { NO=0, YES, UNKNOWN };

ans_t SolveMain(uint64_t L, uint64_t X, char *Ijk);

int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		uint64_t L, X;
		char Ijk[10010];
		scanf("%llu %llu", &L, &X);
		scanf("%s", Ijk);
//		printf("%llu %llu [%s]\n", L, X, Ijk);

		ans_t ans = SolveMain(L, X, Ijk);

		if (ans == NO)
			printf("Case #%d: NO", tcase);
		else if (ans == YES)
			printf("Case #%d: YES", tcase);
		else
			printf("Case #%d: *****UNKNOWN*****", tcase);
		printf("\n");
	}
}

enum state_t {
	RiLi=0, RiLj, RiLk, RiL_i, RiL_j, RiL_k, RiL_1,
	RjLi,   RjLj, RjLk, RjL_i, RjL_j, RjL_k, RjL_1,
	RkLi,   RkLj, RkLk, RkL_i, RkL_j, RkL_k, RkL_1,
	R1Li,   R1Lj, R1Lk, R1L_i, R1L_j, R1L_k, R1L_1,
	Lend,
	RiFin=RjLj, RjFin=RkLk, RkFin=Lend, R1Fin=Lend
};

int state_trans_tbl[29][3] = {
	{ RiFin, RiLk, RiL_j },		// RiLi; For reducing to i, looking i
	{ RiL_k, RiFin, RiLi },		// RiLj; For reducing to i, looking j
	{ RiLj, RiL_i, RiFin },		// RiLk; For reducing to i, looking k
	{ RiL_1, RiL_k, RiLj },		// RiL-i; For reducing to i, looking -i
	{ RiLk, RiL_1, RiL_i },		// RiL-j
	{ RiL_j, RiLi, RiL_1 },		// RiL-k
	{ RiLi, RiLj, RiLk },		// RiL-1; For reducing to i, looking -1

	{ RjFin, RjLk, RjL_j },		// RjLi
	{ RjL_k, RjFin, RjLi },		// RjLj
	{ RjLj, RjL_i, RjFin },		// RjLk
	{ RjL_1, RjL_k, RjLj },		// RjL-i
	{ RjLk, RjL_1, RjL_i },		// RjL-j
	{ RjL_j, RjLi, RjL_1 },		// RjL-k
	{ RjLi, RjLj, RjLk },		// RjL-1

	{ RkFin, RkLk, RkL_j },		// RkLi
	{ RkL_k, RkFin, RkLi },		// RkLj
	{ RkLj, RkL_i, RkFin },		// RkLk
	{ RkL_1, RkL_k, RkLj },		// RkL-i
	{ RkLk, RkL_1, RkL_i },		// RkL-j
	{ RkL_j, RkLi, RkL_1 },		// RkL-k
	{ RkLi, RkLj, RkLk },		// RkL-1

	{ R1Fin, R1Lk, R1L_j },		// R1Li; For reducing to 1, looking i
	{ R1L_k, R1Fin, R1Li },		// R1Lj
	{ R1Lj, R1L_i, R1Fin },		// R1Lk
	{ R1L_1, R1L_k, R1Lj },		// R1L-i
	{ R1Lk, R1L_1, R1L_i },		// R1L-j
	{ R1L_j, R1Li, R1L_1 },		// R1L-k
	{ R1Li, R1Lj, R1Lk },		// R1L-1

	{ R1L_i, R1L_j, R1L_k },	// Lend; To finish, looking 1
};

int ApplyStateMachine(int start_state, char *Ijk, uint64_t L, int *end_state)
{
	int state = start_state;
	for (int i = 0; i < L; i++)
	{
		int idx = Ijk[i] - 'i';
		state = state_trans_tbl[state][idx];
	}
	
	*end_state = state;
	return 0;
}

ans_t SolveMain(uint64_t L, uint64_t X, char *Ijk)
{
	int state_trans_map[29];
	for (int i = 0; i < 29; i++)
	{
		int new_state;
		ApplyStateMachine(i, Ijk, L, &new_state);
		state_trans_map[i] = new_state;
	}

	int state = 0;
	int apply_n = 1;
	for (; apply_n <= 29; apply_n++)
	{
		state = state_trans_map[state];
		if (state == Lend)
			break;
	}

	if (state != Lend)
		return NO;

	int first_equiv = apply_n;

	apply_n = 1;
	for (; apply_n <= 29; apply_n++)
	{
		state = state_trans_map[state];
		if (state == Lend)
			break;
	}

	int period = 0;
	if (state == Lend)
		period = apply_n;

	if (X < first_equiv)
		return NO;

	uint64_t X1 = X - first_equiv;
	if (period == 0)
	{
		if (X1 == 0)
			return YES;
		else
			return NO;
	}

	if (X1 % period == 0)
		return YES;

	return  NO;
}

