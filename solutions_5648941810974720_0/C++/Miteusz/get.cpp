#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = (a); x <= (b); x++)
#define REP(x, n) for (int x = 0; x < (n); x++)
#define SIZE(x) int((x).size())

const string T[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const int K = 30;
int licz[K], cyfra[10];

void wczytaj_dane()
{
	fill(licz, licz + K, 0);
	string S;
	cin >> S;
	REP(i, SIZE(S))
		licz[int(S[i]) - int('A')]++;
}

void f(char z, int c)
{
	int ile = licz[int(z) - int('A')];
	cyfra[c] = ile;
	REP(i, SIZE(T[c]))
		licz[int(T[c][i]) - int('A')] -= ile;
}

void zlicz_cyfry()
{
	fill(cyfra, cyfra + 10, 0);
	f('Z', 0);
	f('W', 2);
	f('U', 4);
	f('X', 6);
	f('G', 8);
	f('O', 1);
	f('R', 3);
	f('F', 5);
	f('S', 7);
	f('I', 9);
	
	REP(i, K)
		assert(licz[i] == 0);
}

string wynik()
{
	string w;
	REP(i, 10)
		while (cyfra[i]--)
			w += char(int('0') + i);
	return w;
}

string zrob_test()
{
	wczytaj_dane();
	zlicz_cyfry();
	return wynik();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testy;
	cin >> testy;
	FOR(tt, 1, testy)
		cout << "Case #" << tt << ": " << zrob_test() << '\n';
	return 0;
}
