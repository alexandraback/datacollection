#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 10;

int t;
int n, m;
string z[MAXN];
string ans;
bool e[MAXN][MAXN];
vector <int> v;
vector <int> p;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &t);
	for (int tn = 1; tn <= t; tn++) {

		memset(e, 0, sizeof(e));
		ans = "";
		scanf("%d %d\n", &n, &m);

		for (int i = 1; i <= n; i++)
			getline(cin, z[i]);

		for (int i = 1; i <= m; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			e[from][to] = e[to][from] = true;
		}

		v.clear();
		for (int i = 1; i <= n; i++)
			v.push_back(i);

		do {

			string curs = "";
			for (int i = 0; i < n; i++)
				curs = curs + z[v[i]];

			bool pos = false;

			p.clear();
			p.push_back(v[0]);
			int cur = 1;

			while (true) {
				if (cur >= n) {
					pos = true;
					break;
				}

				if (p.empty())
					break;

				int c = p.back();
				if (e[c][v[cur]]) {
					p.push_back(v[cur]);
					cur++;
					continue;
				}
				else {
					p.pop_back();
				}
			}

			if (pos) {
				if (ans == "" || curs < ans)
					ans = curs;
			}

		} while (next_permutation(v.begin(), v.end()));

		printf("Case #%d: ", tn);
		cout << ans << endl;

	}

	return 0;
}