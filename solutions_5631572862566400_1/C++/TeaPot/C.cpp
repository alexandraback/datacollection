#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 2000;

int a[MAXN], num[MAXN], color[MAXN];
bool is_happy[MAXN];
vector <int> happy;
vector <int> adj[MAXN];
int n;

int dfs (int v) {
	int cur = 0;
	for (int i = 0; i < sz(adj[v]); ++i) {
		cur = max(cur, dfs(adj[v][i]));
	}
	return cur + 1;
}

int get_res() {
	int res = 0;

	int cur_color = 0;
	for (int i = 0; i < n; ++i) {
		if (color[i] == -1) {
			int v = i;
			int cur_num = 0;
			while (color[v] == -1) {
				color[v] = cur_color;
			    num[v] = cur_num;
			    cur_num++;
				v = a[v];
			}

			if (color[v] == cur_color) {
				res = max(res, cur_num - num[v]);
			
			    assert (cur_num - num[v] != 1);
			    if (cur_num - num[v] == 2) {
			   		happy.pb(v);
			   		happy.pb(a[v]);
			   		is_happy[v] = is_happy[a[v]] = true;
			    }
			}

			cur_color++;
		}
   	}

   	for (int i = 0; i < n; ++i) {
   		if (!is_happy[i]) {
   			adj[a[i]].pb(i);
   		}
   	}

   	int cur = 0;
   	for (int i = 0; i < sz(happy); ++i) {
   		cur += dfs(happy[i]);
   	}

   	res = max(res, cur);

   	return res;
}

void clear() {
	happy.clear();
	for (int i = 0; i < n; ++i) {
		num[i] = -1;
		color[i] = -1;
		is_happy[i] = false;
		adj[i].clear();
	}
}

int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i]--;
		}

		clear();
		int res = get_res();
		
		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}
