#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x, 0, sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define sqr(x) (x)*(x)
#define X first
#define Y second
#define y1 Y1
#define y2 Y2
const long double pi=acos(-1.0);
const long double eps = 1e-9;

int tests;

struct attack
{
	int day;
	int s;
	int w, e;
	attack() {}
	attack(int day_, int s_, int w_, int e_)
	{
		day = day_;
		s = s_;
		w = w_;
		e = e_;
	}
	bool operator < (const attack& arg) const 
	{
		return day < arg.day;
	}
};

int hh[10000000];
int* h;
vector<attack> attacks;
int N, n;
int w, e, s, d, delta_d, delta_p, delta_s;

bool suc(attack a)
{
	FOR(i, a.w, a.e - 1) if (h[i] < a.s) return true;
	return false;
}

void upd(attack a)
{
	FOR(i, a.w, a.e - 1) h[i] = max(h[i], a.s);
}

int main()
{
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	cin >> tests;
	FOR(T, 1, tests)
	{
		CLEAR(hh);
		h = hh + 5000000;
		attacks.clear();
		cin >> N;
		REP(ii, N)
		{
			cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
			REP(i, n)
			{
				attack a(d, s, w, e);
				attacks.push_back(a);

				d += delta_d;
				e += delta_p;
				w += delta_p;
				s += delta_s;
			}
		}

		sort(ALL(attacks));
		int ld = -1;
		int p1 = 0, p2 = -1;
		ll ans = 0;
		while(p1 < attacks.size())
		{
			while (p2 + 1 < attacks.size() && attacks[p2 + 1].day == attacks[p1].day) ++p2;
			FOR(i, p1, p2)
				if (suc(attacks[i])) ++ans;
			FOR(i, p1, p2)
				upd(attacks[i]);

			p1 = p2 + 1;
		}

		printf("Case #%d: ", T);
		cout << ans << endl;
	}
}
