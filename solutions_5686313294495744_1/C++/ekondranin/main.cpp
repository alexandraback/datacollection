#include <bits/stdc++.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif // M_PI
#define endl "\n"
#define S struct
#define X first
#define Y second
#define V vector
#ifndef __linux__
#define LLD "%I64d"
#else
#define LLD "%ll""d"
#endif
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int __i = 0; __i < (n); ++__i) cin >> a[__i];
#define GETM(a, n, m) for (int __i = 0; __i < (n); ++__i) for (int __j = 0; __j < m; ++__j) cin >> a[__i][__j];
#define PRINTM(a, n, m) for (int __i = 0; __i < (n); ++__i) { for (int __j = 0; __j < m; ++__j) cout << a[__i][__j] << " ";  cout << endl; };
#define PRINT(a, n) for (int __i = 0; __i < (n); ++__i) cout << a[__i] << " ";
#define IT(a) a.begin(), a.end()
#define SQR(x) (x) * (x)
#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;
#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();
#define DEBA(a) for (auto __i: a) cout << __i << " "; cout << endl; cout.flush();
#define IFDEB(b, a) if (b) { cout << #a << " = " << (a) << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef pair <LL, LL> PLL;
const int MOD = 1000000007;
void sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); }
S Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;


int n, k;
vector <vector <int>> g;
vector <int> mt;
vector <int> used;

bool try_kuhn (int x) {
	if (used[x]) {
        return 0;
	}
	used[x] = 1;
	for (auto i: g[x]) {
		if (mt[i] == -1 || try_kuhn (mt[i])) {
			mt[i] = x;
			return 1;
		}
	}
	return 0;
}

vector <vector <int>> g2;
vector <int> used2;

int dfs(int x)
{
    used2[x] = 1;
    for (auto i: g2[x]) {
        if (used2[i]) {
            continue;
        }
        dfs(i);
    }
    return 0;
}

int solve(int l)
{
    cerr << "CASE " << l + 1 << endl;
    int m;
    cin >> m;
    vector <pair <string, string>> v(m);
    FOR (i, 0, m) {
        cin >> v[i].first >> v[i].second;
    }
    map <string, int> s1;
    map <string, int> s2;
    for (auto i: v) {
        s1[i.first] = 0;
        s2[i.second] = 0;
    }
    n = 0;
    for (auto &i: s1) {
        i.second = n++;
    }
    k = 0;
    for (auto &i: s2) {
        i.second = k++;
    }
    vector <PII> edge;
    for (auto i: v) {
        edge.push_back({s1[i.first], s2[i.second]});
    }
    g.assign(n, vector <int> (0));
    for (auto i: edge) {
        g[i.first].push_back(i.second);
    }
    mt.assign(k, -1);
	FOR (i, 0, n) {
		used.assign(n, 0);
		try_kuhn(i);
	}
	int ans = n + k;
	FOR (i, 0, mt.size()) {
        if (mt[i] != -1) {
            --ans;
        }
	}
	CASE(l + 1, m - ans);
	/*g2.resize(n + k);
	for (auto i: edge) {
        if (mt[i.second] != i.first) {
            g2[i.first].push_back(n + i.second);
        } else {
            g2[n + i.second].push_back(i.first);
        }
	}
	set <int> good;
	FOR (i, 0, k) {
        if (mt[i] != -1) {
            good.insert(mt[i]);
            good.insert(n + i);
        }
    }
	used2.resize(n + k);
	FOR (i, 0, n + k) {
        if (used2[i] || good.count(i)) {
            continue;
        }
        dfs(i);
	}
	vector <vector <int>> ans(2);
	FOR (i, 0, k) {
        if (mt[i] == -1) {
            continue;
        }
        if (!used2[mt[i]]) {
            ans[0].push_back(mt[i]);
        }
	}
	FOR (i, 0, k) {
        if (mt[i] == -1) {
            continue;
        }
        if (used2[n + i]) {
            ans[1].push_back(i);
        }
	}
	sort(IT(ans[0]));
	sort(IT(ans[1]));
	cout << ans[0].size() + ans[1].size() << endl;
	vector <vector <int>> res1(n);
	vector <vector <int>> res2(k);
	FOR (i, 0, m) {
        if (binary_search(IT(ans[0]), edge[i].first)) {
            res1[edge[i].first].push_back(i);
        } else {
            res2[edge[i].second].push_back(i);
        }
	}
	for (auto i: res1) {
        if (i.size() == 0) {
            continue;
        }
        cout << i.size() << " ";
        for (auto j: i) {
            cout << j + 1 << " ";
        }
        cout << endl;
	}
	for (auto i: res2) {
        if (i.size() == 0) {
            continue;
        }
        cout << i.size() << " ";
        for (auto j: i) {
            cout << j + 1 << " ";
        }
        cout << endl;
	}*/
	return 0;
}

int main()
{
    int t;
    cin >> t;
    FOR (i, 0, t) {
        solve(i);
    }
}
