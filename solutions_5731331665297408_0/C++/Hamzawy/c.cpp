/*
 * c.cpp
 *
 *  Created on: May 3, 2014
 *      Author: AhmedSamir
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef _MSC_VER
#define rep(i,m) for(decltype(m) i=0;i<m;i++)
#define repI(i,m) for(decltype(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(decltype(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#else
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define repI(i,m) for(__typeof(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(__typeof(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define EPS (1e-9)
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

#define SMALL_INPUT
//#define LARGE_INPUT

int ind[10];
vector<unordered_set<int> > adj;
int n, m, x, y;
char zip[10][7];

bool valid()
{
	stack<int> s;
	s.push(ind[0]);
	for (int i = 1; i < n; ++i)
	{
		while (!s.empty() && adj[ind[i]].find(s.top()) == adj[ind[i]].end())
		{
			s.pop();
		}
		if (s.empty()) return 0;
		s.push(ind[i]);
	}
	return 1;
}

string toStr()
{
	string res;
	for (int i = 0; i < n; ++i)
		res += zip[ind[i]];
	return res;
}
int main()
{
	freopen("c.in", "rt", stdin);
#ifdef SMALL_INPUT
	freopen("c-small-attempt0.in", "rt", stdin);
	freopen("c-small.txt", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("c-large.in", "rt", stdin);
	freopen("c-large.txt", "wt", stdout);
#endif
	int tc;
	scanf("%d", &tc);
	rep(T,tc)
	{
		scanf("%d%d", &n, &m);
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", zip[i]);
			ind[i] = i;
		}

		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &x, &y);
			adj[x - 1].insert(y - 1);
			adj[y - 1].insert(x - 1);
		}

		string res(n * 5, '9');
		do
		{
			if (valid()) res = min(res, toStr());
		} while (next_permutation(ind, ind + n));
		printf("Case #%d: %s\n", T + 1, res.c_str());

#ifdef SMALL_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}
