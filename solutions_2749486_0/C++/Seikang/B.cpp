//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

queue<pair<ii, string> > q;
set<ii> mark;
string bfs(int x, int y)
{
	q = queue<pair<ii, string> >();
	q.push(make_pair(make_pair(0, 0), ""));
	int lvl = 0;
	//DEBUG(lvl);
	while(!q.empty())
	{
		//DEBUG(lvl);
		pair<ii, string> curr = q.front();
		q.pop();
		if(curr.second.size() == lvl)
		{
			mark.clear();
			lvl++;
		}

		int a = curr.first.first, b = curr.first.second;
		string s = curr.second;

		if(a == x && b == y)
			return s;

		pair<ii, string> N = make_pair(make_pair(a, b + lvl), s + "N");
		pair<ii, string> S = make_pair(make_pair(a, b - lvl), s + "S");
		pair<ii, string> E = make_pair(make_pair(a + lvl, b), s + "E");
		pair<ii, string> W = make_pair(make_pair(a - lvl, b), s + "W");

		if(mark.find(N.first) == mark.end())
		{
			mark.insert(N.first);
			q.push(N);
		}
		if(mark.find(S.first) == mark.end())
		{
			mark.insert(S.first);
			q.push(S);
		}
		if(mark.find(E.first) == mark.end())
		{
			mark.insert(E.first);
			q.push(E);
		}
		if(mark.find(W.first) == mark.end())
		{
			mark.insert(W.first);
			q.push(W);
		}
	}
	assert(false);
}

int main()
{
//	freopen ("in.txt", "rt", stdin);
//	freopen ("out.txt", "wt", stdout);

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int x, y;
		cin >> x >> y;

		cout << "Case #" << t + 1 << ": " << bfs(x, y) << endl;
	}
	return 0;
}
