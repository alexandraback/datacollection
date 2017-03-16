#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}


void docase() {
	int K, C, S;
	scanf("%d%d%d", &K, &C, &S);
	if (S*C < K) {
		printf(" IMPOSSIBLE\n");
		return;
	}
	REP(s,0,(K+C-1)/C) {
		ll nr = 0;
		REP(i,0,min(C,K-s*C))
			nr = K*nr + s*C+i;
		printf(" %lld", nr+1);
	}
	printf("\n");
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d:", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
