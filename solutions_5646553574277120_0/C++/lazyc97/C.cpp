#include <bits/stdc++.h>
using namespace std;
#define llong long long
#define long llong

bool M[40], F[40];
int A[20];
int n, m, n_test;

bool full (int p)
{
	fill_n(F + 1, m, false);
	F[0] = true;

	for (int i = 1; i <= p; ++i)
	for (int j = m - A[i]; j >= 0; --j)
	if (F[j]) F[j + A[i]] = true;

	return find(F, F + m + 1, false) == F + m + 1;
}

bool check (int x,int y,int p)
{
	if (x > p) return full(n + p);

	for (int i = y + 1; i <= m; ++i)
	if (!M[i])
	{
		M[i] = true;
		A[x + n] = i;
		bool k = check(x + 1, i, p);
		M[i] = false;

		if (k) return true;
	}

	return false;
}

void enter ()
{
	cin >> n >> n >> m;
	fill_n(M + 1, m, false);
	for (int i = 1; i <= n; ++i) cin >> A[i], M[A[i]] = true;
}

void solve ()
{
	for (int i = 0; i < 5; ++i)
	if (check(1, 0, i))
	{
		cout << i << "\n";
		return;
	}

	cout << "5\n";
}

int main ()
{
    cin.rdbuf((new ifstream("C.inp"))->rdbuf());
    cout.rdbuf((new ofstream("C.out"))->rdbuf());

	cin >> n_test;
    for (int i = 1; i <= n_test; ++i)
    {
    	cout << "Case #" << i << ": ";
    	enter ();
		solve ();
    }
}