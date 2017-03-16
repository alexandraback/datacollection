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

double A[1024];
double B[1024];

int main()
{
	int cnt = Rint();
	for (int id = 1; id <= cnt; ++id)
	{
		int n = Rint();
		rep(i, 0, n) scanf("%lf", A+i);
		rep(i, 0, n) scanf("%lf", B+i);
		sort(A, A+n);
		sort(B, B+n);
		int pa = 0, qa = n-1;
		int pb = 0, qb = n-1;
		int u = 0;
		rep(i, 0, n)
		{
			if (A[pa] > B[pb]) ++u, ++pa, ++pb;
			else ++pa, --qb;
		}
		int v = 0;
		pa = 0, qa = n-1;
		pb = 0, qb = n-1;
		rep(i, 0, n)
		{
			if (A[qa] > B[qb]) ++v, --qa, ++pb;
			else --qa, --qb;
		}
		printf("Case #%d: %d %d\n", id, u, v);
	}
	return 0;
}
