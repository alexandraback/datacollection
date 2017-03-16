
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

char S[1024];
char ans_str[2048];

typedef int ans_t;

ans_t SolveMain(uint64_t N, uint64_t *m);

int main() {
	char buf[1024];
	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		scanf("%s", S);
//		printf("%s\n", S);
		int len = strlen(S);
		ans_str[1024] = S[0];
		int start = 1024;
		int end = 1024;
		For(i, 1, len-1) {
			if (S[i] >= ans_str[start]) {
				ans_str[start - 1] = S[i];
				start--;
			}
			else {
				ans_str[end + 1] = S[i];
				end++;
			}
		}
		ans_str[end + 1] = '\0';

		printf("Case #%d: %s", tcase, ans_str+start);
		printf("\n");
	}
}


ans_t SolveMain(uint64_t N, uint64_t *m)
{

	return 0;
}

