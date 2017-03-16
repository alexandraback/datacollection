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

int N;
int cnt[3000];

void docase() {
	scanf("%d", &N);
	REP(k,0,3000)
		cnt[k] = 0;
	REP(i1,0,2*N-1) REP(i2,0,N) {
		int k;
		scanf("%d", &k);
		cnt[k]++;
	}
	int len = 0;
	REP(k,0,3000)
		if (cnt[k]%2) {
			printf(" %d", k);
			len++;
		}
	assert(len == N);
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
