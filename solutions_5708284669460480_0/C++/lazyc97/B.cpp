#include <bits/stdc++.h>
using namespace std;
#define llong long long
#define long llong

string A, B;
double F[110][110];
int K[110], C[110][110];
int n, m, p, n_test;

int cal1 (int x,int y)
{
	if (x == n) return 0;
	if (C[x][y] > -1) return C[x][y];

	for (int i = 0; i < p; ++i)
	{
		int j = y;
		while (j && B[j + 1] != A[i]) j = K[j];
		if (B[j + 1] == A[i]) ++j;

		C[x][y] = max(C[x][y], cal1(x + 1, j) + (j == m));
	}

	return C[x][y];
}

double cal2 (int x,int y)
{
	if (x == n) return 0;
	if (F[x][y] > -0.5) return F[x][y];

	double s = 0;
	for (int i = 0; i < p; ++i)
	{
		int j = y;
		while (j && B[j + 1] != A[i]) j = K[j];
		if (B[j + 1] == A[i]) ++j;

		s += cal2(x + 1, j) + (j == m);
	}

	return F[x][y] = s / p;
}

void enter ()
{
	cin >> p >> m >> n >> A >> B;

	B = " " + B + " ";
	for (int i = 2; i <= m; ++i)
	{
		for (K[i] = K[i - 1]; K[i] && B[K[i] + 1] != B[i]; K[i] = K[K[i]]);
		if (B[K[i] + 1] == B[i]) ++K[i];
	}
}

void solve ()
{
	fill(C[0], C[n], -1);
	fill(F[0], F[n], -1);

	cout << fixed << cal1(0, 0) - cal2(0, 0) << "\n";
}

int main ()
{
    cin.rdbuf((new ifstream("B.inp"))->rdbuf());
    cout.rdbuf((new ofstream("B.out"))->rdbuf());

    cin >> n_test;
    for (int i = 1; i <= n_test; ++i)
    {
    	cout << "Case #" << i << ": ";
    	enter ();
		solve ();
    }
}