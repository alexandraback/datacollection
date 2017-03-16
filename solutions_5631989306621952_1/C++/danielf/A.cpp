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

char buf[1010];
int main() {
	int _42;
	scanf("%d", &_42);
	fu(_41, _42) {
		printf("Case #%d: ", _41+1);
		scanf(" %s", buf);
		string s = buf;
		string ans = "";
		for (char c : s) {
			ans = max(ans + c, c + ans);
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}

