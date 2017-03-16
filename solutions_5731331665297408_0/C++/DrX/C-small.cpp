#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;


#define clr(x) memset(x, 0, sizeof(x))
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 8;

bool ad[N][N];
int res[N][N];
int n;


bool DFS (const vector<int> &p, int cur, int cnt, int left) {
	int i, j, k;
	if (cnt == n) {
		if (left == 0) return true;
		for (i = 0; i < n; ++i) if (res[cur][i]) {
			res[cur][i] --;
			if (DFS (p, i, cnt, left - 1)) return true;
			res[cur][i]++;
		}
		return false;
	}
	else {
		if (ad[cur][p[cnt]]) {
			res[p[cnt]][cur] ++;
			if (DFS (p, p[cnt], cnt+1, left + 1)) return true;
			res[p[cnt]][cur] --;
		}
		for (i = 0; i < n; ++i) if (res[cur][i]) {
			res[cur][i] --;
			if (DFS (p, i, cnt, left - 1)) return true;
			res[cur][i]++;
		}
		return false;
	}
}

int main () {
	int i, j, k, ca, T, m;

	//freopen ("A-large.in", "r", stdin);
	//freopen ("a-out-large.txt", "w", stdout);

	ifstream fin("in.txt");
	ofstream fout("out.txt");

	fin >> T;
	for (ca = 1; ca <= T; ++ca) {
		memset (ad, false, sizeof(ad));

		fin >> n >> m;
		vector<int> perm;
		vector<string> zip;

		for (i = 0; i < n; ++i) {
			string z;
			fin >> z;
			zip.pb(z);
			perm.pb(i);
		}

		for (; m; --m) {
			fin >> i >> j;
			--i; --j;
			ad[i][j] = ad[j][i] = true;
		}
		vector<pair<string, vector<int> > > profile;
		do {
			string z;
			for (i = 0; i < n; ++i) z += zip[perm[i]];
			profile.pb(mp(z, perm));
		}while (next_permutation(perm.begin(), perm.end()));

		sort(profile.begin(), profile.end());
		int pn = profile.size();
		string ans;
		for (int mask = 0; mask < pn; ++mask) {
			vector<int> p = profile[mask].second;
			//for (i = 0; i < n; ++i) printf ("%d%c", p[i], i == n - 1 ? '\n' : ' ');
			memset (res, 0, sizeof(res));
			if (DFS(p, p[0], 1, 0)) {
				ans = profile[mask].first;
				break;
			}
		}
		fout << "Case #" << ca << ": " << ans << endl;
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
