
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

uint64_t N;
uint64_t Height[100][50];
int height_freq[2501];

int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		scanf("%llu", &N);
		for (int i = 0; i < 2*N-1; i++)
			for(int j=0; j<N; j++)
				scanf("%llu", &Height[i][j]);

// 		printf("%llu\n", N);
// 		for (int i = 0; i < 2 * N - 1; i++) {
// 			for (int j = 0; j < N; j++)
// 				printf("%llu", Height[i][j]);
// 			printf("\n");
// 		}

		For(h, 1, 2500)
			height_freq[h] = 0;
		for (int i = 0; i < 2 * N - 1; i++) {
			for (int j = 0; j < N; j++)
				height_freq[Height[i][j]]++;
		}

		int ans[51];
		int i = 1;
		For(h, 1, 2500) {
			if (height_freq[h] % 2 == 1)
				ans[i++] = h;
		}

// 		uint64_t ans = Solve();
// 
		printf("Case #%d: ", tcase);
		For(i, 1, N) {
			if (i > 1)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
}

