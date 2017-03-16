#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = (a); x <= (b); x++)
#define REP(x, n) for (int x = 0; x < (n); x++)
#define SIZE(x) int((x).size())

const int MAX = 18;
int N, t[MAX][2];
bool jest[2][MAX];
map<string, int> id[2];

int wrzuc_do_id(int q, const string& s)
{
	if (id[q].find(s) == id[q].end())
		id[q][s] = SIZE(id[q]);
	return id[q][s];
}

void wczytaj_dane()
{
	REP(i, 2)
		id[i].clear();
	cin >> N;
	REP(i, N)
		REP(j, 2)
		{
			string s;
			cin >> s;
			int k = wrzuc_do_id(j, s);
			t[i][j] = k;
		}
}

bool sprawdz(int m)
{
	REP(i, N)
		if (((m >> i) & 1) == 0)
			REP(q, 2)
				if (! jest[q][t[i][q]])
					return false;
	return true;
}

int rozwiaz()
{
	int wynik = 0;
	REP(m, 1 << N)
	{
		REP(q, 2)
			REP(j, MAX)
				jest[q][j] = false;
		
		int jedynki = 0;
		REP(i, N)
			if (((m >> i) & 1) == 1)
			{
				jedynki++;
				REP(q, 2)
					jest[q][t[i][q]] = true;
			}
		if (sprawdz(m))
			wynik = max(wynik, N - jedynki);
	}
	return wynik;
}

int zrob_test()
{
	wczytaj_dane();
	return rozwiaz();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	FOR(i, 1, T)
		cout << "Case #" << i << ": " << zrob_test() << '\n';
	return 0;
}
