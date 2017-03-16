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

ll comp(ll n) {
	vector<bool> seen(10,false);
	int nrseen = 0;
	ll a;
	for (a = n; nrseen < 10; a += n) {
		ll r = a;
		while(r) {
			nrseen += !seen[r%10];
			seen[r%10] = true;
			r /= 10;
		}
	}
	return a-n;
}

void docase() {
	int N;
	scanf("%d", &N);
	if (N == 0)
		printf("INSOMNIA\n");
	else
		printf("%lld\n", comp(N));
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
