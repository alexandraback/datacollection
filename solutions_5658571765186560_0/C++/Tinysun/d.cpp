
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

enum ans_t { RICHARD=0, GABRIEL, UNKNOWN };

ans_t SolveMain(uint64_t X, uint64_t R, uint64_t C);

int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		uint64_t X, R, C;
		scanf("%llu %llu %llu", &X, &R, &C);
//		printf("%llu %llu %llu\n", X, R, C);

		ans_t ans = SolveMain(X, R, C);

		if (ans == RICHARD)
			printf("Case #%d: RICHARD", tcase);
		else if (ans == GABRIEL)
			printf("Case #%d: GABRIEL", tcase);
		else
			printf("Case #%d: *****UNKNOWN*****", tcase);
		printf("\n");
	}
}

ans_t SolveMain(uint64_t X, uint64_t R, uint64_t C)
{
	if (X > 4 || R > 4 || C > 4)
	{
		return UNKNOWN;
	}

	if (R*C % X != 0)
		return RICHARD;

	uint64_t R1 = Min(R, C);
	uint64_t C1 = Max(R, C);

	if (X == 1)
		return GABRIEL;

	if (X == 2)
		return GABRIEL;

	if (X == 3)
	{
		if (R1 == 1 && C1 == 3)
			return RICHARD;
		if (R1 == 2 && C1 == 3)
			return GABRIEL;
		if (R1 == 3 && C1 == 3)
			return GABRIEL;
		if (R1 == 3 && C1 == 4)
			return GABRIEL;
	}

	if (X == 4)
	{
		if (R1 == 1 && C1 == 4)
			return RICHARD;
		if (R1 == 2 && C1 == 2)
			return RICHARD;
		if (R1 == 2 && C1 == 4)
			return RICHARD;
		if (R1 == 3 && C1 == 4)
			return GABRIEL;
		if (R1 == 4 && C1 == 4)
			return GABRIEL;
	}

	return  UNKNOWN;
}