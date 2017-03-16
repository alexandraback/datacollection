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

int n;

inline bool read()
{
	if (scanf ("%d", &n) != 1)
		return false;

	return true;
}

const int N = 10 * 1000 * 1000 + 13;
int d[N];
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
}

inline void solve(int test)
{
	printf ("Case #%d: ", test + 1);

	printf ("%d\n", d[n]);
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

	prepare();

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
