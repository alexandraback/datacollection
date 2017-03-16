/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;

const int N = 3001;

int tests;
int n;
string st1[N], st2[N];
int dp[1 << 17];
int ts;

set<string> s1, s2;
int used[N];
map<string,int> cnt1, cnt2;
vector<int> g[N];
int k;

int mt[N];

bool try_kuhn(int v)
{
	if (used[v])
		return false;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
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

set<string> words1, words2;
set<string>::iterator it;
vector<string> v1, v2;
map<string, int> map1, map2;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> n;
		++ts;
		words1.clear();
		words2.clear();
		for (int i = 1; i <= n; i++)
		{
			cin >> st1[i] >> st2[i];
			words1.insert(st1[i]);
			words2.insert(st2[i]);
		}
		v1.clear();
		v2.clear();
		
		map1.clear();
		map2.clear();

		for (it = words1.begin(); it != words1.end(); it++)
		{
			v1.push_back(*it);
			map1[*it] = v1.size();
		}
		for (it = words2.begin(); it != words2.end(); it++)
		{
			v2.push_back(*it);
			map2[*it] = v2.size();
		}

		for (int i = 1; i <= v1.size(); i++)
		{
			g[i].clear();
		}
		for (int i = 1; i <= v2.size(); i++)
		{
			g[i].clear();
		}

		for (int i = 1; i <= n; i++)
		{
			int id1 = map1[st1[i]];
			int id2 = map2[st2[i]];
			g[id1].push_back(id2);
		}

		for (int i = 0; i <= v2.size(); i++)
			mt[i] = -1;
		for (int v = 1; v <= v1.size(); v++)
		{
			for (int i = 0; i <= v1.size(); i++)
				used[i] = 0;
			try_kuhn(v);
		}
		
		int need_moves = v1.size() + v2.size();
		for (int i = 1; i <= v2.size(); i++)
		{
			if (mt[i] != -1)
				-- need_moves;
		}

		cerr << "Case #" << ts << ": " << n - need_moves << endl;
		cout << "Case #" << ts << ": " <<n-need_moves << endl;
	}

	cin.get(); cin.get();
	return 0;
}