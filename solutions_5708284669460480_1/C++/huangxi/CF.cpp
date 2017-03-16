#include <bits/stdc++.h>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); ++i)
#define  FOR(i, n)  for (int i=1; i<=int(n); ++i)
#define  pii        pair<int, int>
#define  piL        pair<int, long long>
#define  mp         make_pair
#define  pb         push_back
#define  whatis(x)  cout << #x << ": " << x << endl;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

using namespace std;
#define  N   123
#define  eps 1e-9
#define  pi  acos(-1.0)
#define  inf 0XFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long


double p[N];

int Main() {
	freopen("B-large.in", "r", stdin);
//	freopen("out.txt", "w", stdout);

//	freopen("cf.txt", "r", stdin);
	ios_base::sync_with_stdio(0);



	int T;
	cin >> T;

	FOR(_T, T) {
		int K, L, S;
		cin >> K >> L >> S;

		string key, word;
		cin >> key >> word;

		REP(i, 26) {
			int cnt = 0;
			for (char c : key) if (c == 'A' + i)
				cnt++;
			p[i] = 1.0 * cnt / K;
		}

		double ans = 1.0;
		bool can = true;
		for (char c : word) {
			ans *= p[c - 'A'];
			if (p[c - 'A'] < eps)
				can = false;
		}



		ans *= (S - L + 1);

		int banana = 0;
		if (L == 1) {
			if (p[word[0] - 'A'] > eps)
				banana = S;
		} else if (can) {
			int mx = 0;
			for (int i = 1; i < L; i++) {
				bool ok = true;
				for (int j = 0; j < i; j++)
					if (word[L - j - 1] != word[i - j - 1])
						ok = false;
				if (ok)
					mx = i;
			}

			for (int i = 0; i + L - 1 < S; i += L - mx) {
				if (i + L - 1 < S)
					banana++;
			}

		}

		double res = 1.0 * banana - ans;

		cout << fixed << setprecision(10);
		cout << "Case #" << _T << ": " << res + eps << endl;
	}



	return 0;
}

int main() {
	return Main();
}
