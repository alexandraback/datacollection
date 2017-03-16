
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

ans_t SolveMain(uint64_t D, uint64_t *Pi);

int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		uint64_t D;
		uint64_t Pi[1010];
		scanf("%llu", &D);
		for (int i = 0; i < D; i++)
			scanf("%llu", &Pi[i]);

// 		printf("%llu\n", D);
// 		for (int i = 0; i < D; i++)
// 			printf("%llu ", Pi[i]);
// 		printf("\n");

		ans_t ans = SolveMain(D, Pi);

		printf("Case #%d: %d", tcase, ans);
		printf("\n");
	}
}

int cut_sum_memo[1010];

int ClearCutSum()
{
	for (int i = 0; i < 1010; i++)
		cut_sum_memo[i] = -1;
	return 0;
}

int CountCutSum(uint64_t D, uint64_t *Pi, int big_part)
{
	if (cut_sum_memo[big_part] != -1)
		return cut_sum_memo[big_part];

	int cut_sum = 0;
	for (int i = 0; i < D; i++)
	{
		int cut = (Pi[i] - 1) / big_part;
		cut_sum += cut;
	}

	cut_sum_memo[big_part] = cut_sum;
	return cut_sum;
}

int checkMin(int candi, uint64_t D, uint64_t *Pi)
{
	int big_part = candi;
	
	while (true)
	{
		int cut_sum = CountCutSum(D, Pi, big_part);

		if (candi <= cut_sum)
			return -1;

		int new_big_part = candi - cut_sum;
		if (new_big_part == big_part)
			break;

		big_part = new_big_part;
	}

	return 0;
}

ans_t SolveMain(uint64_t D, uint64_t *Pi)
{
	ClearCutSum();

	int max_Pi = 0;
	for (int i = 0; i < D; i++)
	{
		max_Pi = Max(max_Pi, Pi[i]);
	}

	int max_candi = max_Pi;
	int min_candi = 0;

	while (min_candi + 1 < max_candi)
	{
		int candi = (min_candi + max_candi) / 2;
		int ret = checkMin(candi, D, Pi);
		if (ret == 0)  // OK
			max_candi = candi;
		else  // Faied
			min_candi = candi;
	}

	return  max_candi;
}

