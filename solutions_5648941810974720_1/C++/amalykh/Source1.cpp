#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <utility>
#include <ctime>
#include <string>

using namespace std;

typedef long long ll;

#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))

string u[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

vector<pair<char, int>> g;

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	g.push_back(mp('Z', 0));
	g.push_back(mp('X', 6));
	g.push_back(mp('W', 2));
	g.push_back(mp('G', 8));
	g.push_back(mp('H', 3));
	g.push_back(mp('S', 7));
	g.push_back(mp('R', 4));
	g.push_back(mp('V', 5));
	g.push_back(mp('I', 9));
	g.push_back(mp('O', 1));

	int te;
	cin >> te;
	for (int w = 0; w < te; w++)
	{
		string s;
		cin >> s;
		int a[26];
		ZERO(a);
		for (int i = 0; i < s.size(); i++)
			a[s[i] - 'A']++;
		vector<int> ans;
		for (int i = 0; i < g.size(); i++)
		{
			int c = g[i].first - 'A';
			while (a[c] > 0)
			{
				int t = g[i].second;
				ans.push_back(t);
				for (int j = 0; j < u[t].size(); j++)
					a[u[t][j] - 'A']--;
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", w + 1);
		for (auto el : ans) printf("%d", el);
		printf("\n");
	}

	return 0;
}