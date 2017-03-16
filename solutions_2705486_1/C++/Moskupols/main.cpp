#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <deque>
#include <set>
#include <fstream>
using namespace std;

#ifdef moskupols 
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 
#endif

const int triesize = 4000000, alph = 26;

bool isterm[triesize];
int ne[triesize][alph];
int tsz;

int mkNode()
{
	memset(ne[tsz], -1, sizeof ne[tsz]);
	isterm[tsz] = 0;
	return tsz++;
}

void init()
{
	tsz = 0;
	mkNode();
}

void addWord(string s)
{
	int v = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		unsigned char c = s[i] - 'a';
		if (ne[v][c] == -1)
			ne[v][c] = mkNode();
		v = ne[v][c];
	}
	isterm[v] = 1;
}

struct state
{
	int pr, tp, pen;
	state(int pr, int tp, int pen): pr(pr), tp(tp), pen(pen) {}
};
inline bool operator < (const state &a, const state &b)
{
	return make_pair(a.pr, make_pair(a.tp, a.pen)) < make_pair(b.pr, make_pair(b.tp, b.pen));
}

map<state, int> met;
deque<state> dq;

inline void relax(const state &v, const state &u, int add, char c)
{
	map<state, int>::iterator it = met.find(u);
	int r = met[v] + add;
	if (it == met.end())
		met[u] = r;
	else if (it->second > r)
		it->second = r;
	else
		return;
	if (add)
		dq.push_back(u);
	else
		dq.push_front(u);
//	debug(" -> %d %d %d %d (%c)\n", u.pr, u.tp, u.pen, met[u], c+'a');
}

int solve()
{
	string s;
	cin >> s;

	met.clear();
	dq.clear();

	dq.push_front(state(0, 0, 0));
	met[dq.front()] = 0;
	while (!dq.empty())
	{
		state v = dq.front();
		dq.pop_front();

//		debug("%d %d %d %d\n", v.pr, v.tp, v.pen, met[v]);

		if (v.pr == (int)s.size())
		{
			if (isterm[v.tp])
				return met[v];
			continue;
		}

		int c = s[v.pr] - 'a';

		if (v.tp && isterm[v.tp])
			relax(v, state(v.pr, 0, v.pen), 0, '0'-'a');

		if (ne[v.tp][c] != -1)
			relax(v, state(v.pr+1, ne[v.tp][c], max(0, v.pen-1)), 0, c);
		if (!v.pen)
		{
			for (int i = 0; i < alph; ++i)
				if (ne[v.tp][i] != -1)
					relax(v, state(v.pr+1, ne[v.tp][i], 4), 1, i);
		}
	}
	return -1;
}

int main()
{
	cin.sync_with_stdio(false);

	init();
	ifstream din;
	din.open("dict.txt");
	string w;
	while (din >> w)
		addWord(w);
	din.close();

	debug("%d\n", tsz);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}
