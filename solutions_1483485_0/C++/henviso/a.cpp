#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long double real;

///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = a; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define MOD 100
#define INCMOD(a,b) a = (a+b)%MOD
#define DECMOD(a,b) a = (a+MOD-1)%mod
#define ROUNDINT(a) (int)((double)a + 0.5)
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)

char tab[256];
string s;

int main()
{
	int t, ca = 0;

	tab['a'] = 'y';
	tab['b'] = 'h';
	tab['c'] = 'e';
	tab['d'] = 's';
	tab['e'] = 'o';
	tab['f'] = 'c';
	tab['g'] = 'v';
	tab['h'] = 'x';
	tab['i'] = 'd';
	tab['j'] = 'u';
	tab['k'] = 'i';
	tab['l'] = 'g';
	tab['m'] = 'l';
	tab['n'] = 'b';
	tab['o'] = 'k';
	tab['p'] = 'r';
	tab['q'] = 'z';
	tab['r'] = 't';
	tab['s'] = 'n';
	tab['t'] = 'w';
	tab['u'] = 'j';
	tab['v'] = 'p';
	tab['w'] = 'f';
	tab['x'] = 'm';
	tab['y'] = 'a';
	tab['z'] = 'q';
	tab[' '] = ' ';
	
	scanf(" %d ", &t);

	while(t--){
		getline(cin, s);
		printf("Case #%d: ", ++ca);
		REP(i, s.length()) putchar(tab[s[i]]);
		putchar('\n');
	}
	
}
