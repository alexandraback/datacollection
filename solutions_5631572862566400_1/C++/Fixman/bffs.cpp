#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <cstring>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())
#define all(n) n.begin(), n.end()

vector <int> F;
vector <vector <int>> H;
vector <int> C;

int Q(int n, int j)
{
	int t = 0;
	for (auto& h : H[n])
	{
		if (h != j)
			t = max(t, Q(h, j) + 1);
	}
	
	return t;
}

int V(int n)
{
	if (C[F[n]] != -1)
		return C[n] - C[F[n]];
	
	C[F[n]] = C[n] + 1;
	return V(F[n]);
}

int main()
{
	int t; cin >> t;

	forsn(z, 1, t + 1)
	{
		int n; cin >> n;
		F = vector <int> (n);
		H = vector <vector <int>> (n);

		fore(i, F)
		{
			cin >> F[i]; F[i] -= 1;
			H[F[i]].push_back(i);
		}

		int r = 0;
		int y = 0;
		forn(i, n)
		{
			if (F[F[i]] == i)
				y += Q(i, F[i]) + Q(F[i], i) + 2;
			else
			{
				C = vector <int> (n, -1);
				C[i] = 0;

				r = max(r, V(i) + 1);
			}
		}

		printf("Case #%d: %d\n", z, max(r, y / 2));
	}

	return 0;
}
