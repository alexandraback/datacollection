#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define FOR(x, a, b) for (LL x = (a); x <= (b); x++)
#define FORD(x, a, b) for (LL x = (a); x >= (b); x--)
#define REP(x, n) for (LL x = 0; x < (n); x++)
#define SIZE(x) LL((x).size())

LL modul(LL a)
{
	return a < 0 ? -a : a;
}

struct W
{
	LL c, j, nast, r;
	
	W() {};
	W(LL cc, LL jj, LL na, LL i);
	
	bool operator < (const W& dane) const
	{
		if (modul(r) != modul(dane.r))
			return modul(r) < modul(dane.r);
		else if (c != dane.c)
			return c < dane.c;
		return j < dane.j;
	}
	
	/*friend ostream& operator << (ostream& wyjscie, W& dane)
	{
		wyjscie << '(' << dane.c << ", " << dane.j << ", " << dane.nast << ", " << dane.r << ')';
		return wyjscie;
	}*/
};

const LL MAX = 23;
LL n, pot;
W t[MAX][3];
string s[2];

W::W(LL cc, LL jj, LL na, LL i) : c(cc), j(jj), nast(na), r((cc - jj) * pot + t[i + 1][na].r) {}

void wczytaj_dane()
{
	REP(i, 2)
		cin >> s[i];
	n = SIZE(s[0]);
}

void wypelnij_t()
{
	REP(j, 3)
	{
		t[n][j] = W(0, 0, 0, 0);
		t[n][j].r = 0;
	}
	pot = 1;
	FORD(i, n - 1, 0)
	{
		LL C = LL(s[0][i]) - LL('0'), J = LL(s[1][i]) - LL('0'); 
		if (s[0][i] == '?' && s[1][i] == '?')
		{
			t[i][0] = W(9, 0, 0, i);
			t[i][2] = W(0, 9, 2, i);
			t[i][1] = min(W(0, 0, 1, i), min(W(0, 1, 0, i), W(1, 0, 2, i)));
		}
		else if (s[0][i] != '?' && s[1][i] != '?')
		{
			t[i][0] = W(C, J, 0, i);
			t[i][2] = W(C, J, 2, i);
			t[i][1] = W(C, J, (C < J ? 0 : (C == J ? 1 : 2)), i);
		}
		else if (s[0][i] == '?')
		{
			t[i][0] = W(9, J, 0, i);
			t[i][2] = W(0, J, 2, i);
			t[i][1] = W(J, J, 1, i);
			if (J > 0)
				t[i][1] = min(t[i][1], W(J - 1, J, 0, i));
			if (J < 9)
				t[i][1] = min(t[i][1], W(J + 1, J, 2, i));
		}
		else
		{
			t[i][0] = W(C, 0, 0, i);
			t[i][2] = W(C, 9, 2, i);
			t[i][1] = W(C, C, 1, i);
			if (C > 0)
				t[i][1] = min(t[i][1], W(C, C - 1, 2, i));
			if (C < 9)
				t[i][1] = min(t[i][1], W(C, C + 1, 0, i));
		}
		pot *= 10;
		
		/*REP(j, 3)
			cerr << t[i][j] << ' ';
		cerr << '\n';*/
	}
	//cerr << '\n';
}

void wypisz_wynik()
{
	string C(n, '0'), J(n, '0');
	LL j = 1;
	REP(i, n)
	{
		C[i] = char(LL('0') + t[i][j].c);
		J[i] = char(LL('0') + t[i][j].j);
		j = t[i][j].nast;
	}
	cout << C << ' ' << J << ' ' << '\n';
}

void zrob_test()
{
	wczytaj_dane();
	wypelnij_t();
	wypisz_wynik();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	LL T;
	cin >> T;
	FOR(i, 1, T)
	{
		cout << "Case #" << i << ": ";
		zrob_test();
	}
	return 0;
}
