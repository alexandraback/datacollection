
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

typedef double ans_t;

char combi[1000000][7];
int  inst[1000000];
int  maxinst;
int  totinst;
int  idx[7];

int CountTarget(char *MonkStr, uint64_t S, char *Target, uint64_t L)
{
	if (S >= L && strncmp(MonkStr, Target, L) == 0)
		return 1;
	return 0;
}

ans_t SolveMain(uint64_t K, uint64_t L, uint64_t S, char *Keys, char *Target)
{
	if (K > 7 || S > 7)
		return 0.0;

	// clear index
	for (int i = 0; i < 7; i++)
		idx[i] = 0;
	int entry = 0;

	ans_t ans = 0.0;
	
	maxinst = 0;
	totinst = 0;

	// build combi[]
	while (true)
	{
		for (int i = 0; i < S; i++)
			combi[entry][i] = Keys[idx[i]];

		int thisentry = 0;
		for (int k = 0; k < S; k++)
			thisentry += CountTarget(&combi[entry][k], S-k, Target, L);

// 		if (thisentry == 4)
// 		{
// 			for (int m = 0; m < S; m++)
// 				printf("%c", combi[entry][m]);
// 			printf("\n");
// 		}
		maxinst = Max(maxinst, thisentry);
		totinst += thisentry;

		entry++;

		// next entry
		uint64_t carrypos = S - 1;
		while (true)
		{
			idx[carrypos]++;

			if (idx[carrypos] < K)
				break;

			if (carrypos == 0)
				break;

			idx[carrypos] = 0;
			carrypos--;
		}

		// must check index[0] == K
		if (idx[0] == K)
			break;
	}
//	printf("maxinst=%d totinst=%d\n", maxinst, totinst);
	// assert entry == K**S
	ans = maxinst - totinst*1.0/entry;

	return ans;
}


int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		uint64_t K, L, S;
		char Keys[100];
		char Target[100];
		scanf("%llu %llu %llu", &K, &L, &S);
		scanf("%s", Keys);
		scanf("%s", Target);

// 		printf("%llu %llu %llu\n%s\n%s\n", K, L, S, Keys, Target);

		ans_t ans = SolveMain(K, L, S, Keys, Target);

		printf("Case #%d: %.7lf", tcase, ans);
		printf("\n");
	}
}

