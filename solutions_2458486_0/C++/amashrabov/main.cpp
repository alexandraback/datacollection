#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> T inline sqr(T x) {
    return x * x;
}
#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) (int)((v).size())
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

vi solve();

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		cout << "Case #" << i + 1 << ": ";
		vi res = solve();
		if (res.empty())
			cout << "IMPOSSIBLE";
		else
			for (size_t i = 0; i < res.size(); i++)
				cout << res[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}

const int maxn = (1 << 20) + 10;
int par[maxn];

vi solve()
{
	for (int i = 0; i < maxn; i++) par[i] = -1;
	int k, n;
	cin >> k >> n;
	vi st(k);
	for (int i = 0; i < k; i++)
		cin >> st[i];
	vector<vi> inside(n);
	vi t(n);
	for (int i = 0; i < n; i++)
	{
		int q;
		cin >> t[i] >> q;
		inside[i].resize(q);
		for (int j = 0; j < q; j++)
			cin >> inside[i][j];
	}
	par[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int msk = q.front();
		q.pop();
		map<int, int> elem;
		for (int i = 0; i < st.size(); i++)
			elem[st[i]]++;
		for (int i = 0; i < n; i++)
			if (msk & (1 << i))
			{
				elem[t[i]]--;
				for (int j = 0; j < inside[i].size(); j++)
					elem[inside[i][j]]++;
			}
		for (int i = 0; i < n; i++)
			if ((msk & (1 << i)) == 0 && par[msk + (1 << i)] == -1)
			{
				if (elem[t[i]] > 0)
				{
					par[msk + (1 << i)] = i;
					q.push(msk + (1 << i));
				}
			}
	}

	if (par[(1 << n) - 1] == -1)
		return vi();
	else
	{
		vi res;
		int u = (1 << n) - 1;
		while (u != 0)
		{
			int v = par[u];
			res.push_back(v);
			u -= (1 << v);
		}
		reverse(res.begin(), res.end());
		return res;
	}
}
