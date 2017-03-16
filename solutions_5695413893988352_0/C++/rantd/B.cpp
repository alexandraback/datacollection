#include <bits/stdc++.h>
using namespace std;

#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define FOREACH(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> inline T tabs(T a) { return (a > 0) ? a : -a; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

string a, b;
ll diff, ans_a, ans_b;

void solve(string ta, string tb, int ind, int n) {
	if (ind == n) {
		ll sa = atol(ta.c_str()), sb = atol(tb.c_str());
		ll d = tabs(sa - sb);
		if (d < diff) diff = d, ans_a = sa, ans_b = sb;
		else if (d == diff && sa < ans_a) {
			ans_a = sa, ans_b = sb;
		}
		else if (d == diff && sa == ans_a && sb < ans_b) {
			ans_a = sa, ans_b = sb;
		}
		return;
	}
	if (a[ind] == b[ind] && a[ind] == '?') {
		for (char i = '0'; i <= '9'; ++i) for (char j = '0'; j <= '9'; ++j) {
			solve(ta + i, tb + j, ind + 1, n);
		}
	}
	else if (a[ind] == '?' && b[ind] != '?') {
		for (char i = '0'; i <= '9'; ++i) {
			solve(ta + i, tb + b[ind], ind + 1, n);
		}
	}
	else if (a[ind] != '?' && b[ind] == '?') {
		for (char j = '0'; j <= '9'; ++j) {
			solve(ta + a[ind], tb + j, ind + 1, n);
		}
	}
	else if (a[ind] != '?' && b[ind] != '?') {
		solve(ta + a[ind], tb + b[ind], ind + 1, n);
	}
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
	int nTest; string ra, rb, na, nb;

	cin >> nTest;
	REPU(it, 1, nTest + 1) {
		cin >> a >> b;
		int n = a.size();
		diff = LLONG_MAX;
		solve("", "", 0, n);
		{
			ra = to_string(ans_a), rb = to_string(ans_b);
			while (ra.size() < n) ra = '0' + ra;
			while (rb.size() < n) rb = '0' + rb;
		}
		printf("Case #%d: %s %s\n", it, ra.c_str(), rb.c_str());
	}
	
	return 0;
}
