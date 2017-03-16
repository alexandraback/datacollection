
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

typedef int ans_t;

ans_t SolveMain(int64_t K, int64_t C, int64_t S);

int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		int64_t K, C, S;
		scanf("%lld %lld %lld", &K, &C, &S);
//		printf("%llu %llu %llu\n", K, C, S);

		printf("Case #%d: ", tcase);
		ans_t ans = SolveMain(K, C, S);
		printf("\n");
	}
}

uint64_t Position(int64_t K, int64_t C, int64_t from, int64_t to)
{
	int64_t pos = from;
	for (int64_t i = 0; i < C - 1; i++)
	{
		//if (from < to)
		if (i >= C - K)
			from = from + 1;
		pos = pos * K + from;
	}

	return pos + 1;
}

ans_t SolveMain(int64_t K, int64_t C, int64_t S)
{
	int64_t least_num = (K - 1) / C + 1;
	if (S < least_num)
	{
		printf("IMPOSSIBLE");
		return 0;
	}

	if (K < C)
	{
		printf("%lld", Position(K, C, 0, K - 1));
		return 0;
	}

	for (int64_t i = 0; i < K; i += C)
	{
		if (i > 0)
			printf(" ");
		if (i + C < K)
			printf("%lld", Position(K, C, i, i + C - 1));
		else
			printf("%lld", Position(K, C, K - C, K - 1));
	}
	
	return 0;
}