#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL unsigned long long
#define EPS 0.00000000000001
#define MOD 1000000009
#define INF 1000000000000000000LL
#define N 1110

typedef struct{ int f, s; }ta;

int g[N][N];
int glen[N];

vector<int> mt;
vector<char> used;

bool try_kuhn(int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i = 0; i < glen[v]; ++i)
	{
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn(mt[to]))
		{
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main()
{
//#ifdef _DINARISIO
	ifstream cin("C-large.in");
	ofstream cout("C2.out");
//#endif

	int T;
	cin >> T;
	map<string, int> allS;
	map<string, int> allF;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t + 1 << ": ";

		int n;
		cin >> n;
		memset(glen, 0, sizeof(glen));
		allS.clear();
		allF.clear();
		map<string, int>::iterator it;

		int scnt = 0, fcnt = 0;

		for (int i = 0; i < n; ++i)
		{
			string f, s;
			cin >> f >> s;

			int vf, vs;
			it = allF.find(f);
			if (it != allF.end())
			{
				vf = it->second;
			}
			else
			{
				fcnt++;
				vf = i;
				allF.insert(make_pair(f, i));
			}

			it = allS.find(s);
			if (it != allS.end())
			{
				vs = it->second;
			}
			else
			{
				scnt++;
				vs = i;
				allS.insert(make_pair(s, i));
			}

			g[vs][glen[vs]++] = vf;
		}
		int cntPar = 0;
		mt.assign(n, -1);
		for (int v = 0; v < n; ++v)
		{
			used.assign(n, false);
			if (try_kuhn(v))
			{
				cntPar++;
			}
		}

		cout << n - (cntPar + (scnt - cntPar + fcnt - cntPar)) << endl;
	}
	re 0;
}