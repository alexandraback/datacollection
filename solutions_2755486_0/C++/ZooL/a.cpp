#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;


#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"

int xabs(int x)
{
	return x < 0 ? -x : x;
}
const int MAXN = 4 * 20200000;
int t[MAXN][2] = {};
int build (int v, int tl, int tr) 
{					    
	if (tl == tr)
		t[v][1] = t[v][0] = 0;
	else 
	{
		int tm = (tl + tr) / 2;
		int t1 = build ( v * 2, tl, tm);
		int t2 = build ( v * 2 + 1, tm + 1, tr);
		t[v][1] = min(t1, t2);
		t[v][0] = 0;
	}
	return t[v][1];
}

void push (int v) 
{
	if (t[v][0] > 0) 
	{
		t[v * 2][1] = t[v * 2 + 1][1] = t[v * 2][0] = t[v * 2 + 1][0] = t[v][0];
		t[v][0] = 0;
	}
} 

void update (int v, int tl, int tr, int l, int r, int color) 
{
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v][1] = t[v][0] = max(t[v][0], color);
	else 
	{
		push (v);
		int tm = (tl + tr) / 2;
		update (v * 2, tl, tm, l, min(r, tm), color);
		update (v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, color);
		t[v][1] = min(t[2 * v][1],t[2 * v + 1][1]); 
	}
}
int getmin(int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return inf;
	if (l == tl && tr == r)
		return t[v][1];
	else 
	{
		push (v);
		int tm = (tl + tr) / 2;
		int t1 = getmin (v * 2, tl, tm, l, min(r, tm));
		int t2 = getmin (v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		return min(t1, t2); 
	}
}

int extra = 1010000;
int ms =  2020000;
int main()
{	
	freopen("input3.txt", "r", stdin); freopen("output2.txt", "w", stdout);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int N;
		cin >> N;
		set <pair<int, int> > atack;
		vector <int> di(N), ni(N), wi(N), ei(N), si(N), delta_di(N), delta_pi(N), delta_si(N);
		for (int i = 0; i < N; i++)
		{
			cin >> di[i] >> ni[i] >>  wi[i] >> ei[i] >> si[i] >> delta_di[i] >> delta_pi[i] >> delta_si[i];
			atack.insert(mp(di[i], i));
		}
		build(1,0, ms - 1);
		LL ans = 0;
		while(!atack.empty())
		{
			int day = atack.begin()->X;
			vector <int> now;
			while(!atack.empty() && atack.begin()->X == day)
			{
				now.pb(atack.begin()->Y);
				atack.erase(atack.begin());
			}
			for (int i = 0; i < now.size(); i++)
			{
				int pl = now[i];
				int mi = getmin(1, 0, ms - 1, wi[pl] + extra, ei[pl] + extra - 1);
				if (si[pl] > mi)
					ans++;
			}
			for (int i = 0; i < now.size(); i++)
			{
				int pl = now[i];
				if (si[pl] > 0)
					update(1, 0, ms - 1, wi[pl] + extra, ei[pl] + extra - 1, si[pl]);
				di[pl] += delta_di[pl];
				wi[pl] += delta_pi[pl];
				ei[pl] += delta_pi[pl];
				si[pl] += delta_si[pl];
				ni[pl] --;
				if (ni[pl] > 0)
				{
				   atack.insert(mp(di[pl], pl));
				}
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}						   
    return 0;
}
/*******************************************
*******************************************/
#endif