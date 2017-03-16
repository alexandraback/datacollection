#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 10
#define MOD 1000000007

struct matrix
{
	int t[MR][MR], n;
	//przeladowany zwykly konstruktor
	matrix() {}
	//przeladowany konstruktor kopiujacy
	matrix(const matrix &macierz)
	{
		n = macierz.n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				t[i][j] = macierz.t[i][j];
	}
	matrix operator*(const matrix &B)const	//chyba nie bedziemy uzywac
	{	//+ zamienimy na ||, a * na &&
		matrix C;
		C.clear();	//zeruj macierz
		C.n = n;
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
				for (int j = 0; j < n; j++)
					C.t[i][j] = (C.t[i][j] + t[i][k] * (LL)B.t[k][j]) % MOD;	//+= nie zrobi nam z 1 0			
		return C;
	}
	matrix& operator*=(const matrix &B)
	{	//+ zamienimy na ||, a * na &&
		matrix C;
		C.clear();	//zeruj macierz
		C.n = n;
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
				for (int j = 0; j < n; j++)
					C.t[i][j] = (C.t[i][j] + t[i][k] * (LL)B.t[k][j]) % MOD;	//+= nie zrobi nam z 1 0		
		return *this = C;
	}
	void clear()
	{
		memset(t, 0, sizeof(t));
	}
	void pow(matrix &p, LL b)
	{	//wynik potegowania (*this)^b bedzie przekazany w referencji p
		matrix a = *this;
		p.clear();
		p.n = n;
		for (int i = 0; i < n; i++) p.t[i][i] = 1;
		while (b)
		{
			if (b & 1LL)
				p *= a;
			a *= a;
			b >>= 1LL;
		}
	}
}matr, pot;	//macierze dla drogi kazdego rodzaju

bool go(int N, int M)
{
	matr.n = N;
	int ile = N*N - N - N + 1;
	int end = 1 << ile;
	REP(mask, end)
	{
		bool ok = 0;
		REP(i, N - 1)
		{
			if (mask&(1 << i))
			{
				ok = 1;
				break;
			}
		}
		if (!ok) continue;
		ok = 0;
		int pom = N - 2;
		REP(i, N - 1)
		{
			if (mask&(1 << pom)) {
				ok = 1;
				break;
			}
			pom += N - 1;
		}
		if (!ok) continue;
		int cnt = 0;
		REP(i, N - 1)REP(j, N)
		{
			if (i == j) continue;
			if (mask&(1 << cnt)) matr.t[i][j] = 1; else matr.t[i][j] = 0;
			cnt++;
		}
		int ile = 0;
		FORQ(i, 1, 22)
		{
			matr.pow(pot, i);
			ile += pot.t[0][N - 1];
			if (ile > M) break;
		}
		if (ile == M) return 1;
	}

	return 0;
}

LL tab[100]{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,38,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,8,138,654,2254,0,0,450,330,0,708,26,714,0,2498,458,0,0,0,0,0,16,530,2582,17046,35588,35092,1666,1170,0,2692,50,2706,82710,18050,1682,83608,51988,0,0,68236,32,2082,10278,133414,272900,270884,6402,4386,17337380,10500,98,10530,657958,137474,6434,661800,404004,21105190,34671628,534796 };

int main()
{
	/*freopen("test.out", "w", stdout);
	FORQ(N, 2, 6)FORQ(M, 1, 20)
	{
		if (go(N, M))
		{
			LL res = 0;
			REP(i, N)REP(j, N)
				if (matr.t[i][j])
					res += 1LL << (i*N + j);
			printf("%lld,", res);
		}
		else printf("0,");
	}*/
	int T;
	scanf("%d", &T);
	REP(c, T)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		printf("Case #%d: ", c + 1);
		int ind = -1, cnt = 0;
		FORQ(i, 2, 6)FORQ(j, 1, 20)
		{
			if (i == N && j == M) ind = cnt;
			cnt++;
		}
		LL res = tab[ind];
		if (!res) printf("IMPOSSIBLE\n");
		else
		{
			printf("POSSIBLE\n");
			REP(i, N)
			{
				REP(j, N) if (res & (1LL << (i*N + j))) printf("1"); else printf("0");
				printf("\n");
			}
		}
	}
	return 0;
}