#include <bits/stdc++.h>
using namespace std;

#define TRACE(x...)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define PRINT(x...) TRACE(printf(x))
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR((V).begin(), (V).end());})

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define FU(i, a, b) for(int i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define FD(i, a, b) for (int i = (b)-1; i >= a; --i)
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
	vvi V(2*N-1, vi(N));
	for (auto &x : V) for (auto &y : x) scanf("%d", &y);
	vector<vvi> round(N);
	fu(i, N) {
		int m = 10000;
		for (auto &x : V) m = min(m, x[i]);
		fu(j, V.size()) if (V[j][i] == m) {
			round[i].push_back(V[j]);
			swap(V[j], V.back());
			V.pop_back();
			j--;
		}
	}
	int missing;
	fu(i, N) if (round[i].size() == 1) missing = i;
	fu(i, N) printf(" %d", round[i][0][missing] + round[i][1 % round[i].size()][missing]
													- round[missing][0][i]);
	printf("\n");
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
