#include <bits/stdc++.h>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define PRINT(x...) TRACE(printf(x))
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define FU(i, a, b) for(decltype(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define FD(i, a, b) for (decltype(a) i = (b)-1; i >= a; --i)
#define fd(i, n) FD(i, 0, n)

#define mod(a, b) ((((a)%(b))+(b))%(b))
#define pb push_back
#define sz(c) int((c).size())

const double EPS = 1e-8;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void doit() {
	int N;
	scanf("%d", &N);
	vi BFF(N);
	for (int &x : BFF) {
		scanf("%d", &x);
		x--;
	}
	vi best(N, 0);
	int ans = 0;
	fu(i, N) { // start at i
		if (BFF[BFF[i]] == i)
			continue;
		vi depth(N, -1);
		depth[i] = 0;
		int cur = i;
		while (true) {
			int next = BFF[cur];
			if (depth[next] != -1) {
				int cycle = depth[cur] + 1 - depth[next];
				ans = max(ans, cycle);
				if (cycle == 2)
					best[next] = max(best[next], depth[next]);
				break;
			}
			depth[next] = depth[cur] + 1;
			cur = next;
		}
	}
	int ans2 = 0;
	fu(i, N) if (BFF[BFF[i]] == i)
		ans2 += 1 + best[i];
	printf(" %d\n", max(ans, ans2));
}

int main() {
	int _42;
	scanf("%d", &_42);
	fu(_41, _42) {
		printf("Case #%d:", _41+1);
		doit();
	}
	return 0;
}
