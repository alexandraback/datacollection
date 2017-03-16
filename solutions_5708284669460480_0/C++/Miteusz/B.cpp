#include <bits/stdc++.h>
using namespace std;

typedef long double LD;
#define FOR(x, a, b) for (int x = (a); x <= (b); x++)
#define REP(x, n) for (int x = 0; x < (n); x++)
#define POKAZ(x) cerr << #x << " = " << (x) << '\n'

int K, L, S, licz[26];
string malpa, cel;

void wczytaj_dane()
{
	cin >> K >> L >> S >> malpa >> cel;
}

void wypelnij_licz()
{
	fill(licz, licz + 26, 0);
	REP(i, K)
		licz[int(malpa[i]) - int('A')]++;
}

bool da_sie()
{
	REP(i, L)
		if (licz[int(cel[i]) - int('A')] == 0)
			return false;
	return true;
}

bool poprawne_przesuniecie(const string &s, int i)
{
	FOR(j, i, L - 1)
		if (s[j] != s[j - i])
			return false;
	return true;
}

int nakladka(const string &s)
{
	FOR(i, 1, L)
		if (poprawne_przesuniecie(s, i))
			return i;
	assert(false);
}

int maks_wystapien()
{
	int nakl = nakladka(cel), kon = L - 1, w = 1;
	while (kon + nakl < S)
	{
		kon += nakl;
		w++;
	}
	return w;
}

void wypelnij_p(LD p[])
{
	REP(i, 26)
		p[i] = LD(licz[i]) / LD(K);
}

LD pstwo()
{
	LD p[26];
	wypelnij_p(p);
	LD w = 1.0;
	REP(i, L)
		w *= p[int(cel[i]) - int('A')];
	return w;
}

LD oczekiwanie_wystapien()
{
	return (S - L + 1) * pstwo();
};

LD zrob_test()
{
	wczytaj_dane();
	wypelnij_licz();
	return (da_sie() ? LD(maks_wystapien()) - oczekiwanie_wystapien() : 0.0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.precision(25);
	int T;
	cin >> T;
	FOR(t, 1, T)
		cout << "Case #" << t << ": " << zrob_test() << '\n';
	return 0;
}
