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

int C, D, V;
set<int> st;
int sz, ans;

bool can() {
	static bool ok[N];
	memset(ok, false, sizeof ok);
	ok[0] = true;
	for (int v : st) {
		for (int j = V; j - v >= 0; j--)
			if (ok[j - v])
				ok[j] = true;
	}
	bool ret = true;
	FOR(i, V)
		ret = ret && ok[i];
	return ret;
}

void dfs(int i) {
	if ((int)st.size() > ans)
		return;

	if (i > V) {
		if (can())
			ans = min(ans, (int)st.size());
		return;
	}

	if (can()) {
		ans = min(ans, (int)st.size());
		return;
	}

	if (st.find(i) == st.end()) {
		st.insert(i);
		dfs(i + 1);
		st.erase(i);
		dfs(i + 1);
	} else
		dfs(i + 1);
}

int Main() {
	freopen("C-small-attempt0.in", "r", stdin);
//	freopen("out.txt", "w", stdout);

//	freopen("cf.txt", "r", stdin);
	ios_base::sync_with_stdio(0);



	int T;
	cin >> T;

	FOR(_T, T) {
		cin >> C >> D >> V;

		st.clear();
		REP(i, D) {
			int x;
			cin >> x;
			st.insert(x);
		}
		sz = st.size();
		ans = V;

		dfs(1);
		cout << "Case #" << _T << ": " << ans - sz << endl;
	}



	return 0;
}

int main() {
	return Main();
}
