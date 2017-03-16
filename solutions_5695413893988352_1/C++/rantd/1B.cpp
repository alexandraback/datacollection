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

enum {
	LESS,
	GREAT
};

string a, b;
ll diff, ans_a, ans_b;

void solve(string ta, string tb, int ind, int n, int flag) {
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
		if (flag == LESS) {
			solve(ta + '9', tb + '0', ind + 1, n, LESS);
		}
		else {
			solve(ta + '0', tb + '9', ind + 1, n, GREAT);
		}
	}
	else if (a[ind] == '?' && b[ind] != '?') {
		if (flag == LESS) {
			solve(ta + '9', tb + b[ind], ind + 1, n, LESS);
		}
		else {
			solve(ta + '0', tb + b[ind], ind + 1, n, GREAT);
		}
	}
	else if (a[ind] != '?' && b[ind] == '?') {
		if (flag == LESS) {
			solve(ta + a[ind], tb + '0', ind + 1, n, LESS);
		}
		else {
			solve(ta + a[ind], tb + '9', ind + 1, n, GREAT);
		}
	}
	else if (a[ind] != '?' && b[ind] != '?') {
		solve(ta + a[ind], tb + b[ind], ind + 1, n, flag);
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
		int pos = -1;
		REPU(i, 0, n) {
			if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
				pos = i; break;
			}
		}
		if (pos == -1) {
			ra = a, rb = b;
			REPU(i, 0, n) {
				if (a[i] != '?') ra[i] = rb[i] = a[i];
				if (b[i] != '?') ra[i] = rb[i] = b[i];
				if (a[i] == b[i] && a[i] == '?') ra[i] = rb[i] = '0';
			}
		}
		else {
			REPU(i, 0, n) {
				na.assign(i + 1, '0');
				nb.assign(i + 1, '0');
				int flag = -1;
				REPU(j, 0, i) {
					if (a[j] != '?' && b[j] == '?') na[j] = nb[j] = a[j];
					else if (a[j] == '?' && b[j] != '?') na[j] = nb[j] = b[j];
					else if (a[j] != '?' && b[j] != '?') {
						na[j] = a[j], nb[j] = b[j];
						if (flag == -1) flag = (a[j] < b[j]) ? LESS : GREAT;
					}
					else na[j] = nb[j] = '0';
				}
				if (flag == -1) {
					if (a[i] == '?' && b[i] == '?') {
						na[i] = '1', nb[i] = '0';
						solve(na, nb, i + 1, n, GREAT);
						na[i] = '0', nb[i] = '1';
						solve(na, nb, i + 1, n, LESS);
					}
					else if (a[i] != '?' && b[i] == '?') {
						na[i] = a[i];
						if (a[i] < '9') {
							nb[i] = a[i] + 1;
							solve(na, nb, i + 1, n, LESS);
						}
						else {
							nb[i] = '0';
							solve(na, nb, i + 1, n, GREAT);
						}
						if (a[i] > '0') {
							nb[i] = a[i] - 1;
							solve(na, nb, i + 1, n, GREAT);
						}
						else {
							nb[i] = '9';
							solve(na, nb, i + 1, n, LESS);
						}
					}
					else if (a[i] == '?' && b[i] != '?') {
						nb[i] = b[i];
						if (b[i] < '9') {
							na[i] = b[i] + 1;
							solve(na, nb, i + 1, n, GREAT);
						}
						else {
							na[i] = '0';
							solve(na, nb, i + 1, n, LESS);
						}
						if (b[i] > '0') {
							na[i] = b[i] - 1;
							solve(na, nb, i + 1, n, LESS);
						}
						else {
							na[i] = '9';
							solve(na, nb, i + 1, n, GREAT);
						}
					}
					else if (a[i] != '?' && b[i] != '?') {
						na[i] = a[i], nb[i] = b[i];
						if (a[i] < b[i]) solve(na, nb, i + 1, n, LESS);
						else solve(na, nb, i + 1, n, GREAT);
					}
				}
				else {
					break;
				}
			}
			ra = to_string(ans_a), rb = to_string(ans_b);
			while (ra.size() < n) ra = '0' + ra;
			while (rb.size() < n) rb = '0' + rb;
		}
		printf("Case #%d: %s %s\n", it, ra.c_str(), rb.c_str());
	}
	
	return 0;
}
