#include <bits/stdc++.h>
using namespace std;
#define forn(i, n)    for (int i = 0; i < (int)(n); ++i)
#define ford(i, n)    for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define DB(v) cerr << #v << ": " << v << endl
#define fi first
#define se second


vector<int> prefix(const string& s)
{
	int n = s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[j] != s[i])
			j = pi[j - 1];
		if (s[j] == s[i])
			++j;
		pi[i] = j;
	}
	return pi;
}

string s, t;
double prob[27];
int aut[107][27];
double dp[103][103][103];

const int alphabet = 27;

void outAns(int u, double ans)
{
	cout << "Case #" << u << ": " << ans << '\n';
}

int main()
{
	cout.precision(12);
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T; cin >> T;
	for (int u = 1; u <= T; ++u) {
		int K, L, S;
		cin >> K >> L >> S;
		cin >> s >> t;
		t += '\0';

		// check
		bool good = true;
		for (int i = 0; i < L; ++i) if (find(s.begin(), s.end(), t[i]) == s.end())
			good = false;
		if (!good) {
			outAns(u, 0);
			continue;
		}

		vector<int> pi = prefix(t);

		int rem = L - pi[L - 1];
		int maxOcc = (S - (L - rem)) / rem;

		memset(aut, 0, sizeof(aut));
		memset(dp, 0, sizeof(dp));
		memset(prob, 0, sizeof(prob));

		forn(i, K) {
			prob[int(s[i] - 'A')] += 1.0 / K;
		}

		++L;
		for (int i = 0; i < L; ++i) {
			for (int c = 0; c < alphabet; ++c) {
				if (i > 0 && 'A' + c != t[i]) {
					aut[i][c] = aut[pi[i - 1]][c];
				} else {
					aut[i][c] = i + ('A' + c == t[i]);
				}
			}
		}

		dp[0][0][0] = 1.0;
		forn(i, S) forn(state, L) forn(occ, S + 1) {
			forn(c, alphabet) {
				dp[i + 1][aut[state][c]][occ + (aut[state][c] == L - 1)] += prob[c] * dp[i][state][occ];
			}
		}

		double ans = maxOcc;
		forn(state, L) forn(occ, S + 1) {
			ans -= dp[S][state][occ] * occ;
		}

		outAns(u, ans);
	}

#ifdef HOME
	//cout << "\nTime elapsed: " << clock() << '\n';
#endif
	return 0;
}
