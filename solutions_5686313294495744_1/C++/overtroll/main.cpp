#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 3001;
map <string, int> m1;
map <string, int> m2;
vector <int> e[MAXN];
int p[MAXN];
bool w[MAXN];

bool dfs(int v)
{
	if (v == -1) return true;
	if (w[v]) return false;
	w[v] = true;
	for (int i = 0; i < e[v].size(); i++)
	{
		if (dfs(p[e[v][i]]))
		{
			p[e[v][i]] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int iter = 1; iter <= t; iter++)
	{
		cout << "Case #" << iter <<": ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) e[i].clear();
		m1.clear();
		m2.clear();
		for (int i = 0; i < n; i++) p[i] = -1;
		int n1 = 0, n2 = 0;
		for (int i = 0; i < n; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			if (m1.find(s1) == m1.end()) m1[s1] = n1++;
			if (m2.find(s2) == m2.end()) m2[s2] = n2++;
			e[m1[s1]].push_back(m2[s2]);
		}
		for (int i = 0; i < n2; i++) p[i] = -1;
		int ans = n - n1 - n2;
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n1; j++) w[j] = false;
			if (dfs(i)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}