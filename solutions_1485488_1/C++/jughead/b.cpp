#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#define ll long long
#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair <int, int>
#define ff first
#define ss second
#define ldb long double
#define sqr(a) ((a) * (a))
#define nextLine() {int c = 0; while((c = getchar()) != 10 && c != EOF);}
#define addEdge(a, b) next[edges] = first[a]; first[a] = edges; end[edges] = a;
#define debug(a) cerr << #a << " = " << (a) << " ";
#define debugl(a) cerr << #a << " = " << (a) << "\n";
const ldb eps = 1e-12;
const ldb pi = fabsl(atan2l(0.0, -1.0));
const ll inf = 1 << 28;
using namespace std;
#define problem "b"

int n, m, H;
int c[123][123];
int f[123][123];
#define MV 10011
const int di[] = {0, 0, 1, -1};
const int dj[] = {-1, 1, 0, 0};


int fst[MV], nxt[8 * MV], end[8 * MV], edgs; 
ldb from[8 * MV], d[MV];

class compare
{
	public:
		bool operator ()(int a, int b)
		{
			return d[a] < d[b] - eps || fabsl(d[a] - d[b]) < eps && a < b;
		}
};


set <int, compare> was;

inline int code(int i, int j)
{
	return i * m + j;
}

void load()
{
	cin >> H >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j =0; j < m; j++)
		{
			cin >> f[i][j];
		}
	}
}

inline bool can(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}

inline void add_edge(int i, int j, ldb f)
{
	nxt[edgs] = fst[i];
	fst[i] = edgs;
	end[edgs] = j;
	from[edgs] = f;
	edgs++;
}

ldb get_cost(int ver, int u)
{
	ldb ct = max(d[ver], from[u]);
	if (fabsl(ct) < eps)
		return ct;
	else if (H - ct * 10.0 > f[ver / m][ver % m] + 20 - eps)
		return ct + 1;
	else
		return ct + 10;
}

void solve(int test_number)
{
	cerr << "Case #" << test_number << "\n";
	memset(fst, -1, sizeof(int) * (n * m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			d[code(i, j)] = 1e42;
			for (int k = 0; k < 4; k++)
			{
				int _i = i + di[k];
				int _j = j + dj[k];
				if (can(_i, _j))
				{
					ldb l = 0;
					ldb r = H / 10, t, h;
					bool yeah = false;
					bool ok;
					for (int o = 0; o < 200; o++)
					{
						t = (l + r) * 0.5;
						h = H - t * 10.0;
						ok = max(h, (ldb)f[i][j]) < c[_i][_j] - 50 + eps
							&& f[_i][_j] < c[i][j] - 50 + eps && max(h, (ldb)f[i][j]) < c[i][j] - 50 + eps;
						yeah |= ok;
						if (ok)
							r = t;
						else l = t;
					}
//					cerr << i << "," << j << " => " << _i << "," << _j << "  H = " << H - r * 10.0 << " T = " << r << "\n";
					if (yeah)
					{
						if (H - r * 10.0 > f[i][j] + 20.0 - eps)
							add_edge(code(i, j), code(_i, _j), r);
						else
							add_edge(code(i, j), code(_i, _j), r);
					}
				}
			}
		}
	}
	cout << "Case #" << test_number << ": ";
	d[0] = 0;
	was.clear();
	was.insert(0);
	int ver;
	while (!was.empty())
	{
		ver = *was.begin();
	//	cerr << ver / m << " " << ver % m << " " << d[ver] << "\n";
		if (ver == n * m - 1)
		{
			cout << setprecision(10) << fixed << d[ver] << "\n";
			return;
		}
		was.erase(was.begin());
		for (int u = fst[ver]; u != -1; u = nxt[u])
		{
			if (d[end[u]] > get_cost(ver, u) + eps)
			{
				if (was.find(end[u]) != was.end())
					was.erase(end[u]);
				d[end[u]] = get_cost(ver, u);
				was.insert(end[u]);
			}
		}
	}
	throw 42;
}

int main()
{
	freopen(problem ".in", "rt", stdin);
	freopen(problem ".out", "wt", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
	return 0;
}

