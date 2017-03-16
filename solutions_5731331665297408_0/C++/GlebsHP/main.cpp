#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 100;

set <int> vertex[size];
vector <int> cur;
int idx[size];
int col[size];
bool used[size];
int n, m;
int tc;

void dfs(int v) {
	if (col[v] == 2)
		return;
	used[v] = true;
	for (set <int>::iterator it = vertex[v].begin(); it != vertex[v].end(); ++it)
		if (!used[*it])
			dfs(*it);
}

bool verify(int v) {
	for (int i = 0; i < n; i++)
		used[i] = false;
	dfs(v);
	for (int i = 0; i < n; i++)
		if (!used[i] && col[i] == 0) {
			cerr << "failed " << i << endl;
			return false;
		}
	return true;
}

bool couldgo(int tg) {
	int p = (int) cur.size() - 1;
	while (p >= 0 && vertex[cur[p]].find(tg) == vertex[cur[p]].end())
		p--;
	cerr << "could " << tg << ' ' << p << endl;
	if (p < 0)
		return false;
	else {
		for (int i = (int) cur.size() - 2; i >= p; i--) {
			vertex[cur[i + 1]].erase(cur[i]);
			col[cur[i + 1]] = 2;
		}
		vertex[cur[p]].erase(tg);

		bool ans = verify(tg);

		vertex[cur[p]].insert(tg);
		for (int i = (int) cur.size() - 2; i >= p; i--) {
			vertex[cur[i + 1]].insert(cur[i]);
			col[cur[i + 1]] = 1;
		}
		cerr << "cont " << ans << endl;

		return ans;
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> n >> m;
    	for (int i = 0; i < n; i++) {
    		vertex[i].clear();
    		col[i] = 0;
    	}
       	int v, u;
       	vector <pair <int, int> > tovisit;
       	for (int i = 0; i < n; i++) {
       		cin >> idx[i];
       		tovisit.pb(mp(idx[i], i));
       	}

       	sort(tovisit.begin(), tovisit.end());
       	for (int i = 0; i < m; i++) {
       		cin >> v >> u;

       		v--, u--;
       		vertex[v].insert(u);
       		vertex[u].insert(v);
       	}

       	cur.clear();
       	cur.pb(tovisit.begin()->sc);
       	//cerr << tovisit.begin()->sc << ' ' << tovisit.begin()->fs << endl;
       	//tovisit.erase(tovisit.begin());

       	//cerr << cur[0] << ' ' << idx[cur[0]] << endl;
       	cout << "Case #" << tnum + 1 << ": " << idx[cur[0]];
       	//cerr << idx[cur[0]];
       	col[cur[0]] = 1;

       	for (int i = 0; i < n - 1; i++) {
       		for (int j = 0; j < n; j++)
       			if (col[tovisit[j].sc] == 0 && couldgo(tovisit[j].sc)) {
       				//cerr << tovisit[j].sc << endl;
       				while (vertex[cur.back()].find(tovisit[j].sc) == vertex[cur.back()].end()) {
       					vertex[cur.back()].erase(cur[(int) cur.size() - 2]);
       					col[cur.back()] = 2;
       					cur.pop_back();
       				}
       				vertex[cur.back()].erase(tovisit[j].sc);
       				col[tovisit[j].sc] = 1;
       				cur.pb(tovisit[j].sc);
       				cout << idx[cur.back()];
       				cerr << tnum << ' ' << cur.back() << endl; 

       				break;
       			}
       	}

       	//cerr << endl;
       	cout << endl;
    }


    return 0;
}