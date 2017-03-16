#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

long long go(long long v)
{
	if ((v % 2LL) == 0LL) { return 2LL; }
	for (long long x = 3LL; v / x >= x; x += 2LL) {
		if ((v % x) == 0LL) { return x; }
	}
	return -1LL;
}

bool attempt(int x)
{
	vector<long long> ps;
	long long last = 0LL;
	for (int b = 2; b <= 10; ++b) {
		long long t = 1LL;
		long long v = 0LL;
		int i = x;
		while (i > 0) {
			v += (i&1) * t;
			t *= (long long) b;
			i /= 2;
		}
		long long p = go(v);
		if (p < 0LL) {
			return false;
		}
		ps.push_back(p);
		last = v;
	}
	printf("%lld", last);
	for (int i = 0; i < ps.size(); ++i) {
		printf(" %lld", ps[i]);
	}
	puts("");
	return true;
}

void solve()
{
	static int casenr = 1;
	printf("Case #%d:\n", casenr++);
	
	int N, J; scanf("%d%d", &N, &J);
	
	for (int i = (1<<(N-1))+1; i < (1<<N); i += 2) {
		//printf("%d\n", i);
		if (attempt(i)) {
			if (--J == 0) {
				break;
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
