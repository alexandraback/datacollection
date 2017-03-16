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
/*
x x-1 x-1
x x-1 x-2
x x-2 x-2
s >= 3x-2 => ok cost = 0
s >= 3x-4 && s <= 3x-3 => surprise
s < 3x-4 => never
*/
int must_ok[31];
int can_not[31];
int ok_with_s[31];
int main()
{
	int cas = Rint();
	while (cas--)
	{
		int ans = 0;
		int n = Rint(), s = Rint(), p = Rint();
		vi data(n);
		rep(i, 0, n) data[i] = Rint();
		sort(all(data));
		memset(must_ok, 0, sizeof must_ok);
		memset(can_not, 0, sizeof can_not);
		memset(ok_with_s, 0, sizeof ok_with_s);
		
		for (int dest = 0; dest <= 30; ++ dest)
		{
			int low = 100, hi = -1;
			rep(i, 0, 11) rep(j, 0, 11) rep(k, 0, 11)
			if (i + j + k == dest)
			{
				if (abs(i-j)>2||abs(i-k)>2||abs(j-k)>2) continue;
				cmin(low, i),cmin(low, j),cmin(low, k);
				cmax(hi, i),cmax(hi, j),cmax(hi, k);
			}
			if (low >= p) must_ok[dest] = 1;
			if (hi < p) can_not[dest] = 1;
			if (must_ok[dest] + can_not[dest] == 0)
			{
				int need = true;
				rep(i, 0, 11) rep(j, 0, 11) rep(k, 0, 11)
				if (i + j + k == dest)
				{
					if (abs(i-j)>=2||abs(i-k)>=2||abs(j-k)>=2) continue;
					if (i >= p || j >= p || k >= p) need = false;
				}
				ok_with_s[dest] = need;
			}
		}
		int can_s = 0;
		int may = 0;
		foreach(it, data)
		{
			int t = *it;
			if (t >= 2 && t <= 28 && (must_ok[t] + can_not[t] == 1 ||
			must_ok[t] + can_not[t] + ok_with_s[t] == 0)) ++can_s;
			if (must_ok[t] || must_ok[t] + can_not[t] + ok_with_s[t] == 0) ++ans;
			if (ok_with_s[t]) ++may;
		}
		int inc = 0;
		for (int i = 0; i <= may; ++i)
		if (s - i >= 0 && can_s >= s - i)
		{
			cmax(inc, i);
		}
		static int id = 1;
		printf("Case #%d: %d\n", id++, ans+inc);
	}
	return 0;
}
