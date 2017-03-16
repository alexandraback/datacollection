#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int dirs[4][2] =
{
	1, 0,
	-1, 0,
	0, 1,
	0, -1,
};

vector < pair < int, int > > canonize(const vector < pair < int, int > > &a)
{
	int xMin = 1e9, yMin = 1e9;
	for (auto v : a)
		xMin = min(xMin, v.fst), yMin = min(yMin, v.snd);
	vector < pair < int, int > > res = a;
	for (auto &v : res)
		v.fst -= xMin, v.snd -= yMin;
	return res;
}

set < vector < pair < int, int > > > xminoes[10];
set < pair < int, int > > was;

void rec(int n, int ord)
{
	if (n == ord)
	{
		vector < pair < int, int > > a;
		for (auto x : was)
			a.pb(x);
		a = canonize(a);
		xminoes[ord].insert(a);
		return;
	}
	
	for (auto p : was)
	{
		for (int i = 0; i < 4; i++)
		{
			auto cp = mp(p.fst + dirs[i][0], p.snd + dirs[i][1]);
			if (was.count(cp))
				continue;
			was.insert(cp);
			rec(n + 1, ord);
			was.erase(cp);
		}
	}
	
}

bool checkBfs(vector < vector < int > > a, int k, int r, int c)
{
	auto valid = [&](int x, int y)
	{
		return 0 <= x && x < r && 0 <= y && y < c;
	};
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j])
				continue;
			
			int cnt = 0;
			queue < pair < int, int > > q;
			q.push(mp(i, j));
			a[i][j] = 1;
			
			while (!q.empty())
			{
				auto v = q.front();
				q.pop();
				
				cnt++;
						
				for (int h = 0; h < 4; h++)
				{
					int x = v.fst + dirs[h][0];
					int y = v.snd + dirs[h][1];
					
					if (!valid(x, y) || a[x][y])
						continue;
					a[x][y] = 1;
					q.push(mp(x, y));
				}
				
			}
			
			if (cnt % k)
			{
				return false;
			}
		}
	}
	
	return true;
}


ll ub;
ll iterCnt;
bool check(vector < vector < int > > &a, int k, int r, int c)
{
	if (iterCnt > ub)
		return false;
		
	iterCnt++;
	auto valid = [&](int x, int y)
	{
		return 0 <= x && x < r && 0 <= y && y < c;
	};
	
	bool any = false;
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j])
				continue;
				
			any = true;
				
			for (auto dm : xminoes[k])
			{
				bool good = true;
				for (auto p : dm)
				{
					int x = p.fst + i;
					int y = p.snd + j;
					if (!valid(x, y) || a[x][y])
					{
						good = false;
						break;
					}
				}
				
				if (good)
				{
					for (auto p : dm)
					{
						int x = p.fst + i;
						int y = p.snd + j;
						a[x][y] = 1;
					}
					
					if (checkBfs(a, k, r, c))
					{
					
						bool res = check(a, k, r, c);
						if (res)
							return true;
					}
						
					for (auto p : dm)
					{
						int x = p.fst + i;
						int y = p.snd + j;
						a[x][y] = 0;
					}
				}
				
			}
			
			break;
		}
	}
	
	return !any;
}

map < pair < int, int >, int > mem[7];

int solve(int r, int c, int k)
{
	if (r > c)
		swap(r, c);
		
	if (mem[k].find(mp(r, c)) != mem[k].end())
		return mem[k][mp(r, c)];
		
	bool ans = true;
	
	if ((r * c) % k)
		return false;
		
	for (auto kv : mem[k])
	{
		if (kv.fst.fst <= r && kv.fst.snd <= c && kv.snd)
		{
			return mem[k][mp(r, c)] = 1;
		}
	}
	
	//if (r >= minimalRects[k].fst && c >= minimalRects[k].snd)
	//	return true;
	
	auto valid = [&](int x, int y)
	{
		return 0 <= x && x < r && 0 <= y && y < c;
	};
	
	for (auto dm : xminoes[k])
	{
		bool canFill = false;
		ub = 1;
		while (true)
		{
			ub *= 2;
	
			bool anyIter = false;
			for (int iter = 0; iter < 2 && !canFill; iter++)
			{
				for (int i = 0; i < r && !canFill; i++)
				{
					for (int j = 0; j < c && !canFill; j++)
					{
						bool can = true;
						vector < vector < int > > a(r, vector < int > (c, 0));
						
						for (auto p : dm)
						{
							int x = p.fst + i;
							int y = p.snd + j;
							
							if (!valid(x, y))
							{
								can = false;
								break;
							}
							
							a[x][y] = 1;
						}
						
						if (!can)
							continue;
						
						iterCnt = 0;
						bool res = check(a, k, r, c);
						
						anyIter |= iterCnt > ub;
						
						if (res)
						{
							canFill = true;
							break;
						}							
					}
				}
				
				for (auto &p : dm)
				{
					swap(p.fst, p.snd);
					p.fst = -p.fst;
				}
			}
			
			if (canFill)
			{
				break;
			}
			
			if (anyIter)
				continue;
				
			if (!canFill)
			{
				ans = false;
				break;
			}
		}
		
		if (!ans)
			break;
	}
	
	return mem[k][mp(r, c)] = ans;
}

int main()
{
	//srand(time(NULL));
	//gen();
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	was.insert(mp(0, 0));
	for (int i = 1; i <= 6; i++)
	{
		rec(1, i);
	}
	
	
	for (int k = 1; k <= 6; k++)
	{
		for (int r = 1; r <= 20; r++)
		{
			for (int c = 1; c <= 20; c++)
			{
					//cerr << r << " " << c << " " << k << endl;
					int res = solve(r, c, k);
					cerr << res << ", ";
					//cout << res << ", ";
			}
			cerr << endl;
			//cout << endl;
		}
		cerr << endl;
		//cout << endl;
	}
	
	int t;
	scanf("%d\n", &t);
	
	for (int tt = 1; tt <= t; tt++)
	{
		int k, r, c;
		scanf("%d %d %d", &k, &r, &c);
		
		bool ans = true;
		
		if (k >= 7)
			ans = false;
			
		if (k <= 6)
		{
			ans = solve(r, c, k);
		}
		
		printf("Case #%d: %s\n", tt, ans ? "GABRIEL" : "RICHARD");		
	}

	
	return 0;
}






































