#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define oo 1e9
#define pi 3.1415926536
#define all(x) x.begin(),x.end()
#define sorta(x) sort(all(x))
#define sortam(x,comp) sort(x.rbegin(),x.rend(),comp)
#define sortd(x) sort(x.rbegin(),x.rend())
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
#define sfd(x) scanf("%f", &x)

typedef long long ll;
using namespace std;

int jp[15][15], js[15], ps[15];
bool comp(pair<int, int> a, pair<int, int> b) {
	return jp[a.first][a.second] < jp[b.first][b.second] ||
		(jp[a.first][a.second] == jp[b.first][b.second] && js[a.first] + ps[a.second] < js[b.first] + ps[b.second]) ||
		(jp[a.first][a.second] == jp[b.first][b.second] && js[a.first] + ps[a.second] == js[b.first] + ps[b.second] && js[a.first] < js[b.first]);
}


int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	sf(t);
	for(int tc = 1; tc <= t; tc++) {
		int J, P, S, K;
		sf3(J, P, S); sf(K);
		vector<pair<int, pair<int, int> > >res;
		memset(jp, 0, sizeof jp);
		for(int s = 1; s <= S; s++) {
			vector<pair<int, int> >q;
			for(int j = 1; j <= J; j++) {
				for(int p = 1; p <= P; p++)
					q.push_back({j, p});
			}
			memset(js, 0, sizeof js);
			memset(ps, 0, sizeof ps);
			while(q.size()) {
			sortam(q, comp);
				int j = q.back().first, p = q.back().second;
				q.pop_back();
				if(jp[j][p] >= K || js[j] >= K || ps[p] >= K)
					continue;

				res.push_back({j, {p, s}});
				jp[j][p]++;
				js[j]++;
				ps[p]++;
			}
		}

		printf("Case #%d: ", tc);
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++)
			cout << res[i].first << ' ' << res[i].second.first << ' ' << res[i].second.second << endl;
	}
	return 0;
}
