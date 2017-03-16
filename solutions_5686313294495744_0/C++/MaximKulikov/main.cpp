#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

typedef vector <int> vi;
typedef vector<vi>	vvi;

#define PROBLEM "C-small-attempt1"

int lcnt, rcnt;
vi isLeft, vis;
vvi e;
int T, t;

void dfs(int ind) {
	vis[ind] = 1;
	if (isLeft[ind])
		lcnt++;
	else
		rcnt++;
	for (int i = 0; i < (int)e[ind].size(); ++i) {
		int next = e[ind][i];
		if (!vis[next])
			dfs(next);
	}
}

void solve() {
	int ind = 1, n;
	map<string, int> dictL, dictR;
	cin >> n;
	string l, r;
	int m = 2 * (n + 1);
	isLeft = vi(m);
	e = vvi(m);
	vector <pair< int, int> > in(n);
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		int li = dictL[l], ri = dictR[r];
		if (li == 0) {
			li = dictL[l] = ind++;
			isLeft[li] = 1;
		}
		if (ri == 0) {
			ri = dictR[r] = ind++;
			isLeft[ri] = 0;
		}
		e[li].push_back(ri);
		e[ri].push_back(li);
		in[i].first = li;
		in[i].second = ri;
	}

	m = ind;
	int res = 0;
	vis = vi(m, 0);
	for (int i = 1; i < m; ++i) {
		if (!vis[i]) {
			lcnt = 0;
			rcnt = 0;
			dfs(i);
			res += lcnt > rcnt ? lcnt : rcnt;
		}
	}
	int ans = (n - res);

	int best = 0;
	for (int i = 0; i < (1 << n); ++i) {
        int w = n;
        for (int ii = i; ii; ii = ii & (ii - 1)) --w;
        if (w <= best) continue;

        bool ok = true;
        for (int j = 1; j < m && ok; ++j) {
            bool covered = false;
            for (int k = 0; k < n; ++k) {
                if ((i & (1 << k)) == 0) continue;
                if (j == in[k].first && !isLeft[j] || j == in[k].second && isLeft[j]) throw "$%^%$^&*";
                if (j == in[k].first || j == in[k].second) {
                    covered = true;
                    break;
                }
            }
            ok = ok && covered;
        }
        if (ok) {
            best = w;
        }
	}
    if (best != ans) {
        cerr << "Case: " << t << "   Best: " << best << "    Ans: " << ans << endl;
    }

	std::cout << best << std::endl;
}

int main()
{
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	std::cin >> T;

	for (t = 1; t <= T; ++t) {
		std::cout << "Case #" << t << ": ";
		solve();
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
