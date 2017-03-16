#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
#include <ctime>

#include <iostream>

#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>

//#pragma comment(linker, "/stack:64000000")

using namespace std;

template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 1010;

vector<int> g[N];
int in[N];
int c[N];

bool dfs(int v, int cur) {
	c[v] = 1;
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (c[to] == cur)
			return true;
		if (c[to] != 1) {
			if (dfs(to, cur))
				return true;
		} else {
			assert(false);
		}
	}
	c[v] = cur;
	return false;
}

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

        int test;
        scanf("%d\n", &test);
        forn(it, test) {
        	int n;
        	scanf("%d\n", &n);
        	memset(in, 0, sizeof in);
        	forn(i, n) {
        		int m;
        		scanf("%d", &m);
        		in[i] = m;
        		forn(j, m) {
        			int to;
        			scanf("%d", &to);
        			--to;
        			g[to].pb(i);
        		}
        	}
        	memset(c, 0, sizeof c);
        	bool flag = false;
        	forn(i, n)
        		if (in[i] == 0) {
        			if (dfs(i, i + 2)) {
        				flag = true;
        				break;
        			}	
        		}
		printf("Case #%d: %s\n", it + 1, flag ? "Yes" : "No");
		forn(i, n)
			g[i].clear();
        }


	return 0;
}
