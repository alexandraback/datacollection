#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef pair<int, int> pii;

#define MAXN 1003
int N;
int F[MAXN];
vector<int> RF[MAXN];
int ufd[MAXN]; // only path compression
int ufdsz[MAXN];
int longest[MAXN];

int find(int n) {
	ufd[n] = ufd[n] == n ? n : find(ufd[n]);
	return ufd[n];
}

void unon(int n, int m) {
	int rn = find(n);
	int rm = find(m);
	if (rn == rm) return;
	ufd[rm] = rn;
	ufdsz[rn] += ufdsz[rm];
}

int sz(int n) {
	return ufdsz[find(n)];
}

void ufd_init() {
	for (int i = 0; i < N; i++) {
		ufd[i] = i;
		ufdsz[i] = 1;
	}
}

int dfsUtil(int x, int t) {
	int ret = -1;
	for (int y : RF[x]) {
		if (find(y) != t) {
			ret = max(ret, dfsUtil(y, t));
		}
	}
	return ret + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("bff.in", "r", stdin);
	freopen("bff.out", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		cin >> N;
		for (int i = 0; i < N; i++) {
			RF[i].clear();
		}
		for (int i = 0; i < N; i++) {
			cin >> F[i];
			F[i]--;
			RF[F[i]].push_back(i);
		}
		ufd_init();

		// do our dfs-y thing
		for (int i = 0; i < N; i++) {
			set<int> s;
			int x;
			for (x = i; s.find(x) == s.end(); x = F[x]) {
				s.insert(x);
			}
			// ok now we know we're in a cycle
			for (int y = F[x]; y != x; y = F[y]) {
				unon(x, y);
			}
			int t = find(x);
			if (sz(t) != 2) continue;

			longest[t] = dfsUtil(x, t) + dfsUtil(F[x], t);
			longest[t] += sz(t);
		}

		int ans = 0;
		int best = 0;
		for (int i = 0; i < N; i++) {
			int szi = sz(i);
			if (szi == 2) {
				ans += longest[find(i)];
			}
			else if (szi > 2) {
				best = max(best, szi);
			}
		}
		ans /= 2;
		error(tc, ans, best);
		ans = max(ans, best);
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}
