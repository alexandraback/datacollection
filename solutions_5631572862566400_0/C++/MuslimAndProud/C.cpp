#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#define REP(i, a, b)		for(i = (int)a; i<=(int)b ; i++)
#define FOR(i, N)			REP(i, 0, N-1)

#define II					pair<int, int>
#define fst					first
#define scd					second

#define VI					vector<int>
#define VB					vector<bool>
#define VII					vector<II>

using namespace std;

int N;
VI v;
VI bst;
VB rnd;
VII pr;

int cal(int st) {
	VB done(N);
	int n = 0;
	int cur = st;
	while (!done[cur]) {
		if (rnd[cur]) {
			bst[cur] = max(n, bst[cur]);
			return 0;
		}

		done[cur] = true;
		n++;
		cur = v[cur];
	}
	if (cur == st)
		return n;
	return 0;
}

int main(){
	ifstream cin("C.in");
	ofstream cout("C-Small.out");

	int t, T;
	cin >> T;
	REP(t, 1, T) {
		int i, j;
		cin >> N;

		v = VI(N);
		FOR(i, N) {
			cin >> v[i];
			v[i]--;
		}

		bst = VI(N);
		rnd = VB(N);
		pr = VII();
		FOR(i, N) if (v[v[i]] == i) {
			rnd[i] = true;
			if (i < v[i])
				pr.push_back(II(i, v[i]));
		}

		int ans = 0;
		// circular
		FOR(i, N) {
			int n = cal(i);
			ans = max(n, ans);
		}
		// single pair
		FOR(i, N) if (rnd[i]) {
			int n = bst[i] + 2 + bst[v[i]];
			ans = max(n, ans);
		}
		// two pairs (with the remaining pairs between them)
		FOR(i, N) REP(j, (i + 1), (pr.size()-1)) {
			int n = 2 * pr.size();
			int n1 = bst[pr[i].fst];
			int n2 = bst[pr[i].scd];
			int n3 = bst[pr[j].fst];
			int n4 = bst[pr[j].scd];
			n += max(n1, n2) + max(n3, n4);
			ans = max(n, ans);
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}