#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 2000;
string A[N], B[N];
int n;

map <string, int> L, R;

void addWord(map <string, int> &m, string w)
{
	int sz = (int)m.size();
	if (m.count(w) == 0)
		m[w] = sz;
}

vector <int> g[N];
int match[N];
int par[N];
int used[N];
int cc = 1;

bool kuhn(int v)
{
	if (used[v] == cc)
		return false;
	used[v] = cc;
	for (int to : g[v])
	{
		if (par[to] == -1 || kuhn(par[to]))
		{
			par[to] = v;
			match[v] = to;
			return true;
		}
	}
	return false;
}

void solve()
{
	L.clear();
	R.clear();

	for (int i = 0; i < N; i++)
	{
		g[i].clear();
		par[i] = -1;
		match[i] = -1;
		used[i] = 0;
	}
	cc = 1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i];
		addWord(L, A[i]);
		addWord(R, B[i]);
	}
	for (int i = 0; i < n; i++)
	{
		g[L[A[i]]].push_back(R[B[i]]);
	}

	int matchSize = 0;
	while (1)
	{
		bool change = false;
		cc++;
		for (int i = 0; i < (int)L.size(); i++)
		{
			if (match[i] == -1 && used[i] != cc)
			{
				if (kuhn(i))
				{
					matchSize++;
					change = true;
				}
			}
		}
		if (!change)
			break;
	}
	int ans = n - ((int)L.size() + (int)R.size() - matchSize);
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
