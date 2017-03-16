#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
#define ALL(x) x.begin(), x.end()
#define LL long long
#define MP make_pair
#define PB push_back
#define CLR(a,b) memset(a, b, sizeof(a))
template<class T> inline T Sqr(const T &x) { return x*x; }
template<class T> inline T Abs(const T &x) { return x >= 0 ? x : -x; }
#define fo(i, n) for (int i = 0; i < (n); i++)
#define foz(i, a) for (int i = 0; i < (a).size(); i++)
#define ABS(x) ((x)<0 ? -(x) : (x))

void init()
{

}

#define maxn 7

int n;
int s[maxn], p[maxn];

LL gcd(LL a, LL b) 
	{ if (b) return gcd(b, a%b); return a; }

struct F {
	LL a, b;
	F(LL A = 0, LL B = 1) { 
		if (B<0) { B=-B; A=-A; }
		if (!B) { a = b = 0; return; }
		LL d = gcd(ABS(A), ABS(B));
		a = A/d; b = B/d;
	}
	friend F operator+ (const F &u, const F &v) { return F(u.a*v.b+u.b*v.a, u.b*v.b); }
	friend F operator- (const F &u, const F &v) { return F(u.a*v.b-u.b*v.a, u.b*v.b); }
	friend F operator* (const F &u, const F &v) { return F(u.a*v.a, u.b*v.b); }
	friend F operator/ (const F &u, const F &v) { return F(u.a*v.b, u.b*v.a); }
	friend bool operator< (const F &u, const F &v) { return u.a*v.b < u.b*v.a; }	
};

struct Ev
{
	F time;
	int type;
	int i, j;
	friend bool operator < (const Ev &a, const Ev &b) {
		return make_pair(a.time, a.type) < make_pair(b.time, b.type); }
	Ev(F time, int type, int i = 0, int j = 0) : time(time), type(type), i(i), j(j) {}
};

bool f[1<<6];

void solvecase()
{
	scanf("%d", &n);
	char buf[5];
	int s0 = 0;
	for (int i = 0; i < n; i++) 
	{
		scanf("%s%d%d", buf, &s[i], &p[i]);
		if (buf[0] == 'R') s0 |= 1 << i;
	}
	vector<Ev> e;
	e.push_back(Ev(0, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (s[i] != s[j])
			{
				F t1 = F(5 - (p[j] - p[i]), s[j] - s[i]);
				F t2 = F(-5 - (p[j] - p[i]), s[j] - s[i]);
				if (t2 < t1) swap(t2, t1);
				if (!(t1 < 0)) e.push_back(Ev(t1, 1, i, j));
				if (!(t2 < 0)) e.push_back(Ev(t2, 0));
			}
	sort(ALL(e));
	int N = 1 << n;
	CLR(f, 0);
	f[s0] = true;
	for (int i = 0; i < e.size(); i++)
	{
		if (e[i].type == 0)
		{
			bool free[maxn];
			for (int k = 0; k < n; k++)
			{
				free[k] = true;
				for (int j = 0; j < n; j++) if (j != k)
				{
					F x = (p[j] - p[k]) + (s[j] - s[k]) * e[i].time;
					if (x < 5 && -5 < x) free[k] = false;
				}
			}			
			queue<int> q;
			for (int j = 0; j < N; j++) if (f[j]) q.push(j);
			while (!q.empty())
			{
				int v = q.front(); q.pop();
				for (int j = 0; j < n; j++) if (free[j])
				{
					int u = v ^ (1<<j);
					if (!f[u])
					{
						q.push(u);
						f[u] = true;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < N; j++) if (((j >> e[i].i) & 1) == ((j >> e[i].j) & 1)) f[j] = false;
			bool good = false;
			for (int j = 0; j < N; j++) if (f[j]) good = true;
			if (!good)
			{
				printf("%.6lf", (double)e[i].time.a / e[i].time.b);
				return;
			}
		}
	}
	printf("Possible");
}

void solve() {
	init();
	int n_tests;
	scanf("%d", &n_tests);
	for (int i = 1; i <= n_tests; i++)
	{
		printf("Case #%d: ", i);
		solvecase();
		printf("\n");
	}
}

#define problem_letter "C"
//#define fname "test"
#define fname problem_letter "-small-attempt0"
//#define fname problem_letter "-small-attempt1"
//#define fname problem_letter "-small-attempt2"
//#define fname problem_letter "-large"

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	return 0;
}