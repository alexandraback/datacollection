#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 10000+7;
int L;
ll X;
char in[MAX];
int vals[MAX], prefix[MAX], suffix[MAX];

const int ONE = 1, I = 2, J = 3, K = 4;
int _mul[4][4] = {
	{ONE, I, J, K},
	{I, -ONE, K, -J},
	{J, -K, -ONE, I},
	{K, J, -I, -ONE}};
inline int sgn(int n) { return n>0 ? 1 : -1; }
inline  int mul(int a, int b) { return sgn(a) * sgn(b) * _mul[abs(a)-1][abs(b)-1]; }

int c2v(char c) 
{
	if (c == 'i') return I;
	if (c == 'j') return J;
	if (c == 'k') return K;
}

void Solve(int tc)
{
	scanf("%d%lld%s", &L, &X, in);
	REP(i, L) vals[i] = c2v(in[i]);
	REP(i, L) {
		prefix[i] = mul((i?prefix[i-1]:1), vals[i]);
		suffix[L-1-i] = mul(vals[L-1-i], (i?suffix[L-i]:1));
	}
	int total = prefix[L-1], cycle = 0, tmp = 1;
	do {
		++cycle;
		tmp = mul(tmp, total);
	} while (tmp != 1);

	printf("Case #%d: ", tc);
	for (int i = 0; i < L; ++i) {
		int left = prefix[i], need_left = 0;
		for (; left != I && need_left < 10; ++need_left)
			left = mul(total, left);
		if (left != I) continue;

		int mid_left = 1, mid_right = 1;
		for (int j = 1; j <= L+1; ++j) {
			if (i+j < L) mid_left = mul(mid_left, vals[i+j]);
			else mid_right = mul(mid_right, vals[(i+j)%L]);
			int mid_mid = 1, need_mid = 0;
			for (; i+j >= L && mul(mid_left, mul(mid_mid, mid_right)) != J && need_mid < 10; ++need_mid)
				mid_mid = mul(mid_mid, total);
			if (mul(mid_left, mul(mid_mid, mid_right)) != J) continue;

			int right = suffix[(i+j+1)%L], need_right = 0;
			for (; right != K && need_right < 10; ++need_right)
				right = mul(right, total);
			if (right != K) continue;

			int used = need_left + need_mid + need_right;
			if (i+j < L-1) used += 1;
			else if (i+j < 2*L-1) used += 2;
			else used += 3;
			if (used <= X && (X-used) % cycle == 0) {
				printf("YES\n");
				return;
			}
		}
	}
	printf("NO\n");
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}