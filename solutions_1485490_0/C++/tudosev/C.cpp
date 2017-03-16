#include<cstdio>
#include<map>
#define NMAX 105
#define ll long long
using namespace std;

struct entry
{
	int i, j;
	ll ni, nj;

	bool operator<(const entry& e) const
	{
		if(i != e.i)
			return i < e.i;
		if(j != e.j)
			return j < e.j;
		if(ni != e.ni)
			return ni < e.ni;
		return nj < e.nj;
	}
};

int T1[NMAX], T2[NMAX], n, m;
ll N1[NMAX], N2[NMAX];
map<entry, ll> M;

ll f(entry e)
{
	if(e.i == n || e.j == m)
		return 0;
	if(M.count(e))
		return M[e];

	if(T1[e.i] == T2[e.j])
		if(e.ni < e.nj)
		{
			entry e2;
			e2.i = e.i + 1;
			e2.ni = N1[e2.i];
			e2.j = e.j;
			e2.nj = e.nj - e.ni;
			M[e] = e.ni + f(e2);
			return M[e];
		}
		else
		{
			entry e2;
			e2.i = e.i;
			e2.ni = e.ni - e.nj;
			e2.j = e.j + 1;
			e2.nj = N2[e2.j];
			M[e] = e.nj + f(e2);
			return M[e];
		}

	entry e2;
	e2.i = e.i + 1;
	e2.ni = N1[e2.i];
	e2.j = e.j;
	e2.nj = e.nj;
	ll m1 = f(e2);

	e2.i = e.i;
	e2.ni = e.ni;
	e2.j = e.j + 1;
	e2.nj = N2[e2.j];
	ll m2 = f(e2);

	M[e] = max(m1, m2);
	return M[e];
}

void solve()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%lld%d", N1 + i, T1 + i);
	for(int i = 0; i < m; ++i)
		scanf("%lld%d", N2 + i, T2 + i);
	entry e;
	e.i = e.j = 0; e.ni = N1[0]; e.nj = N2[0];
	printf("%lld\n", f(e));
	M.clear();
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ", t);
		solve();
	}

	return 0;
}
