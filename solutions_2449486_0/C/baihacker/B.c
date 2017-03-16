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

int mat[105][105];

int main()
{
	int cas = Rint();
	while (cas--)
	{
		int n = Rint(), m = Rint();
		rep(i, 0, n) rep(j, 0, m) mat[i][j] = Rint();
		vector<int> pos[101];
		rep(i, 0, n) rep(j, 0, m)
		pos[mat[i][j]].push_back(i<<10|j);
		int ok = 1;
		for (int i = 1; i <= 100; ++i)
		{
			const int size = sz(pos[i]);
			for (int j = 0; j < size; ++j)
			{
				int v = pos[i][j];
				int x = v >> 10, y = v & 1023;
				int r = 1, c = 1;
				int value = mat[x][y];
				for (int k = 0; k < m; ++k)
				r = r && mat[x][k] <= value;
				for (int k = 0; k < n; ++k)
				c = c && mat[k][y] <= value;
				if (r == 0 && c == 0) {ok = 0; goto failed;}
			}
		}
		failed:
		static int id = 1;
		printf("Case #%d: ", id++);
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
