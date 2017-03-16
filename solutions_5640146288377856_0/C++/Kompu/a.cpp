#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

bool CanFit(VI& board, int ship)
{
	int l = 0;
	REP(x, SIZE(board))
	{
		if(board[x] == 0 || board[x] == 2) l++;
		else l = 0;
		if(l == ship) return true;
	}
	return false;
}

int Play(VI& board, int ship)
{
	// REP(x, SIZE(board)) cout << board[x];
	// cout << endl;

	int w = INF;
	int s = 0;
	REP(x, SIZE(board)) 
	{
		if(board[x] == 2)
		{
			s++;
		}
	}
	if(s == ship)
	{
		return 0;
	}
	REP(x, SIZE(board)) if(board[x] == 0)
	{
		int v = 0;
		VI miss(board);
		miss[x] = 1;
		if(CanFit(miss, ship))
		{
			int p = 0;
			for(int i = x - 1; i >= 0 && board[i] == 0; --i)
			{
				p++;
			}
			if(p < ship)
			{
				for(int i = x; p > 0 && i > 0; --p)
				{
					miss[--i] = 1;
				}
			}
			p = 0;
			for(int i = x + 1; i < SIZE(board); ++i)
			{
				p++;
			}
			if(p < ship)
			{
				for(int i = x; p > 0; --p)
				{
					miss[++i] = 1;
				}
			}
			v = Play(miss, ship) + 1;
		}

		VI hit(board);
		int left = -1, right = -1;
		for(int i = 0; i < x; ++i)
		{
			if(board[i] == 2)
			{
				left = i;
				break;
			}
		}
		for(int i = SIZE(board) - 1; i > x; --i)
		{
			if(board[i] == 2)
			{
				right = i;
				break;
			}
		}
		if((left != -1 && x - left >= ship) || (right != -1 && right - x >= ship))
		{
			w = min(w, v);
			continue;
		}
		hit[x] = 2;
		REP(i, SIZE(board)) if(abs(i - x) >= ship) hit[i] = 1;
		v = max(v, Play(hit, ship) + 1);
		w = min(w, v);
	}
	return w;
}

int main()
{
	int t;
	cin >> t;
	FOR(o, 1, t)
	{
		int r, c, w;
		cin >> r >> c >> w;
		VI board(c, 0);
		cout << "Case #" << o << ": " << Play(board, w) << endl;
	}
	return 0;
}