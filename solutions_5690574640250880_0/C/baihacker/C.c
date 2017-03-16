#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
const int inf = 2000000000;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
template<typename T> static inline void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> static inline void cmin(T& a, const T& b){if(b<a)a=b;}

char mat[64][64];

int adj[64][64];
bool check(int r, int c, int m)
{
	if (m == r*c-1) return 1;
	if (m == 0) return 1;
	
	rep(i, 0, r) rep(j, 0, c)
	{
		int cnt = 0;
		for (int a = -1; a <= 1; ++a)
		for (int b = -1; b <= 1; ++b)
		{
			int x = i + a, y = j + b;
			if (x < 0 || y < 0 || x >= r || y >= c) continue;
			cnt += mat[x][y] == '*';
		}
		adj[i][j] = cnt;
	}
	rep(i, 0, r) rep(j, 0, c)
	if (mat[i][j] != '*')
	{
		if (adj[i][j] == 0) continue;
		
		int cnt = 0;
		for (int a = -1; a <= 1; ++a)
		for (int b = -1; b <= 1; ++b)
		{
			int x = i + a, y = j + b;
			if (x < 0 || y < 0 || x >= r || y >= c) continue;
			if (x == i && y == j) continue;
			cnt += adj[x][y] == 0;
		}
		if (cnt == 0) return 0;
	}
	return 1;
}

int solve(int r, int c, int m, int flag)
{
	rep(i, 0, r) mat[i][c] = 0;
	
	int ok = 0;

	for (int each = 1; each <= c; ++each)
	for (int used = 0; used < r; ++used)
	{
		const int remain = m - used * each;
		if (used * each > m) continue;
		if (remain >= (r - used) * c) continue;

		for (int i = 0; i < used; ++i)
		for (int j = 0; j < c; ++j)
		if (j < each) mat[i][j] = '*'; else mat[i][j] = '.';
		
		for (int j = 0, have = remain; j < c; ++j)
		for (int i = used; i < r; ++i)
		if (have > 0) mat[i][j] = '*', --have;
		else mat[i][j] = '.';
		
		mat[r-1][c-1] = 'c';
		if (check(r, c, m)) {ok = 1; goto done;}
	}
done:
	if (ok)
	{
		if (flag == 0)
		{
			for (int i = 0; i < r; ++i)
			puts(mat[i]);
		}
		else
		{
			for (int i = 0; i < c; puts(""), ++i)
			for (int j = 0; j < r; ++j)
			putchar(mat[j][i]);
		}
	}
	return ok;
}
int main()
{
	int cnt = Rint();
	for (int id = 1; id <= cnt; ++id)
	{
		int r = Rint(), c = Rint(), m = Rint();
		
		printf("Case #%d:\n", id);
		
		if (solve(r, c, m, 0)) continue;
		if (solve(c, r, m, 1)) continue;
		puts("Impossible"); continue;
	}
	return 0;
}
