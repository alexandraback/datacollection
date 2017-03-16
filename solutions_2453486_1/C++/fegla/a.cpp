/*
 TASK:
 LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <bitset>
#include <cstring>
#include <climits>
#include <deque>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#include <valarray>
//#include "vc.h"
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif

template<class key>
struct hashtemp {

	enum {
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;
#ifndef M_PI
const long double M_PI=acos((long double)-1);
#endif
#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO = 0;
const long double INF = 1 / ZERO, EPSILON = 1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
int di[] = { 1, 0, 1, -1 };
int dj[] = { 0, 1, 1, 1 };
char b[4][5];
bool check(int i, int j, int k, char c) {
	int cnt = 0;
	do {
		if (b[i][j] == c || b[i][j] == 'T')
			cnt++;
		i += di[k];
		j += dj[k];
	} while (i < 4 && i > -1 && j < 4 && j > -1);
	return cnt == 4;
}

int main() {
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("1.in", "rt", stdin);
	freopen("1.out", "wt", stdout);
#endif
	int T;
	cin >> T;
	rep(t,T)
	{

		printf("Case #%d: ", t + 1);
		rep(i,4)
			rep(j,4)
				cin >> ws >> b[i][j];
		char *str = "XO";
		bool draw=1;
		rep(i,4)
			rep(k,4)
			rep(l,2)
			{

				if(b[i][k]=='.')
					draw=0;
				if(check(i,0,k,str[l]) || check(0,i,k,str[l]))
				{
					printf("%c won",str[l]);
					goto next;
				}
			}
		if(draw)
			printf("Draw");
		else
			printf("Game has not completed");
		next:
		printf("\n");
	}
	return 0;
}
