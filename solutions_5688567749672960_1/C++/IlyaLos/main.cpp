#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

li n;

inline bool read()
{
	if (!(cin >> n))
		return false;

	return true;
}

const int N = 10 * 1000 * 1000 + 13;
int d[N], p[N];
int q[N], head, tail;
int inQ[N];

inline void prepare()
{
	forn (i, N)
	{
		d[i] = INF;
		inQ[i] = 0;
	}
	head = tail = 0;

	d[0] = 0;
	q[tail++] = 0;

	while (head != tail)
	{
		int v = q[head++];
		if (head == N)
			head = 0;
		inQ[v] = 0;

		int dv = d[v];

		if (v + 1 < N)
		{
			if (d[v + 1] > dv + 1)
			{
				d[v + 1] = dv + 1;
				p[v + 1] = v;

				if (!inQ[v + 1])
				{
					q[tail++] = v + 1;
					if (tail == N)
						tail = 0;
					inQ[v + 1] = 1;
				}
			}
		}

		int nv = 0;
		int vv = v;
		while (vv)
		{
			int c = vv % 10;
			vv /= 10;

			if (c != 0 || nv != 0)
				nv = nv * 10 + c;
		}

		if (nv < N)
		{
			if (d[nv] > dv + 1)
			{
				d[nv] = dv + 1;
				p[nv] = v;

				if (!inQ[nv])
				{
					q[tail++] = nv;
					if (tail == N)
						tail = 0;
					inQ[nv] = 1;
				}
			}
		}
	}
//
//	for (int i = 1; i <= 1000 * 1000; i *= 10)
//		cerr << i << ' ' << d[i] << endl;
}

inline li calcAns (li n)
{
	if (n <= 10)
		return int(n);

	li ans = 10;
	li target = 100;
	li add1 = 9, add2 = 8;
	li dadd2 = 90;
	while (target <= n)
	{
		ans += add1 + add2 + 1 + 1;

		if (add2 < add1)
		{
			add2 += dadd2;
			dadd2 *= 10;
		}
		else
			add1 = add1 * 10 + 9;

		target *= 10;
	}

	return ans;
}

inline void solve(int test)
{
	printf ("Case #%d: ", test + 1);

	//li oldN = n;

	li nn = 1;
	int cnt = 1;
	while (nn * 10 <= n)
	{
		nn *= 10;
		cnt++;
	}

	li sAns = calcAns(nn);

	if (n == nn)
	{
		cout << sAns << endl;
		return;
	}

	li ans1 = n - nn;

	li ans2 = 0;
	if (n % 10 == 0)
	{
		ans2++;
		n--;
	}
	li ans3 = INF64;

	for (int i = 1; i < cnt; i++)
	{
		li l = 0, r = 0;
		li v = n;
		string ss;
		forn (j, i)
		{
			ss.pb(char(v % 10));
			//l = l * 10 + v % 10;
			v /= 10;
		}
		ford(i, sz(ss))
			l = l * 10 + ss[i];

		forn (j, cnt - i)
		{
			r = r * 10 + v % 10;
			v /= 10;
		}

		li cur = (l + r - 1) + 1;
		ans3 = min(ans3, cur);
	}

	ans2 += ans3;

	li ans = sAns + min(ans1, ans2);
	//cerr << oldN << ' ' << ans << ' ' << d[oldN] << endl;
	//assert(ans == d[oldN]);

	cout << ans << endl;
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

//	prepare();
//
//	for (int i = 1; i <= 10000000; i++)
//	{
//		n = i;
//		solve(n);
//	}
//
//	cerr << "OK" << endl;
//
//	return 0;

	int testCnt;
	assert(scanf ("%d", &testCnt) == 1);

	forn (test, testCnt)
	{
		assert(read());
		solve(test);
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
